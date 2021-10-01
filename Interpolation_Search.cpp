//插值查找法
//**适用于均匀分布的数据**
#include <iostream>
#include <vector>
//宏定义
#define OK 0
#define ERROR -1
#define true 1
//子函数
int search(struct Inter_search find);
//结构体
typedef struct Inter_search{
    std::vector<int> arr;  //存数据
    int f,size;  //f要查找的数，size数组大小
}Inter_search;
//主函数
int main(){
    Inter_search i_F;
    std::cout<<"Search!"<<"\n"<<"input size"<<"\n";
    std::cin>>i_F.size; //读取大小
    for (int i = 0; i < i_F.size; i++){
        i_F.arr.push_back(i);
    }
    //读取要查找的值
    std::cout<<"what you want find?"<<"\n";
    std::cin>>i_F.f;
    //先简单对数组进行排序
    for (int i = 0; i < i_F.size-1; i++){
        for (int k = 0; k < i_F.size-i-1; k++){
            int j;
            if ( i_F.arr[k] > i_F.arr[k+1] ){
                j = i_F.arr[k];
                i_F.arr[k] = i_F.arr[k+1];
                i_F.arr[k+1] = j;
            }
        }
    }
    //开始搜索
    int c = search(i_F);
    //没有找到
    if ( c == -1){
        std::cout<<"not found!"<<"\n";
    }
    //找到，返回位置
    else{
        std::cout<<"postion is:"<<c<<"\n";
    }
    return OK;
}
//搜索子函数
int search(struct Inter_search find){
    int key;
    //通过计算出每个数据均匀分布的值*要查找的数据与第一个的数据即可查找到得到要查找数据的下标位置，之后判断是否相等
    key=((find.arr[find.size-1]-find.arr[0])/(find.size-1))*(find.f-find.arr[0]);
    //如果相等输出位置
    if ( key == find.f && key < find.size){
        return key;
    }
    //否则返回错误
    return ERROR;
}
