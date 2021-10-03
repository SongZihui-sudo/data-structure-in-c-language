#include <iostream>
#include <vector>
//宏定义
#define OK 0
#define ERROR -1
#define true 1
//子函数
void print(struct select_sort p); //输出
int sort(struct select_sort q); //排序
void swap(int *r,int *temp); //交换元素
//结构体
typedef struct select_sort{
    std::vector<int> arr;
    int size;
}select_sort;
//主函数
int main(){
    select_sort s;
    std::cout<<"select sort!"<<"\n";
    std::cout<<"input size=";       //主函数
    std::cin>>s.size;
    int j;
    for (int i = 0; i < s.size; i++){
        std::cin>>j;          //读取输入的数据
        s.arr.push_back(j);
    }
    print(s); //输出
    sort(s);  //排序
    return 0;
}
//输出子函数
void print(struct select_sort p){
    auto b = p.arr.begin(),e = p.arr.end();
    for ( b ; b!=e; b++ ){  //利用了迭代器从第一个迭代到到最后一个
        std::cout << "data="<<*b<<"\n"; //输出数据
    }
}
//排序子函数
int sort(struct select_sort q){
    int min,k;
    int h;  //定义几个变量
    k = 0;
    for (int i = 0 ; i < q.size  ; i++){
        min  = q.arr[i]; //定义一个变量存放当前遍历到的元素
        for ( int n = i+1; n < q.size; n++){
            if ( min > q.arr[n]){ //遍历，找比该元素小的元素
                swap(&q.arr[n],&q.arr[i]); //交换，把较小的提前。
            }
        }
    }
    std::cout<<"sort:"<<"\n";
    print(q); //输出
    return OK;
}
//交换元素
void swap(int *r,int *t){
    int temp = *r;  //*r指针指向q.arr[n](较小的)，*t指向q.arr[i]较大的,利用了第三个变量先存放较小的
    *r = *t;        //把较小拷贝进较大的。（因为*r地址与q.arr[n]相同）
    *t = temp;         //较大的拷贝进较小的地址
}
