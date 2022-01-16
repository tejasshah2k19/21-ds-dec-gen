#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
}; //main_root

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

struct node *rightRotate(struct node *x){

        struct node *y = x->left;
        struct node *yr = y->right;
        y->right = x;
        x->left = yr;

        //recalculate

        x->height = max(getHeight(x->left),getHeight(x->right)) + 1; // 1
        y->height = max(getHeight(y->left),getHeight(y->right)) + 1; // 2

        return y;
}


struct node *leftRotate(struct node *x){

        struct node *y = x->right;
        struct node *yr = y->left;
        y->left = x;
        x->right = yr;

        //recalculate

        x->height = max(getHeight(x->left),getHeight(x->right)) + 1; // 1
        y->height = max(getHeight(y->left),getHeight(y->right)) + 1; // 2

        return y;
}



struct node* addNode(struct node *root,int data){//80,90
    //if(root != NULL){
      //  printf("\nCalling for %d : %d ",root->data,data);
   // }
    if(root == NULL){
       return createNode(data);

    }else if( data > root->data){//100
            //right
            root-> right = addNode(root->right,data);//90->right =
    }else if(  data < root-> data ){
            //left
          //  printf("\ni m in left %d",root->data);
            root-> left = addNode(root->left,data);//
            //printf("\n returning %d --> ",root->data);
    }

    root->height = 1 +  max( getHeight(root->left) , getHeight(root->right) );


    if( getBF(root) == 0 || getBF(root) == -1  || getBF(root) == 1 ){

    }else{
        printf("\nInvalid BF => %d",root->data); // 60 50 40 LL
        //rotation

        if( getBF(root) > 1 && root->left->data > data ) { // LL insertion
                printf("\nDoing right rotate for : %d ",root->data);
                return rightRotate(root);
        }
        else if( getBF(root) < -1 && root->right->data < data ) { //RR insertion
                printf("\nDoing left rotate for : %d ",root->data);
                return leftRotate(root);
        }
        else  if( getBF(root) > 1 && root->left->data < data ) { // LR insertion
                printf("\nDoing LR -> double rotation for : %d ",root->data);
                root->left = leftRotate(root->left);
                return rightRotate(root);
        }else  if( getBF(root) < -1 && root->right->data > data ) { // RL insertion
                printf("\nDoing RL -> double rotation for : %d ",root->data);
                root->right = rightRotate(root->right);
                return leftRotate(root);
        }


          //

        //



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
    //main_root = root

    root =  addNode(root,100);//80
    //printf("\n1");

   // printf("\n%d ",root->data);
 root  =   addNode(root,150);
    //printf("\n2");
   // printf("\n%d ",root->data);

   root =  addNode(root,120);
   // printf("\n3");
   //

   // printf("\n%d ",root->data);


     //addNode(root,60);
     //printf("\n4");

     //addNode(root,85);
     //printf("\n5");


    // addNode(root,105);
    // printf("\n5");

    printf("\nInsertion done");

    //printf("%d ",root->data);


    printf("\n-----all data-----\n");
    inorder(root);
    return 0;
}
