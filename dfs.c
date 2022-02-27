#include<stdio.h>


struct node{
    int vertext; // 10 11 12 14
    struct node* next; // adj list maintain
};



struct Graph {
    int vertices; // 7
    int *visited; // visit
    struct node** adjList;// total--> 7
}*graph;

//5
createGraph(int vertices){//7

        int i;
        graph = (strcut Graph*)malloc(sizeof(struct Graph))

        graph->vertices = vertices;//total vertex

        graph->adjList = malloc(vertices * sizeof(struct node*));
        graph->visited = malloc(vertices * sizeof(int)); //7 -> 0

        for(i=0;i<vertices;i++){
            graph->adjList[i] = NULL; //A B C D E F G
            graph->visited[i] = 0; // all nodes are untouch no visit yet
        }

}

struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->vetext = data ;
    newNode->next = NULL;
    return newNode;

}

//node -> node [ 10,50] [10,60] [10,20]
addEdges(int src,int dest){
    struct node* sNode = createNode(src); //10
    struct node* dNode = createNode(dest); //50






}







