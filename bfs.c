#include<stdio.h>
#define SIZE 15

struct queue{
    int f;
    int r;
    int items[SIZE];
};


struct node {
    int vertex;
    struct node *next;

};

struct Graph{
    int totalVertices;
    struct node** adjList;
    int* visited;

};


struct node* createNode(int d){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = d;
    newNode->next = NULL;
    return newNode;
};

struct Graph* createGraph(int totalVertices){
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->totalVertices = totalVertices ;
    graph->adjList = (struct node**)malloc(totalVertices * sizeof(int));
    graph->visited = (int*)malloc(totalVertices * sizeof(int));


    for(i=0;i<totalVertices;i++){
        graph->adjList[i] = NULL;
        graph->visited[i] = 0; //not visited
    }

    return graph;
}


void addEdge(struct Graph* graph,int src,int dest){

    struct node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->f=-1;
    q->r=-1;
    return q;
};
void addQ(struct queue *q,int data){

    if(q->r == SIZE-1){
        printf("\nQ is Full...");
    }else{
        if(q->f == -1 ){
            q->f = 0;
        }
        q->r++;//-1
        q->items[q->r] = data;
    }

}
int removeQ(struct queue *q){
    int data;
    if(q->f == -1){
        printf("\nQ is Empty");
        data =  -1;
    }else{
        data = q->items[q->f];
        q->f++;

        if(q->f > q->r){
            q->f =-1;
            q->r =-1;
        }

    }
    return data;
}


void displayQueue(struct queue *q){
    int i;
    if(q->f == -1){
        printf("\nQ is Empty");
    }else{
        printf("\nQueue Contents\n");
        for(i=q->f;i<=q->r;i++){
            printf("%d ",q->items[i]);
        }
    }
}

void dfs(struct Graph *graph,int startV){
    struct node* adjList = graph->adjList[startV];//0 3  2 14
    struct node* p = adjList;//3
    int nData;


    graph->visited[startV] = 1;
    printf("\nVisited : %d",startV); //0

    while(p!=NULL){
        nData = p->vertex;//3  4   1

        if(graph->visited[nData] == 0){
            dfs(graph,nData);
        }

        p=p->next;
    }


}



void bfs(struct Graph *graph,int startV){
    int oldNode;
    struct node *p = NULL;
    int nData;
    struct queue *q = createQueue();

    graph->visited[startV] = 1; //0visited
    addQ(q,startV);

    while(q->f != -1){
      //  displayQueue(q); //0 3 2 1 4
        oldNode = removeQ(q);//0 is removed from queue
        printf("  Visited = %d",oldNode);
        p = graph->adjList[oldNode];


        while(p!=NULL){
            nData = p->vertex; //3 2 1
            if(graph->visited[nData] == 0){
                graph->visited[nData] = 1;
                addQ(q,nData);//3 2 1 4
            }
            p=p->next;
        }//while adjList
    }//queue main while
}


int main(){

    struct Graph *myGraph = createGraph(6);
        addEdge(myGraph,0,1);
        addEdge(myGraph,0,2);
        addEdge(myGraph,0,3);
        addEdge(myGraph,3,2);
        addEdge(myGraph,3,4);
        addEdge(myGraph,4,1);

       // bfs(myGraph,0);
        dfs(myGraph,0);
        return 0;
}

