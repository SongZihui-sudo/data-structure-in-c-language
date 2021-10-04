#include <iostream>
#include <vector>
//宏定义
#define OK 1
#define ERROR -1
#define true 1
//子函数
int print(struct Insertion_Sort printarr);
int sort(struct Insertion_Sort inser_sort);
//结构/类
typedef struct Insertion_Sort{
    std::vector<int> arr;
    int size;
}Insertion_Sort;
//主函数
int main(){
    Insertion_Sort main;
    std::cout<<"insertion sort"<<"\n";
    std::cout<<"input size";
    std::cin>>main.size;          //读入大小
    for ( int i = 0; i < main.size ; i++){
        std::cout<<"input data:";
        int j;                   //读入数据
        std::cin>>j;
        main.arr.push_back(j);
    }
    std::cout<<"print"<<"\n";  
    print(main); //输出
    sort(main); //排序
    return 0;
}
//排序
int sort(struct Insertion_Sort inser_sort){
    int key,j,c;
    j = 0;
    std::cout<<"sort"<<"\n"; //提示
    for (int i = 1; i < inser_sort.size; i++){
        key = inser_sort.arr[i]; //保存当前遍历到的元素
        c = i -1;  //前一个的下标
        while ( key < inser_sort.arr[c] && c >= 0){ //如果前面的大于后面的进入循环
            inser_sort.arr[c+1] = inser_sort.arr[c]; //后面的等于前面的
            c--; //继续比较               
        }
        //前c个元素是已经排序好的，后面的是没排序好的
        inser_sort.arr[c+1] = key; //然后面等于前面保存到值
    }
    print(inser_sort); //输出
    return OK;
}
//输出
int print(struct Insertion_Sort printarr){
    auto b=printarr.arr.begin();  //开始迭代器
    auto e=printarr.arr.end();    //结束迭代器
    for ( int i = 0; b!=e; b++){
        std::cout<<"data="<<*b<<"\n"; //输出数据
    }
    return OK;
}
