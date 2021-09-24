#include "stdio.h"
#include "stdlib.h"
//宏定义
#define OK 0
#define ERROR 1
#define MAXSIZE 10
#define uchar unsigned char
//子函数
struct dichotomy *sort();//冒泡排序法排序
int find();//查找
//结构体
typedef struct dichotomy{
    int size,l;
    int sort[MAXSIZE];
    int key[MAXSIZE];
}dichotomy;
//主函数
int main(){
    int j,mid;//变量
    printf("dichotomy!\n");
    dichotomy *d;//结构体指针
    d=(dichotomy*)malloc(sizeof(dichotomy));//为结构体分配内存空间
    sort(d);  //排序
    find(d);//查找
    return 0;//返回0
}
//冒泡排序法排序
struct dichotomy *sort(dichotomy *s){
    int k;
    printf("sort!\n");
    printf("input size:");
    scanf("%d",&s->size);
    if (s->size > MAXSIZE){
        printf("error!\n");
        return ERROR;
    }//如果输入长度超过最大长度则报错
    for (int i = 0; i < s->size; i++){
        s->key[i] = rand() % 10;//存原数据
        s->sort[i]=s->key[i];//存排序后数据
    }//读取数据
    //排序
    for (int i = 0; i < s->size-1; i++)
    {
        for (int j = 0; j < s->size-1-i; j++){//随i的值加一，较小的值向前移动一位
            if (s->sort[j]>s->sort[j+1]){
                k=s->sort[j];
                s->sort[j]=s->sort[j+1];
                s->sort[j+1]=k;
            }
        }
    }
    return s;
}
/*
    EXAMPLE:
                                    冒泡排序法
                    i=0         56380    4
                    i=1         53608    3
                    i=2         35068    2
                    i=3         30568    1
                    i=4         03568    FINSH
    通过两个for循环嵌套，第一次循环，就先两两进行比较，较小的先前提一位，第二次循环次数减1，较小的在先前提一位，直至第一位是最小的。
*/
//查找
int find(dichotomy *find){
    dichotomy *p;
    p=find;
    int last,first,mid;
    int i;
    int u; 
    i=0;
    printf("input finddata:");
    scanf("%d",&u);//读取要查找的数据
    last=p->size-1;
    first=0;
    //判断首尾
    while (first <= last){
        mid=(first+last)/2;//找中间值
        if (u < p->sort[mid]){
            last=mid-1;//如果数在前半部分，最后一个应该是中间数前的一个
            i++;
        }
        else if (u > p->sort[mid]){
            first=mid+1;//如果数在后半部分，第一个应该是中间的中间数的后一个
            i++;
        }
        else{
            printf("postion=%d",mid);//u==p->sort[mid]是输出位置
            return mid;//返回位置
        }
    }
    return ERROR;//没找到
}
/*
                                                    二分法查找：
    相对数组进行由大到小的排序，并找出中间数。判断输入的数是大于还是小于中间数，如果等于直接输出位置。
    大于的话，就在后半区域，mid+1-last间，通过循环再找出这半区的中间数判断大于小于等于，等于就输出，
    如果还大于就再次定位first到mid+1，直至找到数据。
    与最初的中间数小于的话，就把last定位到mid-1，进行比较，不想等就继续计算出mid的值，直至找到要查找的值。

*/
