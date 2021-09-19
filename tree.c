#include "stdio.h"
#include "stdlib.h"
//宏定义
#define OK 1//正确
#define ERROR 0//错误
#define MAXSIZE 5//最大长度
#define uchar unsigned char//uchar
#define true 1
//宏定义
int print_tree();//输出
int preorderoutput();
int print_son();
//三叉链表结构体
typedef struct tree
{
    int p;
    int data;//数据域
    struct tree *right;//右指针
    struct tree *left;//左指针
}tree;
//变量p
//主函数
int main(void){
    int i,h;    
    //根节点，右遍头节点，左边头节点，右边普通节点，左边普通节点，右边叶子，左边叶子
    tree *father,*rightson,*leftson,*right_node,*left_node,*left_node_son,*right_node_son;
    father=(tree*)malloc(sizeof(tree));//创建根节点
    rightson=(tree*)malloc(sizeof(tree));//创建右遍头节点
    leftson=(tree*)malloc(sizeof(tree));//创建左边头节点
    father->p=0;
    printf("tree!\n");
    printf("input size=:");//输入树的大小
    scanf("%d",&father->data);//把树的大小存入根节点数据域
    if (father->data>MAXSIZE){//错误处理，输入大于最大长度
        printf("ERROR!");
        return ERROR;//返回错误
    }
    for (i = 0;i < father->data; i++){
        right_node=(tree*)malloc(sizeof(tree));//创建右遍的树枝
        right_node->data=i;//赋值
        right_node_son=(tree*)malloc(sizeof(tree));//创建一个叶子
        right_node_son->data=i+1;//给叶子赋值
        right_node->right=right_node_son;//树枝的右指针指向叶子 
        right_node->left=rightson;//指向树枝的下一个节点
        rightson=right_node;
    }
    i=0;
    for (i = 0; i <father->data; i++){
        left_node=(tree*)malloc(sizeof(tree));//创建左边树枝
        left_node->data=i+3;//赋值
        left_node_son=(tree*)malloc(sizeof(tree));//创建一个叶子
        left_node_son->data=i+2;//给叶子赋值
        left_node->left=left_node_son;//树枝的左边指针指向叶子
        left_node->right=leftson;//指向树枝的下一个节点
        leftson=left_node;
    } 
    father->left=rightson;//根节点的左指针指向左边树枝
    father->right=leftson;//根节点的右指针指向右边树枝
    preorderoutput(father);
    father->left=rightson;//重新根节点的左指针指向左边树枝
    father->right=leftson;//重新根节点的右指针指向右边树枝
    print_son(father);
    return OK;
}
//递归方法输出树枝
int preorderoutput(tree *pre_father){  
    printf("print!\n");
    pre_father->p++;//用变量p来结束递归
    if (pre_father->p<5){        
        printf("left=%d\n",pre_father->left->data);//输出
        pre_father->left=pre_father->left->left;//指针指向下一个节点
        preorderoutput(pre_father);//递归
    }
    else if (pre_father->p>=5 && pre_father->p<10){
        printf("right=%d\n",pre_father->right->data);//输出
        pre_father->right=pre_father->right->right;//指针指向下一个节点        
        preorderoutput(pre_father);//递归
    }
    return OK;
}
//递归法输出叶子
int print_son(tree *son_father){
    printf("print!\n");
    son_father->p++;
    if (son_father->p>=10 && son_father->p<15){
        printf("leftson=%d\n",son_father->left->right->data);//输出
        son_father->left=son_father->left->left;//树枝向下
        son_father->left->right=son_father->left->right;//指向新的叶子
        print_son(son_father);
    }
    else if(son_father->p>=15 && son_father->p<20){
        printf("rightson=%d\n",son_father->right->left->data);//输出
        son_father->right=son_father->right->right;//树枝向下
        son_father->right->left=son_father->right->left;//指向新的叶子
    }
    return OK;
}
   
