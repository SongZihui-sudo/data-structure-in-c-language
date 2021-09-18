//kmp
#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define MAXSIZE 5
#define subsize 2
#define uchar unsigned char

int input();
int find();

typedef struct kmp{
    uchar Substring[subsize];
    uchar Parent_string[MAXSIZE]; 
}kmp;

int main(void){
    kmp *k;
    int i,j;
    k=(kmp*)malloc(sizeof(kmp));
    input(k);
    find(k);
    return OK;
}

int input(kmp *l){
    int i;
    int j;
    int y;
    printf("kmp strings!\n");
    for (i = 0; i < subsize; i++){
        printf("input string:");
        scanf("%s",&l->Substring[i]);
    }
    printf("parent_string!\n");
    for (i = 0; i < MAXSIZE; i++){ 
        printf("input string:");
        scanf("%s",&l->Parent_string[i]);
    }
    printf("input over!\n");
    return l;
}

int find(kmp *f){
    int h,n;
    int j=0;
    int i=0;
    int y=0;
    while (i<subsize){
        while (f->Substring[i]!=f->Parent_string[j]){
            y++;
            if (i==0){
                f->Parent_string[j]=f->Substring[i];
                i++;
            }
            while (f->Parent_string[j]!=f->Parent_string[y]){
                y++;
            } 
                j=y+1;
                }
       i++;
       y=j;
       printf("postion=%d,%d\n",y,y+1);
    }    
    return OK;
    }   
  
