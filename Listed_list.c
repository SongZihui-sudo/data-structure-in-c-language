#include "stdlib.h"
#include "stdio.h"

#define OK 1
#define ERROR 0
#define uchar unsigned char
//子函数
int print_line();
int add();
int enable();
int del();
int find();
//定义链表结构体
typedef struct link{
    struct link* next;
    int data;
}link;
//主函数
int main(void){
    printf("Linked list!\n");
    link *head,*node,*end;//头指针，普通指针，尾指针
    head=(link*)malloc(sizeof(link));//创建尾指针
    head->next=end;//刚开始只有一个头指针，头指针也是尾指针，指向尾指针
    end=head;
    printf("init link!\ninput size:");
    scanf("%d",&head->data);//表长存入头指针
    for (int i = 0; i < head->data; i++){
        /* code */
        node=(link*)malloc(sizeof(link));//创建普通指针
        //scanf("%d",&node->data);
        node->data=i;//赋值
        node->next=end;//尾指针后移
        end=node;
    }
    print_line(head,node,end);//输出
    enable(head,node,end);//功能选择
    return OK;
}
int enable(link *en_head,link *en_node,link *en_end){
    while (1){
        /* code */ 
        uchar j;
        printf("chose!\n");
        scanf("%s",&j);
        if (j=='a'){
            /* code */
            add(en_head,en_node,en_end);//插入
            break;
        }
        else if (j=='d'){
            /* code */
            del(en_head,en_node,en_end);//删除
            break;
        }
        else if (j=='f'){
            /* code */
            find(en_head,en_node,en_end);//寻找
            break;
        }
        else{
            printf("ERROR!\n");//错误处理
            return ERROR;
        }
    }
    return OK;
}
//输出
int print_line(link *pr_head,link *pr_node,link *pr_end){
    printf("print!\n");
  //  printf("size=%d\n",pr_head->data);
    for (int i = 0; i < pr_head->data; i++)
    {
        printf("data=%d\n",pr_node->data);//输出普通节点的数据域。
        pr_node=pr_node->next;//遍历链表输出，普通节点指针依次指向下一个
    }
    return OK;
}
//插入
int add(link *add_head,link *add_node,link *add_end){
    int k,j;
    link *temp=NULL;
    //add_node=NULL;
    printf("add!\n");
    printf("postion:");
    scanf("%d",&j);//读取要插入的位置
    printf("data:");
    scanf("%d",&k);//读入要插入的数据
    add_head->data++;//表长加一
    add_head->data++;//表长加一，输出头节点的表长值。
    for (int i = 0; i < j; i++){
        add_end=add_end->next;//遍历
    }//找出要插入的前一个结点 
    temp=(link*)malloc(sizeof(link));//创建新节点
    temp->data=k;//新节点赋值
    temp->next=add_end->next;//新节点指向上一个节点 
    add_end->next=temp;//插入
    print_line(add_head,add_node,temp);//输出新链表
    return OK;
}
//删除
int del(link *del_head,link *del_node,link *del_end){
    int j;
    link *per;
    link *q;
    q=del_end->next;//前一个节点
    per=(link*)malloc(sizeof(link));//分配内存空间
    printf("delate data:");
    scanf("%d",&j);//读取要删掉的节点
    while (q->data!=j)
    {
        per=q;
        q=q->next;//遍历链表，寻找要删掉的节点。
    }
    per->next=q->next;//如果找到要删除的节点，指向这个节点的下一个节点。
    print_line(del_head,per,del_end);
    del_head->data--;
    return OK;
}
//寻找
int find(link *find_head,link *find_node,link *find_end){
    int j;
    printf("find:");
    scanf("%d",&j);//读取要寻找的节点
    for (int i = 0; i < find_head->data; i++)
    {
        printf("finding!\n");
        if (j==find_end->data){//遍历链表，进行寻找。
            /* code */
            printf("Found!postion:%d\n",i+1);//输出位置
            return OK;
        }
        else{
            printf("NOT FOUND!\n");//错误处理
        }        
        find_end=find_end->next;//遍历循环
    }
    return OK;
}
