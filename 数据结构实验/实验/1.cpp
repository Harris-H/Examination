#include<stdio.h> /// no have head node  ha and hb >>ha
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
 
LinkList CreateLink(int sz)  /// ����һ������
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
    return h;  /// ����ͷָ��
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
            tmp=(LinkList)malloc(sizeof(LNode));	//����һ���½�� 
            tmp->next=NULL;	
            tmp->data=ha->data;
            pnew->next=tmp;pnew=tmp;ha=ha->next;
        }
        else if(ha->data > hb->data){
            tmp=(LinkList)malloc(sizeof(LNode));	//����һ���½�� 
            tmp->next=NULL;
            tmp->data=hb->data;
 
            pnew->next=tmp;pnew=tmp;hb=hb->next;
        }
        else{
            hb=hb->next; /// ha����hb��Ԫ�أ�hbֱ��ָ����һ���
        }
    }
    pnew->next=ha?ha:hb;  ///  ָ��ʣ�������
 
    return hnew->next;    /// ������ͷ����ָ��
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
    printf("����������ha��Ԫ�ظ����Ͷ�Ӧ������:\n"); 
    scanf("%d",&n);   ///ha
    LinkList ha=CreateLink(n);
 	printf("����������hb��Ԫ�ظ����Ͷ�Ӧ������:\n"); 
    scanf("%d",&m);    ///hb
    LinkList hb=CreateLink(m);
    printf("\n�ںϲ�����֮ǰ:\n");
    printf("ha����:  "); Print_fun(ha);
    printf("hb����:  "); Print_fun(hb); 
    LinkList hc=MergeList(ha,hb);
    printf("\n�ںϲ�����֮��:\n");
    printf("hc����:  ");Print_fun(hc);
    printf("ha����:  ");Print_fun(ha);
    printf("hb����:  ");Print_fun(hb);
    return 0;
}
 
/**
6 
1 3 4 5 7  8 
5
2 5 6 7 10 
*/
