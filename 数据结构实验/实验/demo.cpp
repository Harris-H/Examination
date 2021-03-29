#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
LinkList CreateLink(int n)  //创建链表 
{
    LinkList h=(LinkList)malloc(sizeof(LNode)),q;
    scanf("%d",&h->data);	//输入表中数据data	
    h->next=NULL;	//初始化 
    q=h;
    for(int i=1;i<n;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return h;  /// 返回头指针
}
void MergeList(LinkList ha,LinkList hb,LinkList & hc)	//合并链表ha,hb 
{
    LinkList p,pb,pc;
    //hc 新链表的头指针 
    p=(LinkList)malloc(sizeof(LNode));
    p->next=NULL;
    hc=pc=p;
    while(ha&&hb)
    {
        if(ha->data < hb->data){
        	p=(LinkList)malloc(sizeof(LNode));
        	p->next=NULL,p->data=ha->data;
            pc->next=p;pc=p;ha=ha->next;
        }
        else if(ha->data > hb->data){
        	p=(LinkList)malloc(sizeof(LNode));
        	p->next=NULL,p->data=hb->data;
            pc->next=p;pc=p;hb=hb->next;
        }
        else{	//出现ha 元素和hb 数据相同,则hb的数据不归并到ha中 
            hb=hb->next; 
        }
    }
    pc->next=ha?ha:hb;  ///  指向剩余的链表
    hc=hc->next;
}
void Print(LinkList h)
{
 
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
int main(){
	int n,m;
    scanf("%d",&n);   ///ha
    LinkList ha=CreateLink(n);
 
    scanf("%d",&m);    ///hb
    LinkList hb=CreateLink(m);
    printf("\nBefore MergeList\n");
    Print(ha);
    Print(hb);
    LinkList hc=(LinkList)malloc(sizeof(LNode));
   // printf("hb.data=%d\n",hb->data);
    MergeList(ha,hb,hc);
 //	printf("hb.data=%d\n",hb->data);
    printf("After MergeList\n");
    Print(hc);
    Print(hb);
 
    return 0;
} 
