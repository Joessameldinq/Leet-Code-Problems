#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;

}Node;

typedef struct 
{
    Node *head;
}List;
typedef struct 
{
    int vertices;
    List *array;
}Graph;

Node *createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->array = (List*)malloc(sizeof(List) * vertices);

    for(int i = 0 ; i<vertices;i++)
        newGraph->array[i].head = NULL;

    return newGraph;
}

bool addEdge(Graph *graph,int src,int dest)
{
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

}

void DFSUtil( Graph* graph, int vertex, bool visited[]) {
        visited[vertex] = true;
        printf("%d ", vertex);

        struct Node* temp = graph->array[vertex].head;
        while (temp) {
        if (!visited[temp->data])
            DFSUtil(graph, temp->data, visited);
        temp = temp->next;
        }
}

void DFS(Graph *graph,int startVertex)
{
    bool *visited = (bool*)malloc(sizeof(bool) * graph->vertices);
    for(int i = 0 ; i < graph->vertices;i++)
        visited[i] = false;
    DFSUtil(graph,startVertex,visited);

    free(visited);
    
}
int main()
{
    int vertices = 7;
    Graph *graph = createGraph(vertices);

    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,0,3);
    addEdge(graph,1,4);
    addEdge(graph,3,5);
    addEdge(graph,3,6);

    printf("DFS ");
    DFS(graph,0);
}