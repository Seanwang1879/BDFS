#include<stdio.h>

#define  max_size  10
//邻接举证

typedef struct{
	char vertec[max_size];
	char arcs[max_size][max_size];
}graph;

typedef struct node{
	int vercte;
	struct node *next;
}*NODE;

typedef struct{
	NODE front, rear;
}queue;

/*
//顺序队列(循环队列)
typedef struct{
	int data;
	int front;
	int rear;
}queue;

//顺序栈
typedef struct{
	int data;
	int top;
}stack;

//链栈
typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct{
	NODE *top;
}stack;
*/

void QueueInit(queue *Q)
{
	NODE node = (NODE)malloc(sizeof(*NODE));
	if(!node){
		return ;
	}
	Q->front = Q->rear = node;
	
	return ;
}
//empty：1    not empty: 0
int QueueEmpty(queue *Q)
{
	if(Q->front == Q->rear){
		return 1;
	}

	return 0;
}

char QueuePop(queue *Q)
{
	if(QueueEmpty(Q)){
		return ;
	}
	
	NODE node;
	int data;

	printf("%c\n", Q->front->vertec);
	node = Q->front;
	Q->front = Q->front->next;
	data = node->vertec;

	free(node);

	return data;
}

void QueuePush(queue *Q, char data)
{
	NODE node = (NODE)malloc(sizeof(*NODE));
	
	node->vertec = data;
	node->next = NULL;

	Q->rear->next = node;
	Q->reat = Q->rear->next;

	return ;
}

void GraphCreat(graph *G, int *visit)
{
	int i,j,k;
	
	printf("please enter vertec\n");
	for(i=0; i<max_size; i++){
		visit[i] = 0;
		scanf("%c", &G->vertec[i]);
	}
	
	please("please enter arcs\n");
	for(i=0; i<max_size; i++){
		for(j=i+1; j<max_size; j++){  //无向图
			scanf("%c", &G->arcs[i][j]);
			G->arcs[j][i] = G->arcs[i][j];
		}
	}
	
	return ;
}

void GraphInit(graph *G, int *visit){
	int i;
	
	memcpy(visit, 0, max_size);
	
	return ;
}

void DFS(graph *G, int nums, int start, int *visit)
{
	if(G==NULL || visit==NULL || nums<0){
		return ;
	}
	
	int i;

	printf("%d\n", start);
	visit[start] = 1;	
	
	for(i=0; i<nums; i++){
		if(G->arcs[start][i]!=0 && visit[i]==0){
			DFS(G, nums, i, visit);
		}
	}
	
	for(i=0; i<max_size; i++){  //如果是非连通图
		visit[i] = 1;
	}

	return ;
}

void BFS(graph *G, int nums ,int start, int *visit)
{
	if(G==NULL || nums<0 || visit==NULL`){
		return ;
	}
	
	int i;
	queue *Q;
	int temp;

	prinf("%d\n", Q->vertec[start]);
	QueueInit(Q);
	QueuePush(Q, start);

	while(!QueueEmpty(Q)){
		temp = QueuePop(Q);

		for(i=0; i<max_size; i++){
			if(G->arcs[temp][i]!=0 && visit[i]==0){
				visit[i] = 1;
				printf("%c\n", G->vertec[i]);
				QueuePush(Q, i);
			}
		}
	}
	
	return ;
}

void main()
{
	graph G;
	int visit[max_size];
	int start;

	GraphCreat(&G);
	
	printf("please enter start node\n");
	scanf("%d", &start);
	DFS(G, max_size, start, visit);

	GraphInit(&G, visit);
	BFS(G, max_size, start, visit);

	return ;
}
