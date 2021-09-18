//kmp
#include "stdio.h"
#include "stdlib.h"
//宏定义
#define OK 1
#define ERROR 0
#define MAXSIZE 5//目标字符串长度
#define subsize 2//子串长度
#define uchar unsigned char
//子函数
int input();//输入字符串
int find();//查找子字符串位置
//定义子串，与目标字符串的结构体
typedef struct kmp{
    uchar Substring[subsize];
    uchar Parent_string[MAXSIZE]; 
}kmp;
//主函数
int main(void){
    kmp *k;//申明结构体
    int i,j;
    k=(kmp*)malloc(sizeof(kmp));//给结构体一定的内存空间
    input(k);//输入
    find(k);//查找
    return OK;//返回OK
}
//输入函数
int input(kmp *l){
    int i;
    int j;
    int y;
    printf("kmp strings!\n");
    for (i = 0; i < subsize; i++){
        printf("input string:");//读取子字符串的值
        scanf("%s",&l->Substring[i]);
    }
    printf("parent_string!\n");
    for (i = 0; i < MAXSIZE; i++){ 
        printf("input string:");//读取目标字符串的值
        scanf("%s",&l->Parent_string[i]);
    }
    printf("input over!\n");
    return l;//返回读入输入后的结构体.
}
//字符串查找函数
int find(kmp *f){
    int h,n;
    int j=0;
    int i=0;//一些变量
    int y=0;
    while (i<subsize){//循环字串长度次
        while (f->Substring[i]!=f->Parent_string[j]){//如果子串与目标串不相等进入循环
            y++;//y+1
            if (i==0){//如果是第一个就不相等，就把子串第一个的值赋给目标串的第一个。
                f->Parent_string[j]=f->Substring[i];
                i++;//子串的下标到第二个。
            }
            while (f->Parent_string[j]!=f->Parent_string[y]){
                y++;//在目标串中找到与第一个相等的
            } 
                j=y+1;//改变目标字符串的下标位置，比较下一个相不想等。
                }
       i++;//如果相等给子串数组下标加一
       y=j;//得到位置。
       printf("postion=%d,%d\n",y,y+1);//输出位置
    }    
    return OK;//返回OK
    }   

  
