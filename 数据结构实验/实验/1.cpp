#include<stdio.h> /// no have head node  ha and hb >>ha
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
 
LinkList CreateLink(int sz)  /// 创建一个链表
{
    LinkList h=(LinkList)malloc(sizeof(LNode)),q;
    scanf("%d",&h->data);
    h->next=NULL;
    q=h;
    for(int i=1;i<sz;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=NULL;
 
        q->next=p;
        q=p;
    }
    return h;  /// 返回头指针
}
void print(LinkList h);
LinkList MergeList(LinkList ha,LinkList hb)
{
    LinkList tmp,hnew,pnew;
    tmp=(LinkList)malloc(sizeof(LNode));
    tmp->next=NULL;
 
    hnew=pnew=tmp;
    while(ha&&hb)
    {
        if(ha->data < hb->data){
            tmp=(LinkList)malloc(sizeof(LNode));	//创建一个新结点 
            tmp->next=NULL;	
            tmp->data=ha->data;
            pnew->next=tmp;pnew=tmp;ha=ha->next;
        }
        else if(ha->data > hb->data){
            tmp=(LinkList)malloc(sizeof(LNode));	//创建一个新结点 
            tmp->next=NULL;
            tmp->data=hb->data;
 
            pnew->next=tmp;pnew=tmp;hb=hb->next;
        }
        else{
            hb=hb->next; /// ha中有hb的元素，hb直接指向下一结点
        }
    }
    pnew->next=ha?ha:hb;  ///  指向剩余的链表
 
    return hnew->next;    /// 返回无头结点的指针
}
void Print_fun(LinkList h)
{
 
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
 
int main()
{
    int n,m;
    printf("请输入链表ha的元素个数和对应的数据:\n"); 
    scanf("%d",&n);   ///ha
    LinkList ha=CreateLink(n);
 	printf("请输入链表hb的元素个数和对应的数据:\n"); 
    scanf("%d",&m);    ///hb
    LinkList hb=CreateLink(m);
    printf("\n在合并链表之前:\n");
    printf("ha链表:  "); Print_fun(ha);
    printf("hb链表:  "); Print_fun(hb); 
    LinkList hc=MergeList(ha,hb);
    printf("\n在合并链表之后:\n");
    printf("hc链表:  ");Print_fun(hc);
    printf("ha链表:  ");Print_fun(ha);
    printf("hb链表:  ");Print_fun(hb);
    return 0;
}
 
/**
6 
1 3 4 5 7  8 
5
2 5 6 7 10 
*/
