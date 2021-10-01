#include <iostream>
#include <vector>
//宏定义
#define OK 0
#define ERROR -1
#define MAXSIZE
//子函数
int search(struct jmup s);
//结构体
typedef struct jmup{
    int size;
    std::vector<int> arr;
    int h;
}jmup;
//主函数
int main(){
    jmup j;
    std::cout<<"jump search"<<"\n";
    int n;
    std::cout<<"input size:"<<"\n";
    std::cin>>j.size;
    //把数据压入数组
    for (int i = 0; i < j.size; i++){
        j.arr.push_back(i);
    }
    //读取要搜索的值
    std::cout<<"what you want to find?"<<"\n";
    std::cin>>j.h;
    //用y来判断是否找到目标值,L来得到位置
    int y,L;
    y=-1;
    y,L=search(j);
    //输出位置
    if (y == -1 && L != -1){
        std::cout<<"postion is:"<<L<<"\n";

    }
    //没有找到要查找的值
    else{
        std::cout<<"not found"<<"\n";        
    }
    return 0;
}
//搜索子函数
int search(struct jmup s){
    //进行冒泡排序
    for (int i = 0; i < s.size-1; i++){
        for (int j = 0; j < s.size-i-1; j++){
            int b;
            if (s.arr[j]>s.arr[j+1]){
                b=s.arr[j];
                s.arr[j]=s.arr[j+1];
                s.arr[j+1]=b;
            }
        }
    }
    //left是开始的时候，right是结尾，step每次走到步的距离
    int left,right,step;
    left=0;
    step=0;
    right=s.size;
    while ( s.h > s.arr[left] && right >= left){
        left += step;
        step++;  //走步距离每次加一
    }
    step = 1 ;
    //判断是否相等
    while (s.h != s.arr[left] && right != left){
        left-=step;
        //向回遍历，如果相等就退出循环
        if (right == left){
            return ERROR;
        }
    }
    //如果相等就输出OK和位置
    return OK,left;
}
