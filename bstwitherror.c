#include<stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}*main_root=NULL;

struct node* createNode();
struct node* addNode(int data,struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int search(struct node*,int searchData);

struct node* deleteNode(struct node*,int deleteItem,struct node*);


int main(){
    int i,num,searchData;

    /*for(i=1;i<=7;i++){ //4
        printf("Enter number");
        scanf("%d",&num);// 70 60 80 90  75 65 55
        addNode(num,main_root);// 90,mainRoot0(70)
    }*/

    main_root = addNode(70,main_root);
    if(main_root == NULL){
        printf("root is null");
    }

     addNode(60,main_root);
     addNode(80,main_root);
     addNode(90,main_root);
     addNode(75,main_root);
    //addNode(65,main_root);
    addNode(55,main_root);

    //                70
    //            60         80
    //        55     [65]  75        90
    //
    //
    printf("\nItems added\n");
    inorder(main_root);


   // printf("Enter number to search?");
    //scanf("%d",&searchData);

    //printf("search ==> %d ", search(main_root,searchData) ) ;


    deleteNode(main_root,55,NULL);
    printf("\nAfter Remove\n");
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

struct node* addNode(int num,struct node *root){ //90, -root-80
    struct node *tmp;
    if(root == NULL){
        root = createNode();
        root->data = num;
        return root;

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
    //
}

void inorder(struct node* root){ //70

    if(root != NULL){

         inorder(root->left);
         printf("%d ",root->data);
         inorder(root->right);
    }
}



void preorder(struct node* root){ //70

    if(root != NULL){

         printf("%d ",root->data);
         preorder(root->left);
         preorder(root->right);
    }
}



void postorder(struct node* root){ //70

    if(root != NULL){

         postorder(root->left);
         postorder(root->right);
         printf("%d ",root->data);

    }
}

int search(struct node* root,int searchData){
    if(root!=NULL){

        if(root->data == searchData){
            return 1;
        }else if(root->data > searchData ){
            search(root->left,searchData);
        }else if(root->data <  searchData ){
            search(root->right,searchData);
        }

    }else{
        return -1;
    }
}


//40 50 60 70 80 90 100 110
struct node* deleteNode(struct node* root,int deleteItem,struct node *parent){ //70 60 55

    if(root == NULL){
        return NULL;
    }else if(root->data > deleteItem ){
        //left
        //root->70
        parent = root; //60
        deleteNode(root->left,deleteItem,parent);


    }else if(root->data < deleteItem){
        parent = root; //60
        deleteNode(root->right,deleteItem,parent);
        //right
    }else if(root->data == deleteItem){
        printf("\n\nElement found");
        //leaf
        if(root->left == NULL && root->right == NULL){
            printf("\nnode is leaf node");
            //parent->left = null
            printf("\nParent node => %d",parent->data);
            if(parent->data > deleteItem){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
            free(root);
        }
        //one child
        else if(root->left == NULL || root->right == NULL){
            printf("\nNode is parent node with one child");
        }
        //two child
        else if(root -> left != NULL && root->right != NULL ){
            printf("\nNode is parent node with two child");
        }
    }


}


