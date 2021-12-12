#include<stdio.h>

struct node{
    int data;//4
    struct node *next;//2
}*head=NULL,*last=NULL;

void insertnode();


int main(){

    int choice;
    while(1){

        printf("\n1 Insert\2 print\n3 Exit\nPlease Enter choice");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insertnode();
                break;
            case 1+1:
                printf("\n MEN AT WORK");
                break;
            case 2+1:
                exit(0);
        }
    }



    return 0;
}


void insertnode(){
    int num;
    struct node *tmp;

    printf("Enter number");
    scanf("%d",&num);

    if(head ==NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        last = head;
    }else{
        tmp  = (struct node*)malloc(sizeof(struct node));
        printf("Enter number");
        scanf("%d",&num);
        tmp->data = num;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;

    }
}






