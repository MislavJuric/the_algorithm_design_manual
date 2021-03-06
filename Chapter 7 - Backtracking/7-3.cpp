/*
	Design and implement an algorithm for testing whether two graphs are isomorphic
	to each other. The graph isomorphism problem is discussed in Section 16.9
	(page 550). With proper pruning, graphs on hundreds of vertices can be tested
	reliably.
*/

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <vector>

#define MAXCANDIDATES 10
#define GRAPHSIZE 10

//---------------------- Skienas Graph Data Structure ---------------------------------

#define MAXV 1000 /* maximum number of vertices */

// how do I extract the vertices from the graph structure?

typedef struct {
	int y; /* adjacency info */
	int weight; /* edge weight, if any */
	struct edgenode *next; /* next edge in list */
} edgenode;

typedef struct {
	edgenode *edges[MAXV + 1]; /* adjacency info */  
	int degree[MAXV + 1]; /* outdegree of each vertex */
	int nvertices; /* number of vertices in graph */
	int nedges; /* number of edges in graph */
	bool directed; /* is the graph directed? */
} graph;

void initialize_graph(graph *g, bool directed)
{
	int i; /* counter */
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	for (i = 1; i <= MAXV; i++) g->degree[i] = 0;
	for (i = 1; i <= MAXV; i++) g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
	int i; /* counter */
	int m; /* number of edges */
	int x, y; /* vertices in edge (x,y) */
	initialize_graph(g, directed);
	scanf("%d %d", &(g->nvertices), &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		insert_edge(g, x, y, directed);
	}
}

void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p; /* temporary pointer */
	p = (edgenode*) malloc(sizeof(edgenode)); /* allocate edgenode storage */
	p->weight = NULL;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x] = p; /* insert at head of list */
	g->degree[x] ++;
	if (directed == false)
		insert_edge(g, y, x, true);
	else
		g->nedges++;
}

void print_graph(graph *g)
{
	int i; /* counter */
	edgenode *p; /* temporary pointer */
	for (i = 1; i <= g->nvertices; i++) {
		printf("%d: ", i);
		p = g->edges[i];
		while (p != NULL) {
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
}

//---------------------- Skienas Graph Data Structure ---------------------------------

// char vertexLabels[5]{'A', 'B', 'C', 'D', 'E'};

bool is_a_solution(int a[], int k, graph* g)
{
	if (g->edges[0] == nullptr)
	{
		return false;
	}
	if (k  != (GRAPHSIZE - 1))
	{
		return false;
	}
	bool allMatch = true;
	int index = 0;
	edgenode* temp = g->edges[index];
	std::vector<int> nodeLabels;
	while (temp != nullptr)
	{
		bool alreadySeen = false;
		for (int i = 0; i < nodeLabels.size(); i++)
		{
			if (nodeLabels[i] == temp->y)
			{
				alreadySeen = true;
			}
		}
		if (!alreadySeen)
		{
			nodeLabels.push_back(temp->y);
		}
		temp = g->edges[index + 1];
		index++;
	}
	index = 0;
	temp = g->edges[index];
	while (temp != nullptr)
	{
		if (a[index] != nodeLabels[index]) // nije dobar test, jer edgevi mogu biti poredani kako hoće...
										   // ali to mi nije ni bitno, bitno je postoji li homomorfizam za to...
										   // rethinkati SP, rethinkati sve
		{
			allMatch = false;
			break;
		}
		temp = g->edges[index + 1];
		index++;
	}
	return allMatch;
}

void process_solution(int a[], int k, data input)
{
	// print_graph(g);
	for (int i = 0; i < k; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void backtrack(int a[], int k, data input) // the array a will contain the vertex mapping
{
	int c[MAXCANDIDATES]; /* candidates for next position */
	int ncandidates; /* next position candidate count */
	int i; /* counter */
	if (is_a_solution(a, k, input)) 
		process_solution(a, k, input); 
	else
	{
		k = k + 1;
		construct_candidates(a, k, input, c, &ncandidates); 

		for (i = 0; i<ncandidates; i++)
		{
			a[k] = c[i];
			// make_move(a, k, input); // not necessary
			backtrack(a, k, input);
			// unmake_move(a, k, input); // not necessary
			// won't need the below line
			/*
			if (finished) 
				return;
			*/
		}
	}
}


int main()
{

    return 0;
}

