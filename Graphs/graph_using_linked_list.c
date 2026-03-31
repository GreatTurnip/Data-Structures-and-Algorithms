#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
} NODE;

void insertEdge(NODE* GRAPH[],int N,int u,int v)
{
    if(u>=0 && v>=0 && u<N && v<N) 
    {
        NODE *new = (NODE*)malloc(sizeof(NODE));
        new->info = v;
        new->next = NULL;
        if(GRAPH[u]==NULL)  GRAPH[u]=new;
        else 
        {
            new->next = GRAPH[u];
            GRAPH[u] = new;
        }
    }
    
}
void deleteEdge(NODE* GRAPH[],int N,int u,int v)
{
    if(GRAPH==NULL) return;
    else if(GRAPH[u]->info==v)
    {
        NODE* ptr = GRAPH[u];
        GRAPH[u] = GRAPH[u]->next;
        free(ptr);
    }
    else{
        NODE* cur = GRAPH[u]->next;
        NODE* prev = GRAPH[u];
        while(cur!=NULL)
        {
            if(cur->info!=v)
            {
                prev = cur;
                cur = cur->next;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                return;
            }
        }
    }
}
void searchEdge(NODE* GRAPH[],int N,int u,int v)
{
    if(u>=0 && v>=0 && u<N && u<N)
    {
        if(GRAPH[u]==NULL)  return;
        else
        {
            NODE* cur = GRAPH[u];
            while(cur!=NULL)
            {
                if(cur->info==v)
                {
                    printf("(%d,%d) Found!\n",u,v);
                    return;
                }
                else
                    cur = cur->next;
            }
        }
    }
}
void print(NODE* GRAPH[],int N)
{
    printf("\n");
    for(int i=0;i<N;i++)
    {
        NODE* cur = GRAPH[i];
        printf("VERTEX %d : ",i);
        while(cur!=NULL)
        {
            printf("%d ",cur->info);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() {
    int N = 5; // Number of vertices
    NODE* GRAPH[N];

    // Initialize all vertices to NULL
    for (int i = 0; i < N; i++)
        GRAPH[i] = NULL;

    // Insert some edges
    insertEdge(GRAPH, N, 0, 1);
    insertEdge(GRAPH, N, 0, 4);
    insertEdge(GRAPH, N, 1, 2);
    insertEdge(GRAPH, N, 1, 3);
    insertEdge(GRAPH, N, 3, 4);

    printf("Graph after inserting edges:\n");
    print(GRAPH, N);

    // Search for some edges
    searchEdge(GRAPH, N, 0, 1);
    searchEdge(GRAPH, N, 2, 3); // Not present

    // Delete an edge
    deleteEdge(GRAPH, N, 1, 3);
    printf("\nGraph after deleting edge (1,3):\n");
    print(GRAPH, N);

    // Free all memory
    for (int i = 0; i < N; i++) {
        NODE* cur = GRAPH[i];
        while (cur != NULL) {
            NODE* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }

    return 0;
}
