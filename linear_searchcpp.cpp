#include <iostream>
#include <vector>
//宏定义
#define MAXSIZE 5
#define OK 1
#define ERROR -1
//子函数
int search(std::vector<int> key,int k);
//主函数
int main(){
    std::cout<<"linear search in c++" << "\n" ;
    std::vector<int> arr; // 使用了vector容器，可以实现动态数组
    for (int i = 0; i < MAXSIZE; i++){
        arr.push_back(i); //压入数据
    }  
    std:: cout<<"what you want to find?" << "\n";
    int j;
    std:: cin >> j; //获取要搜索的值
    int p;
    p=-1;
    p=search(arr,j);
    if (p==-1){ //-1为错误
        std::cout<<"NOT FOUND!"<<"\n"; //输出not found
    }
    else{
        std::cout<<"postion:"<<p<<"\n"; //找到位置
    }
    return 0;
}
//搜索
int search(std::vector<int> key,int k){
    int left,right;
    left=0;
    right=MAXSIZE; //从左右两边同时开始遍历
    while (left<=right){
        if (key[left] == k){
            return left ;
        } //左边找到返回位置
        else if (key[right] == k){
            return right; //右边找到返回位置
        }
        else{
            std::cout << "Now not found!" << "\n" ; //当前位置不是要查找的元素
        }
        left++;
        right--; //自增 自减
    }
    return ERROR; //没找到，返回错误
}
