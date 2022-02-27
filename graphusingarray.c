#include<stdio.h>
#define S  4

int graph[S][S];

int main(){

    int i,j,choice;

    //A => 65
    for(i=0;i<S;i++){
        for(j=i;j<S;j++){
            printf("\n%c is connected with %c ",65+i,65+j);//65,65 => A,A
            printf("\n1 For Yes\n0 For No");
            scanf("%d",&choice);

            graph[i][j] = choice; //A - B ==> yes
            graph[j][i] = choice; //B - A ==> yes
        }

    }

    printf("\nList of Adj --> connected node \n");

   for(i=0;i<S;i++){
        printf("%c ",65+i);//A
        for(j=0;j<S;j++){
            if(graph[i][j]!=0)
                    printf("%c ",65+j);
         }
        printf("\n");
    }



    return 0;

}
