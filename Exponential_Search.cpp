#include <iostream>
#include <vector>
//宏定义
#define OK 0
#define ERROR -1
#define true 1
//子函数
int expon_search(struct Exponential_Search find); //确定范围
int Binary_Search(struct Exponential_Search Binary,int left); //再确定的范围内进行二分法查找
//结构体
typedef struct Exponential_Search{
    std::vector<int> arr; //arr
    int size,f; 
}Exponential_Search;
//主函数
int main(){
    Exponential_Search e;
    std::cout<<"Exponential Search"<<"\n"<<"input size"<<"\n"; //提示
    std::cin>>e.size;//读入数组大小
    for (int i = 0; i < e.size; i++){
        e.arr.push_back(i); //像数组中压入数据
    }
    //先简单的利用冒泡排序法进行排序
    int l;
    for (int i = 0; i < e.size-1; i++){
        for (int j = 0; i < e.size-1-i; i++){
            if ( e.arr[j] > e.arr[j+1] ){
                l = e.arr[j];
                e.arr[j] = e.arr[j+1];
                e.arr[j+1] = e.arr[j];
            }
        }
    }  
    //读入要输入的数据
    std::cout<<"what you want to find?"<<"\n";
    std::cin>>e.f;  
    int g;
    g=0;
    //根据返回值，确认是不是找到了，-1是没找到，其他值是找到了
    g = expon_search(e);
    if (g == -1){
        std::cout<<"not found!"<<"\n";
        return OK; //不存在
    }
    else{
        std::cout<<"potsion is "<<g<<"\n";
        return OK; //输出位置
    }
}
//确定范围
int expon_search(struct Exponential_Search find){
    int left,right;
    int j;
    left = 1;
    right = find.size-1;
    int step; 
    if (find.f == find.arr[0]){
        return left;
    } //先确定第一个相不相等
    while ( find.arr[left] <= find.f && left < right ){
            left*=2;      //确定范围，left每一次翻一番，知道要找到值小于数组中的值是停止循环，另一个条件是防止数组下标溢出
        }
    return Binary_Search(find,left);//在指定范围内进行二分法查找
} 
//二分法查找
int Binary_Search(struct Exponential_Search Binary,int left){
    int mid,right;
    right = left;        
    left = 0;  //确定初步边界
    while (right >= left){        
        mid=static_cast<int>(left+right)/2; //计算中间数的值
        if ( Binary.f < Binary.arr[mid]){
            right = mid -1 ; //在前半段，把right提到mid前面
        }
        else if ( Binary.f > Binary.arr[mid] ){
            left = mid + 1;  //在后半段，把left提到mid后边
        }
        else{
            return mid; //既不大于也不小于，就是小于
        }        
    }
    return ERROR; //遍历完也没找到，不存在，返回错误
} 
