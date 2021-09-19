#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define MAXSIZE 5
#define uchar unsigned char

int print_tree();
int enable();
int add();
int del();
int find();

typedef struct tree
{
    int data;
    int size;
    struct tree *right;
    struct tree *left;
}tree;

int main(void){
    tree *father,*rightson,*leftson,*right_node,*left_node,*left_node_son,*right_node_son;
    int i,h;
    father=(tree*)malloc(sizeof(tree));
    rightson=(tree*)malloc(sizeof(tree));
    leftson=(tree*)malloc(sizeof(tree));
    printf("tree!\n");
    printf("input size=:");
    scanf("%d",&father->data);
    father->size=father->data;
    if (father->data>MAXSIZE){
        printf("ERROR!");
        return ERROR;
    }
    for (i = 0;i < father->data; i++){
        right_node=(tree*)malloc(sizeof(tree));
        right_node->data=i;   
        right_node_son=(tree*)malloc(sizeof(tree));
        right_node_son->data=i+1;
        right_node->right=right_node_son;     
        right_node->left=rightson;
        rightson=right_node;
    }
    i=0;
    for (i = 0; i <father->data; i++){
        left_node=(tree*)malloc(sizeof(tree));
        left_node->data=i;
        left_node_son=(tree*)malloc(sizeof(tree));
        left_node_son->data=i;
        left_node->left=left_node_son;
        left_node->right=leftson;
        leftson=left_node;
    } 
    father->left=rightson;
    father->right=leftson;
    print_tree(father); 
    return OK;
}

int print_tree(tree *print_father){
    printf("print tree!\n");
    for ( int i = 0; i < print_father->size; i++){
        printf("left=%d\n",print_father->left->data);        
        printf("left-son=%d\n",print_father->left->right->data);   
        print_father->left=print_father->left->left;
        print_father->left->right=print_father->left->right;
    }
    for (int i = 0; i < print_father->data; i++){
        printf("right=%d\n",print_father->right->data);        
        printf("right-son=%d\n",print_father->right->left->data);
        print_father->right=print_father->right->right;
        print_father->right->left=print_father->right->left;
    }
    return OK;
}
