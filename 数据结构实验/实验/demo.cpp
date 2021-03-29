#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
LinkList CreateLink(int n)  //�������� 
{
    LinkList h=(LinkList)malloc(sizeof(LNode)),q;
    scanf("%d",&h->data);	//�����������data	
    h->next=NULL;	//��ʼ�� 
    q=h;
    for(int i=1;i<n;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return h;  /// ����ͷָ��
}
void MergeList(LinkList ha,LinkList hb,LinkList & hc)	//�ϲ�����ha,hb 
{
    LinkList p,pb,pc;
    //hc �������ͷָ�� 
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
        else{	//����ha Ԫ�غ�hb ������ͬ,��hb�����ݲ��鲢��ha�� 
            hb=hb->next; 
        }
    }
    pc->next=ha?ha:hb;  ///  ָ��ʣ�������
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
