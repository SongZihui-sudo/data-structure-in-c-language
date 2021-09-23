#include "stdio.h"
#include "stdlib.h"
//各种宏定义
#define MAXSIZE 5
#define OK 0
#define ERROR 1
#define uchar unsigned char
//结构体有两个数组，一个存放原数据，一个存放排序后的数据
typedef struct Bubbling{
    int key[MAXSIZE];
    int sort[MAXSIZE];
}Bubbling;
//主函数
int main(){
    int j,k;//定义变量
    Bubbling *b;//结构体指针
    b=(Bubbling*)malloc(sizeof(Bubbling));//为结构体分配内存空间
    printf("Bubbling sort!\n");//提示
    for (int i = 0; i < MAXSIZE; i++){    
        printf("input:");//为数组赋值
        scanf("%d",&b->key[i]);
        b->sort[i]=b->key[i];//给排序数组赋值
    }
    //进行排序
    for (int i = 0; i < MAXSIZE-1; i++){
        for (int j = 0; j < MAXSIZE-1-i; j++){//冒泡排序法
            if ( b->sort[j] > b->sort[j+1] ){//for循环嵌套，内层for循环每进行一次把两两比较较小的先前挪1位。
                k=b->sort[j];//进行交换
                b->sort[j]=b->sort[j+1];
                b->sort[j+1]=k;
            }
        }
    }
    return 0;//返回0
}
