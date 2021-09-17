#include "stdlib.h"
#include "stdio.h"

#define OK 1
#define ERROR 0
#define uchar unsigned char

int print_line();
int add();
int enable();
int del();
int find();

typedef struct link{
    struct link* next;
    int data;
}link;

int main(void){
   
    printf("Linked list!\n");
    link *head,*node,*end;
    head=(link*)malloc(sizeof(link));
    head->next=end;
    end=head;
    printf("init link!\ninput size:");
    scanf("%d",&head->data);
    for (int i = 0; i < head->data; i++){
        /* code */
        node=(link*)malloc(sizeof(link));
        //scanf("%d",&node->data);
        node->data=i;
        node->next=end;
        end=node;
    }
    print_line(head,node,end);
    enable(head,node,end);
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
            add(en_head,en_node,en_end);
            break;
        }
        else if (j=='d'){
            /* code */
            del(en_head,en_node,en_end);
            break;
        }
        else if (j=='f'){
            /* code */
            find(en_head,en_node,en_end);
            break;
        }
        else{
            printf("ERROR!\n");
            return ERROR;
        }
    }
    return OK;
}

int print_line(link *pr_head,link *pr_node,link *pr_end){
    printf("print!\n");
  //  printf("size=%d\n",pr_head->data);
    for (int i = 0; i < pr_head->data; i++)
    {
        /* code */
        printf("data=%d\n",pr_node->data);
        pr_node=pr_node->next;
    }
    return OK;
}

int add(link *add_head,link *add_node,link *add_end){
    int k,j;
    link *temp=NULL;
    //add_node=NULL;
    printf("add!\n");
    printf("postion:");
    scanf("%d",&j);
    printf("data:");
    scanf("%d",&k);
    add_head->data++;    
    add_head->data++;
    for (int i = 0; i < j; i++){
        add_end=add_end->next;
    } 
    temp=(link*)malloc(sizeof(link));
    temp->data=k;
    temp->next=add_end->next; 
    add_end->next=temp;
    print_line(add_head,add_node,temp);
    return OK;
}

int del(link *del_head,link *del_node,link *del_end){
    int j;
    link *per;
    link *q;
    q=del_end->next;
    per=(link*)malloc(sizeof(link));
    printf("delate data:");
    scanf("%d",&j);
    while (q->data!=j)
    {
        per=q;
        q=q->next;
    }
    per->next=q->next;
    print_line(del_head,per,del_end);
    del_head->data--;
}

int find(link *find_head,link *find_node,link *find_end){
    int j;
    printf("find:");
    scanf("%d",&j);
    for (int i = 0; i < find_head->data; i++)
    {
        printf("finding!\n");
        if (j==find_end->data){
            /* code */
            printf("Found!postion:%d\n",i+1);
            return OK;
        }
        else{
            printf("NOT FOUND!\n");
        }        
        find_end=find_end->next;
    }
    return OK;
}


