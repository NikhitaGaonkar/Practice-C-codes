#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"stack.c"

/*
	Undireced grap representation - Adjacency List

    0----1
    |   /|  \
    |  / |   2
    | /  |  /
    4----3

    0 ->1->4
    1->0->4->2->3
    2->1->3
    3->4->2->1
    4->3->0->1
*/

#define UN_DIRECTED 1 

typedef struct adj_list_node
{
	int dest; //adjacent node
	struct adj_list_node *next;
}adj_list_node;

typedef struct adj_list
{
	adj_list_node *head;  //pointer to the head of each list
}adj_list;

typedef struct Graph
{
 	int V; //total no of vertices
 	int E; //total no of edges
	adj_list *array; //array of lists or bags
}Graph;

/* Create Graph of V vertices*/
Graph *create_graph(int V)
{
	Graph *g = (Graph*)malloc(sizeof(Graph));
	if(g == NULL)
	{
		printf("Failed to allocate memory to the graph");
		return;
	}
	g->V = V;
	g->E = 0;
	g->array = calloc(V, sizeof(adj_list));
	return g;
}

/* Function to create a new node in the list (bag)*/
adj_list_node *new_adj_list_node(int dest)
{
	adj_list_node *n = (adj_list_node*)malloc(sizeof(adj_list_node));
	n->dest = dest;
	n->next= NULL;
	return n;
}

/* Add an edge to te undirected graph*/
void add_edge(Graph *g, int src, int dest)
{
	/*
	   Adding an edge from src to dest. 
	  Create a new node for destination vertex
	  add it at the begining of the list, order not important
	  A new node is added to the adjacency list of src
	*/
	adj_list_node *new_node = new_adj_list_node(dest);
	new_node->next = g->array[src].head;
	g->array[src].head = new_node;

#if UN_DIRECTED	
	//Undirected grap, so add an edge from dest to src
	new_node = new_adj_list_node(src);
	new_node->next = g->array[dest].head;
	g->array[dest].head = new_node;
#endif	
	g->E++; //account for the edge
}

adj_list_node *adj_vertices_list(Graph *g, int src)
{
	if(g != NULL)
	  return g->array[src].head;
	
	return NULL;
}

void print_graph(Graph *g)
{
	int v;
	for(v = 0; v < g->V; v++)
	{
		adj_list_node *ptr = g->array[v].head;
		printf("Vertices adjacent to %d", v);
		while(ptr)
		{
			printf("-> %d", ptr->dest);
			ptr = ptr->next;
		}
		printf("\n");		
	}
}

typedef struct search_info{
	
	int *edgeTo;
	bool *visited;
}search_info;

void dfs(Graph *g, search_info *s, int v)
{
	if(s== NULL)
	  return;
	s->visited[v]= true;
	adj_list_node *adj_node = g->array[v].head;
	while(adj_node != NULL)
	{
		int adj_V = adj_node->dest;
		if(s->visited[adj_V] == false)
		{
			dfs(g,s,adj_V);
			s->edgeTo[adj_V] = v; 
		}
		adj_node = adj_node->next;
	}
}

void print_path(Stack *S)
{
	while(S->size != 0)
	{
	  printf("%d ->", top(S));
	  pop(S);
	}
}

bool hasPathTo(search_info *s, int V)
{
	return s->visited[V];
}

int w = 3;

void pathTo(search_info *s, Graph *g, int v)
{
	if(s->visited[v] == false)
	  printf("No node \n");
	Stack *S = createStack(10);
	int x;
	for(x=v; x!= w; x= s->edgeTo[x])
	  printf("%d \n", x);
	  //push(S,x);
	push(S,w);
	
	//print_path(S);
}

//find path from v to w
void DepthFirstPaths(Graph *g, int V, int v)
{
	search_info *s = malloc(sizeof(search_info));
	s->edgeTo = malloc(sizeof(int) * V);
	s->visited = malloc(sizeof(bool) * V);
	dfs(g, s, v);
	int i;
	for(i=0; i<V; i++)
      printf("%d ", s->edgeTo[i]);
	//pathTo(s, g, v);
}

int main(void)
{
	int V = 5;
	Graph *graph = create_graph(V);
	add_edge(graph, 0,1);
	add_edge(graph, 0,4);
	add_edge(graph, 1,4);
	add_edge(graph, 1,3);
	add_edge(graph, 1,2);
	add_edge(graph, 2,3);
	add_edge(graph, 3,4);
	
	print_graph(graph);
	printf("Total no of edges: %d", graph->E);
	printf("\n");
	printf("dfs \n");
	//find path from 0 to w ie 3
	DepthFirstPaths(graph, V, 0);
	
	return 0;
}



