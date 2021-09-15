#include "stdio.h"
#include "stdlib.h"

#define unchar unsigned char
#define error 1
#define OK 0
#define MAXSIZE 5
#define Elemtype int
unchar i;
int size;
int DATA_WRITE[MAXSIZE]={0,1,2,3,4};
typedef struct
{
    /* data */
    //int data;
    int size;
    Elemtype data[MAXSIZE];
    int length;
}sqlist;
//function
int initline(sqlist *l);
int printline(sqlist *SQ);
int inputline(sqlist *f);
int enable();
int add();
int sub();
int find();
int enable(sqlist *line);
//main
int main(void){
    sqlist s;
    initline(&s);
    enable(&s);   
    return 0;
}
//input
int inputline(sqlist *f){
    for ( f->length = 0; f->length < MAXSIZE; f->length++){
         /* code */ 
            f->data[f->length]=DATA_WRITE[f->length];
            printf("input=%d\n",f->data[f->length]);
    }
    printf("input over!\n"); 
    }
//功能选择
int enable(sqlist *line){
    printf("choose!\n");
    while (1)
    {
        scanf("%s",&i);
        /* 加 */
        if(i=='a'){
            add(&line);
            break;
        }
        else if (i=='s'){
            /* 减 */
            sub(&line);
            break;
        }    
        else if(i=='f'){
            find(&line);
            break;
        }
        else{
            printf("ERROR!\n");
        }
    }
}
//init
int initline(sqlist *l){
    l=(sqlist *)malloc(MAXSIZE*sizeof(sqlist));
    if(!l->length){
        printf("init error!\n");
        return error;
    }
    l->length=0;
    printf("init ok!\n");
    }
//add
int add(sqlist *add){
    inputline(add);
    int j, k;
    printf("ADD\n");  
    if(add->length>MAXSIZE){
        printf("line error!\n");
        return error;
    }
    scanf("%d",&j);
    scanf("%d",&k);
    size=MAXSIZE;
    for(int l=0;l<size-j;l++){
        add->data[size-l]=add->data[size-l-1];
    }
    add->data[j]=k; 
    for (add->length = 0; add->length < size; add->length++){
            /* code */
        printf("add=%d\n",add->data[add->length]);
                }
    return OK;
}
//sub
int sub(sqlist *sub){
    int j,k;
    printf("SUB\n");
    inputline(sub);
    scanf("%d",&j);
    size=MAXSIZE-1;
    for (int y = 0; y < size-j ; y++){
        /* code */
        sub->data[j+y]=sub->data[j+1+y];
    }
    for (sub->length = 0; sub->length < size; sub->length++){
            /* code */
        printf("add=%d\n",sub->data[sub->length]);
                }
    return OK;
}
//find
int find(sqlist *find){
    inputline(find);
    printf("find\n");
    int j;
    scanf("%d",&j);
    size=MAXSIZE;
    //printf("%d\n",size);
    for (find->length= 0;find->length <size;find->length++)
    {
        printf("finding\n");
        printf("find=%d\n",find->data[find->length]);
        if (j==find->data[find->length])
        {
            /* code */   
            printf("get! postion is :%d\n",find->length);
            return OK;
        }
        else{
            printf("NOT FOUND!\n");
        }
    }
}
