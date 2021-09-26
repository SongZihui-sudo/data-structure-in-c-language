#include "stdlib.h"
#include "stdio.h"
//宏定义
#define OK 0
#define ERROR 1
#define uchar unsigned char
#define uint unsigned int
#define MAXSIZE 64
#define mapsize 8
//两个字函数
struct bitmap *input(); //输入数值
struct bitmap *creat_bitmap(); //创建bitmap
int find();//查找
//结构体
typedef struct bitmap{
    int key[MAXSIZE]; //原始数据
    int bitmap[mapsize]; //bitmap
}bitmap;
/*
    bitmap:
    0  1  2  3  4  5  6  7  
    8  9  10 11 12 13 14 15
    16 17 18 19 20 21 22 23
    24 25 26 27 28 29 30 31 
    32 33 34 35 36 37 38 39
    40 41 42 43 44 45 46 47
    48 49 50 51 52 53 54 55
    56 57 58 59 60 61 62 63
*/
int main(){
    printf("Bitmap!\n");
    bitmap *bit;
    bit=(bitmap*)malloc(sizeof(bitmap)); //分配相应内存空间
    input(bit); //输入数据
    creat_bitmap(bit);//建表
    find(bit);
    return 0;
}
//输入原始数据
struct bitmap *input(bitmap *b){
    int l;
    for (int i = 0; i < MAXSIZE; i++){
        b->key[i]=rand() % 51 + 13 ; 
    }
    for (int j = 0; j < MAXSIZE - 1; j++){
        for (int k = 0; k < MAXSIZE - 1 -j; k++){
            if (b->key[k]>b->key[k+1]){
                l=b->key[k];
                b->key[k]=b->key[k+1];
                b->key[k+1]=l;    
            } 
        }
    }
    return b;
}
//创建出bitmap
struct bitmap *creat_bitmap(bitmap *creat_bit){
    int h,w,j; 
    int k;
    uint bit;
    bit=0200;
    for (int i = 0; i < 8; i++){
        creat_bit->bitmap[i] = 0;
    } //先赋初值 00000000
    //建表
    for (j = 0; j < MAXSIZE; j++){
        w = creat_bit->key[j];  
        k=0;      
        while (w >= 0){
            w=w-8; //确定水平方向位置
            k++;
        }                      //根据数值得到相应的bit
        w=w+8;
        //h=-(-8+w-j)/8; //确定确定数值方向位置
        h=k-1;
        creat_bit->bitmap[h]= creat_bit->bitmap[h] | bit>>w;
    }    
    //输出bitmap    
    for ( int i = 0; i < 8; i++)    {
        printf("bitmap=%d\n",creat_bit->bitmap[i]);
    }
    
    return creat_bit; //返回指针
}
//查找
int find(bitmap *find_bit){
    int j,w,h;
    printf("find!\ninput data:");
    scanf("%d",&j); //读入要查找的数据
    if (j >= MAXSIZE){
        printf("ERROR!\n"); //错误处理，超出容量
        return ERROR;
    }
    w=j;
    h=0;
    while (w>=0){
        w=w-8;
        h++; //计算出要查找的数据在bitmap中的位置
    }
    w=w+8;
    h=h-1;
    if (find_bit->bitmap[h]<<w & 128){ //判断该位置在移位后是一还是零
        printf("find!\n");    //是一则输出位置
        printf("postion is:%d\n",j);
        return j;
    }
    else{
        printf("not found\n"); //否则没有找到，不存在
        return ERROR;
    }
}


