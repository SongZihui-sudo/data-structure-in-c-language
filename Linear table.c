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
//定义结构体
typedef struct
{
    /* data */
    //int data;
    int size;
    Elemtype data[MAXSIZE];
    int length;
}sqlist;
//function
//初始化子函数
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
    initline(&s);//初始化线性表
    enable(&s);  //功能选择，插入，删除，寻找。 
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
            add(&line);//插入
            break;
        }
        else if (i=='s'){
            /* 减 */
            sub(&line);//删除
            break;
        }    
        else if(i=='f'){
            find(&line);//寻找
            break;
        }
        else{
            printf("ERROR!\n");//错误处理
        }
    }
}
//init
//初始化线性表
int initline(sqlist *l){
    l=(sqlist *)malloc(MAXSIZE*sizeof(sqlist));//开辟出相应的内存空间
    if(!l->length){
        printf("init error!\n");
        return error;
    }
    l->length=0;
    printf("init ok!\n");
    }
//add
int add(sqlist *add){
    inputline(add);//向表中加入数据
    int j, k;
    printf("ADD\n");  
    if(add->length>MAXSIZE){//判断是否超长
        printf("line error!\n");
        return error;
    }
    scanf("%d",&j);//读取位置
    scanf("%d",&k);//读取插入的数
    size=MAXSIZE;
    for(int l=0;l<size-j;l++){
        add->data[size-l]=add->data[size-l-1];//最后一个向size+1移动，倒数第二个去最后一个以此类推。
    }
    add->data[j]=k; 
    //输出插入后的表
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
    scanf("%d",&j);//输入删除的位置
    size=MAXSIZE-1;
    for (int y = 0; y < size-j ; y++){
        /* code */
        sub->data[j+y]=sub->data[j+1+y];//向删除的位置移动，删除位置+1的元素
    }
    //输出删除后的线性表
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
    scanf("%d",&j);//读取要寻找的值
    size=MAXSIZE;
    //printf("%d\n",size);
    //循环遍历线性表
    for (find->length= 0;find->length <size;find->length++)
    {
        printf("finding\n");
        printf("find=%d\n",find->data[find->length]);
        //表中元素与J一一比较。
        if (j==find->data[find->length])
        {
            /* code */   
            printf("get! postion is :%d\n",find->length);
            return OK;
        }
        //错误处理
        else{
            printf("NOT FOUND!\n");
        }
    }
}
