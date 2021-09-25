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
//结构体
typedef struct bitmap{
    int key[MAXSIZE]; //原始数据
    int bit[8][8]; //bit
    int sort[MAXSIZE]; //排序后数据
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
    return 0;
}
//输入原始数据
struct bitmap *input(bitmap *b){
    int l;
    for (int i = 0; i < MAXSIZE; i++){
        b->key[i]=rand() % 51 + 13 ; 
        b->sort[i]=b->key[i];    
    }
    for (int j = 0; j < MAXSIZE - 1; j++){
        for (int k = 0; k < MAXSIZE - 1 -j; k++){
            if (b->sort[k]>b->sort[k+1]){
                l=b->sort[k];
                b->sort[k]=b->sort[k+1];
                b->sort[k+1]=l;    
            } 
        }
    }
    return b;
}
//创建出bitmap
struct bitmap *creat_bitmap(bitmap *creat_bit){
    int h,w,j;
    uint bit;
    bit=0200;
    for (j = 0; j < MAXSIZE; j++){
        w = creat_bit->sort[j];        
        while (w >= 0){
            w=w-8;
        }                      //根据数值得到相应的bit
        w=w+8;
        h=-(-8+w-j)/8;
        creat_bit->bit[h][w]=bit>>w;
    }        
    //创建bitmap
    for (int i = 0; i < MAXSIZE/8; i++){
        j=0;
        while (creat_bit->bit[i][j] < 0){
                j++;
            } //防止填充数影响结果
        bit=creat_bit->bit[i][j];
        for (int k = 0; k < 8; k++){
            while (creat_bit->bit[i][k] < 0){
                k++; 
            }
            bit= bit | creat_bit->bit[i][k]; //通过或得到这一列的bit值    
        }
        creat_bit->bitmap[i]=bit;
        
    }
    return creat_bit; //返回指针
}
/*
    creat map:
    1 0 0 0 0 1 1 1
    0 0 1 1 1 1 0 0
    0 1 1 1 1 1 0 1
    0 0 0 1 1 0 1 1
    0 0 0 0 1 1 1 1
    1 0 1 0 0 0 1 1
    0 1 0 0 0 1 1 0 
    0 0 1 0 1 1 0 1
*/
