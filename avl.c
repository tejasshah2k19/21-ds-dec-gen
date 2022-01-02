#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node* createNode(int data){
    struct node  *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    tmp->height = 1;
    return tmp;
};

int getHeight(struct node* node){
    if(node == NULL){
        return 0;
    }else{
        return node->height;
    }
}
int max(int a,int b){
    return a>b?a:b;
}

int getBF(struct node* node){

        return getHeight(node->left) - getHeight(node->right);

}

struct node* addNode(struct node *root,int data){//80 90
    //if(root != NULL){
      //  printf("\nCalling for %d : %d ",root->data,data);
   // }
    if(root == NULL){
       return createNode(data);

    }else if( data > root->data){//100
            //right
            root-> right = addNode(root->right,data);//90
    }else if(  data < root-> data ){
            //left
          //  printf("\ni m in left %d",root->data);
            root-> left = addNode(root->left,data);//
            //printf("\n returning %d --> ",root->data);
    }
    root->height = 1 +  max( getHeight(root->left) , getHeight(root->right) );
    if( getBF(root) == 0 || getBF(root) == -1  || getBF(root) == 1 ){

    }else{
        printf("\nInvalid BF => %d",root->data);
        //rotation
    }

    return root;
}

void inorder(struct node* root){

    if(root != NULL){
            inorder(root->left);
            printf(" %d:%d:%d",root->data,root->height,getBF(root));
            inorder(root->right);
    }
}

int main(){
    struct node *root=NULL;//80

    root =  addNode(root,80);//80
    printf("\n1");

   // printf("\n%d ",root->data);
    addNode(root,90);
    printf("\n2");
   // printf("\n%d ",root->data);

    addNode(root,100);
    printf("\n3");
   //

    printf("\n%d ",root->data);


     addNode(root,60);
     printf("\n4");

     addNode(root,85);
     printf("\n5");


    printf("\nInsertion done");

    printf("%d ",root->data);
    printf("\n-----all data-----\n");
    inorder(root);
    return 0;
}
