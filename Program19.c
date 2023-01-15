//Program 19: Implement Graph traversals (BFS & DFS)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

struct Graph{
	int V;
	bool A[MAX][MAX];
	bool visited[MAX];
};

struct Graph* CreateGraph(int V)
{
	struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = V;
	int i,j;
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			g->A[i][j] = false;
		}
	}
	return g;
}

void DeleteGraph(struct Graph* g){ 
	free(g); 
}

void addEdge(struct Graph* g, int v, int w)
{
	g->A[v][w] = true;
}

void BFS(struct Graph* g, int s)
{
	int i;
	for (i = 0; i < g->V; i++) {
		g->visited[i] = false;
	}

	int queue[MAX];
	int front = 0, back = 0;
	
	g->visited[s] = true;
	queue[back++] = s;

	while (front != back) {
		s = queue[front++];
		printf("%d ", s);

		int adj;
		for (adj = 0; adj < g->V; adj++) {
			if (g->A[s][adj] && !g->visited[adj]) {
				g->visited[adj] = true;
				queue[back++] = adj;
			}
		}
	}
}


void DFS(struct Graph* g, int s)
{
	printf("%d ",s);
	g->visited[s] = true;

	int adj;
	for (adj = 0; adj < g->V; adj++) {
		if (g->A[s][adj] == true && !g->visited[adj]) {
			DFS(g,adj);
		}
	}
}

int main()
{
	struct Graph* g = CreateGraph(7);
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,1,0);
	addEdge(g,1,2);
	addEdge(g,2,0);
	addEdge(g,2,1);
	addEdge(g,2,3);
	addEdge(g,2,4);
	addEdge(g,3,0);
	addEdge(g,3,2);
	addEdge(g,3,4);
	addEdge(g,4,2);
	addEdge(g,4,3);
	addEdge(g,4,5);
	addEdge(g,4,6);
	addEdge(g,5,4);
	addEdge(g,6,4);

	int choice;
	
	do
	{
		printf ("\n-----------------------------------");
		printf ("\n          GRAPH TRAVERSALS         ");	
		printf ("\n-----------------------------------");		
		printf ("\nOPERATIONS:\n1. Breadth-First Search(BFS)\n2. Depth-First Search(DFS)\n3. Exit\n");
	
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			int start;
			printf("\nEnter the starting vertex: ");
			scanf("%d",&start);	
			printf("\nBreadth First Traversal: ");
			BFS(g,start);
			DeleteGraph(g);
			break;
		}
		
		else if(choice == 2){
			int start;
			printf("\nEnter the starting vertex: ");
			scanf("%d",&start);	
			printf("\nDepth First Traversal: ");
			DFS(g,start);
			break;
		}
		
		else if(choice == 3){
			exit(0);
		}
		
		else{
			printf("Invalid choice!");
		}
	}
	while (choice!=3);
	return 0;
}


