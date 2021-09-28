#include <stdio.h>
#include <stdlib.h>
//宏定义
#define OK 0
#define ERROR -1
#define MAXSIZE 5
#define true 1
//子函数
int search();
//主函数
int main(){
    int arr[MAXSIZE];
    int i,k,x;
    printf("linear search!\n");
    for (int i = 0; i < MAXSIZE; i++){
        printf("input data:"); //读入数据
        scanf("%d",&arr[i]);
    }
    //输入要查找的数据
    printf("what you want to find:");
    scanf("%d",&k);
    x=-1;
    x = search(arr,k);//得到位置
    if (x=-1){
        printf("not found!\n");
        return ERROR;  //-1未查找到
    }
    else{
        printf("postion=%d\n",x);
        return OK;  //不为-1则未查找到
    }
}
//查找函数
int search(int key[MAXSIZE],int j){
    int left,right;
    left = 0;
    right = MAXSIZE;
    while (left!=right){
        if (key[left]==j){
            printf("found!\n"); 
            return left;  //从左边开始遍历
        }
        else if (key[right]==j){
            printf("found!\n");
            return right; //从右边开始遍历
        }
        else{
            printf("not found!\n");
        }
        left++;     //两边同时进行遍历，一边找到时，直接返回位置，没找到就输出NOT FOUND
        right--;
    }
}
