#include<stdio.h>

struct node {
    int data; //A B C 10 11 23
    struct node *next;
};
struct adjList {
    struct node* head;//A B C D E
};
struct Graph{
    int v;//total vertex
    struct adjList* list;//array ->
};


//create graph
 struct Graph* createGraph(int v){ //6
    int i;
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->list = (struct adjList*)malloc(v * sizeof(struct adjList));//10 byte --> 6 * 10 = 60

    //memory -- null

    for(i=0;i<v;i++){
        graph->list[i].head = NULL; //6 -> linklist --> list [ a- b c , b -> a d ]
    }
    printf("\nInit Graph done");
    return graph;
};


struct node* newAdjList(int dest){
    //A
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = dest ;
    newNode->next = NULL;
    printf("\nNewAdjLIST works...");
    return newNode;
}

void addEdge(struct Graph *g, int src,int dest){
    //0 - 1
    //0 - 2
    //0 - 3
    //3 - 1
    struct node* p = NULL;
    struct node* newNode = newAdjList(dest);//1

     if(g->list[src].head == NULL ){
        newNode->next = g->list[src].head;
        g->list[src].head  = newNode;
     }else{
            p = g->list[src].head; // 0 -> 1   2  3
            while(p->next!=NULL){  // 1 -> 0  3
                p=p->next;
            }
            p->next = newNode;
     }


     //src
        p=NULL;
        newNode = newAdjList(src);
        if(g->list[dest].head == NULL){
            newNode->next = g->list[dest].head ;
            g->list[dest].head = newNode;
        }else{

                p = g->list[dest].head;
                while(p->next != NULL){
                    p=p->next;
                }
                p->next = newNode;

        }

}


void printAllData(struct Graph *g){
    int i ;
    for(i=0;i<g->v;i++){
        struct node *p = g->list[i].head;
        printf("\nAdjList of %d\n : ",i); //0
        while(p!=NULL){
            printf(" %d ",p->data);
            p=p->next;
        }

    }


}

 int main(){

    int totalNode = 6;


    struct Graph* graph =   createGraph(totalNode);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,4,3);
    addEdge(graph,1,3);
    addEdge(graph,4,5);
    addEdge(graph,1,2);
    addEdge(graph,2,5);

    printAllData(graph);
    return 0;
 }
