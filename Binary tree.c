#include "stdio.h"
#include "stdlib.h"
//宏定义
#define OK 1//正确
#define ERROR 0//错误
#define MAXSIZE 5//最大长度
#define uchar unsigned char//uchar
#define true 1
//宏定义
int preorderoutput();//输出树枝
int print_son();//输出叶子
int find();//查找
int able();//功能选择
int add();//插入
int del();//删除节点
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
    father->left=rightson;//重新根节点的左指针指向左边树枝
    father->right=leftson;//重新根节点的右指针指向右边树枝
    father->p=0;
    able(father,rightson,leftson);
    return OK;
}
//递归方法输出树枝
int preorderoutput(tree *pre_father){  
    if (pre_father->p<pre_father->data){        
        printf("left=%d\n",pre_father->left->data);//输出
        pre_father->p++;//用变量p来结束递归
        pre_father->left=pre_father->left->left;//指针指向下一个节点
        preorderoutput(pre_father);//递归
    }
    else if (pre_father->p>=pre_father->data && pre_father->p<pre_father->data*2){
        printf("right=%d\n",pre_father->right->data);//输出
        pre_father->p++;//用变量p来结束递归
        pre_father->right=pre_father->right->right;//指针指向下一个节点        
        preorderoutput(pre_father);//递归
    }
    return OK;
}
//递归法输出叶子
int print_son(tree *son_father){
    if (son_father->p>=son_father->data*2 && son_father->p<son_father->data*3){
        printf("leftson=%d\n",son_father->left->right->data);//输出    
        son_father->p++;
        son_father->left=son_father->left->left;//树枝向下
        son_father->left->right=son_father->left->right;//指向新的叶子
        print_son(son_father);
    }
    else if(son_father->p>=son_father->data*3 && son_father->p<son_father->data*4){
        printf("rightson=%d\n",son_father->right->left->data);//输出
        son_father->p++;
        son_father->right=son_father->right->right;//树枝向下
        son_father->right->left=son_father->right->left;//指向新的叶子
        print_son(son_father);
    }
    return OK;
}
//功能选择，插入，删除，查找
int able(tree *able_father,tree *able_right,tree *able_left){
    able_father->p=0;
    uchar j;
    printf("chose!\n");
    while (true){
        scanf("%s",&j);
        if (j=='a'){//插入
            add(able_father,able_right,able_left);
            break;
        }
        else if (j=='d'){//删除
            del(able_father,able_right,able_left);
            break;
        }
        else if (j=='f'){//寻找
            find(able_father,able_right,able_left);
            break;
        }
        else{
            printf("error!\n"); //错误处理
            return ERROR; //返回错误
        }
    }
    return OK;
}
//删除函数
//只可删除树枝节点，且叶子也会被删除
int del(tree *del_father,tree *del_right,tree *del_left){
    int j,i;//变量i，j
    tree *del_r,*del_f,*q,*u;
    del_r=(tree*)malloc(sizeof(tree));//存储变量的中介，防止遍历后的数据丢失
    del_f=(tree*)malloc(sizeof(tree));//同上
    q=(tree*)malloc(sizeof(tree));//为减少->防止混乱所以建立q和u
    u=(tree*)malloc(sizeof(tree));//同上
    q=del_father->left;//q等于树的左边，减少->left的次数
    u=del_father->right;//u等于树d右边，减少->right的次数
    printf("del!\n");
    printf("input postion:");//读取输入的位置
    scanf("%d",&j);
    if (i<del_father->data){    //前一个循环左边
        for ( i = 0; i < del_father->data; i++){//0-4
            if (i==j){
                del_f->left=q->left;//把在del_f中保存的上一个节点指向下下一个树枝节点
                preorderoutput(del_father);//输出
                return OK;//返回OK
            }
            else {
                del_f=q;//在del_f中保存上一个节点
                q=q->left; //遍历指向下一个树枝节点
                }
    }
        }
    for (i ; i < del_father->data*2; i++) //后一个循环遍历右边
    {//5-9
        if (i==j){
            del_r->right=u->right;//把在del_r中保存的上一个节点，直接指向下下一个树枝节点。
            preorderoutput(del_father);//输出
        return OK;//返回OK
        }  
        else { 
            del_r=u;//在del_u中保存上一个树枝节点，防止丢失
            u=u->right; //遍历指向下一个树枝节点
        }
    }
    return OK;//返回OK
}
//插入函数。
//只可以添加树枝节点。
int add(tree *add_father, tree *add_right,tree *add_left){
    int i;
    tree *add;//新添加的节点
    add=(tree*)malloc((sizeof(tree)));//为新添加的节点分配内存空间
    int j,k;
    printf("ADD!\n");
    printf("input postion:");
    scanf("%d",&j);//读取要添加的位置
    printf("input data:");
    scanf("%d",&add->data);//读取要添加的数据
    if (j<5){
        for ( i = 0; i < j; i++){//第一个for循环寻找左边的位置
            add_father->left=add_father->left->left;//通过遍历找到要添加的位置的前序节点
        }
        add->left=add_father->left->left;//添加的节点指向前序节点
        add_father->left->left=add;//移动节点到新添加的节点
        add_father->left=add_right;//重新把右边节点连接上根节点,根节点的左连接右
        add_father->data++;//表长加一
        preorderoutput(add_father);//输出
        return OK;//返回结束循环
    }
    else if (j>=5 && j<10){
        for ( i = 0; i < 10-j; i++){//第二个for循环寻找右边的位置
            add_father->right=add_father->right->right;//通过遍历找到要添加的位置的前序节点
        }
        add->left=add_father->right->right;//添加的节点指向前序节点
        add_father->right->right=add;//移动节点到新添加的节点
        add_father->right=add_left;//重新把左节点连接上根节点，根节点的右连接左
        add_father->data++;//表长加一
        preorderoutput(add_father);//输出
        return OK;//返回OK，结束循环
    }
}
//寻找函数
int find(tree *find_father,tree *find_right,tree *find_left){
    int j,i;
    printf("print!\n");
    printf("input data:");//读入要寻找的数据
    scanf("%d",&j);
    for (i = 0; i < find_father->data; i++){//第一个for循环想寻找左边树枝
        if (j==find_father->left->data){
            printf("get!\n");
            printf("tree postion=%d\n",i);
            return OK;//返回OK结束循环
        }
        else{
            printf("not found!\n");
            find_father->left=find_father->left->left;//如果没找到就指向下一个节点
        }
    }
    for ( i ; i < 10; i++){//第二个for循环寻找右边树枝
        if (j==find_father->right->data){
            printf("get!\n");
            printf("tree postion=%d\n",i);
            return OK;//返回OK结束循环
        }
        else{
            printf("not found!");
            find_father->right=find_father->right->right;//如果没找到就指向下一个节点
        }
    }
    find_father->left=find_right;//指针回到第一位
    find_father->right=find_left;//回溯
    for ( i = 0; i < 15; i++){
        if (j==find_father->left->right->data){//第三个for循环寻找左边叶子
            printf("get!\n");
            printf("leaf postion=%d\n",i);
            return OK;//返回OK结束循环
        }
        else{
            printf("not found!\n");
            find_father->left=find_father->left->left;//如果不是就树枝指向下一个节点，比较下一个叶子。
            find_father->left->right=find_father->left->right;
        }
    }
    for ( i = 0; i < 20; i++){
        if (j==find_father->right->left->data){//第三个for循环比较右边叶子
            printf("get!\n");
            printf("leaf postion=%d\n",i);
            return OK;//返回OK结束循环
        }
        else{
            printf("not found!\n");
            find_father->right=find_father->right->right;//如果不是就指针指向下一个节点，比较下一个叶子
            find_father->right->left=find_father->right->left;
        }
    }            
    return OK;
        }
