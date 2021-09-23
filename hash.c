#include "stdio.h"
#include "stdlib.h"
//各种宏定义
#define MAXSIZE 5 //表最大长度
#define LIST_Size 100 //
#define OK 0 //返回OK
#define ERROR 1 //返回error
#define true 1 //true
#define uchar unsigned char
//子函数
int find();//查找
struct hash *add();//插入
struct hash *del();//删除
int able();//功能选择
//结构体
typedef struct hash{
    int Key[MAXSIZE];
    int list[LIST_Size];
    int size;
}hash;
//主函数
struct hash *main(){
    int i,j;//变量
    hash *h;//结构体指针
    h=(hash*)malloc(sizeof(hash));//为结构体分配内存空间
    printf("Hash list!\n");
    printf("input data:\n");//提示语句
    for (int i = 0; i < MAXSIZE-1; i++){
        h->Key[i]=rand() % 10;//为key赋值
    }
    int max=h->Key[0];
    for (int i = 0; i < MAXSIZE-1; i++){//确定哈希表长，因为我做的这个表是把数据映射到与这个数据相等的数组的位置，所以以这个数组最大的数作为长度。
        if (h->Key[i]>max){
            max=h->Key[i]+1;//确定最大值，也就是表长
        }
    }
    h->size=max;
    for (i = 0; i < h->size; i++){//在数据的对应位置上赋值
        for (j = 0; j < MAXSIZE-1; j++){
            if (i==h->Key[j]){
                h->list[i]=h->Key[j];
            }
        }  
    }
    for (int i = 0; i < h->size; i++){
        printf("list=%d\n",h->list[i]);//输出哈希表
    }
    able(h);//进行功能选择
    return h;//返回h
}
//查找函数
int find(hash *sh){
    int k,y;
    uchar j;//两个变量
    printf("find!\n");//提示语句
    printf("postion or key\n");
    while (true){//第一个是根据位置查找key
        scanf("%s",&j);
        if (j=='p'){
            printf("input postion:");
            scanf("%d",&k);
            //根据原数组位置
            for (int i = 0; i < MAXSIZE-1; i++){
                if (k==i){
                    y=sh->list[sh->Key[i]];
                    printf("key=%d",y);
                    return y;//返回key
                }
            }
            //return y;//根据表位置
        }
        else if(j=='k'){//第二个是根据key查找位置
            printf("printf key:");
            scanf("%d",&k);
            for (int i = 0; i < MAXSIZE-1; i++){
                if (k==sh->Key[i]){
                    y=i;
                    printf("postion=%d\n",y);
                    return y;//返回原数组位置位置
                } 
            }
            //return k;返回在表中位置
        }
    }
    return OK;
}
//插入
struct hash *add(hash *Add){
    int j,k;
    printf("add!\n");
    printf("input postion:");//提示
    scanf("%d",&j);//读取位置原数组
    printf("input data:");
    scanf("%d",&k);//读取插入数据
    for (int i = 0; i < MAXSIZE-j; i++){
        Add->Key[MAXSIZE-i]=Add->Key[MAXSIZE-i-1];//向最后移动
    }
    Add->Key[j]=k;//赋值
    Add->list[Add->Key[j]]=k;//赋值
    return Add;//返回结构体指针
}
//删除
struct hash *del(hash *del){
    int j,i,p;
    uchar k;
    printf("delete\n");
    printf("input key or postion!\n");//提示
    while (true){
        scanf("%s",&k);
        if (k=='p'){
            printf("input postion:");
            //根据原数组位置
            scanf("%d",&j);
            for ( i = 0; i < MAXSIZE-1; i++){
                if (j == i){                 
                    del->list[del->Key[i]]=0;//在表中清零
                    //在原数组中删除
                    for (int u = 0; u < MAXSIZE-j; u++){
                        del->Key[j]=del->Key[j+1];//向删除位置移动
                    }
                    return del;
                }
            }
        }
        else if (k=='k'){
            printf("input key:");
            scanf("%d",&j);//读取数值，根据原数组。
            for (i = 0; i < MAXSIZE - 1; i++){
                if(del->Key[i]==j){
                    //在原数组中删除
                    for (int x = 0; x <MAXSIZE-i; x++){
                        del->Key[i]=del->Key[i+1];//先删除位置移动
                    }
                del->list[j]=0;//清零
                }
            }   
        }
            return del;
        }
    }
//功能选择
int able(hash *able){
    uchar j;
    printf("chose!\ninput:\n");
    while (true){
        scanf("%s",&j);
        if (j=='a'){
            add(able);//插入
            break;           
        }
        else if (j=='d'){
            del(able);//删除
            break;
        }
        else if (j=='f'){
            find(able);//查找
            break;
        }
        else{
            printf("ERROR!");
            return ERROR;//错误处理
        }
    }
    return OK;//返回OK
}
