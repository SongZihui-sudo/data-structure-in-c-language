#include <stdio.h>
#include <stdlib.h>
//宏定义
#define OK 0
#define ERROR -1
#define MAXSIZE 5
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
    return OK;
}
//查找函数
int search(int key[MAXSIZE],int j){
    for (int i = 0; i < MAXSIZE; i++){
        if (j==key[i]){           //遍历数组如果相等就输出位置
            printf("find:%d\n",i);
            return i;  //返回位置
        }
        else{
            printf("not found!\n"); //当前位置不是要查找的值
        }
    }
}
