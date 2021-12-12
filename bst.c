#include<stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}*main_root=NULL;

struct node* createNode();
void addNode(int data,struct node*);
void inorder(struct node*);

int main(){
    int i,num;

    /*for(i=1;i<=7;i++){ //4
        printf("Enter number");
        scanf("%d",&num);// 70 60 80 90  75 65 55
        addNode(num,main_root);// 90,mainRoot0(70)
    }*/

    addNode(70,main_root);
    addNode(60,main_root);
    addNode(80,main_root);
    addNode(90,main_root);
    addNode(75,main_root);
    addNode(65,main_root);
    addNode(55,main_root);

    inorder(main_root);

    return 0;
}
struct node* createNode(){
    struct node *tmp;
     tmp = (struct node*) malloc(sizeof(struct node));
     tmp->left = NULL;
     tmp->right = NULL;
    return tmp;
};

void addNode(int num,struct node *root){ //90, -root-80
    struct node *tmp;
    if(root == NULL){
        root = createNode();
        root->data = num;

    }else{
        tmp=createNode();
         tmp->data = num;//90
        if(root->data > num){
            //left
           // root->left = tmp;
            if(root->left == NULL){
                root->left = tmp;
            }else{
                addNode(num,root->left);
            }
        }else{
            //right
            //root->right = tmp;
            if(root->right == NULL){
                root->right = tmp;
            }else{
                addNode(num,root->right);//90,80
            }
        }
    }
}

void inorder(struct node* root){ //70

    if(root != NULL){
         inorder(root->left);
         printf("%d ",root->data);
         inorder(root->right);
    }


}





