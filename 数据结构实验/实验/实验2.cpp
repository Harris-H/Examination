#include<stdio.h>
#include<stdlib.h>
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define LIST_INIT_SIZE  100
typedef int Status;         //Status�Ǻ��������ͣ���ֵ�Ǻ����������
struct node{            //����
    float   coeff;      //ϵ��coefficient
    int     expn;       //ָ��exponent
};
 
typedef struct Polynomial{      //����ʽ
    struct node  elem;          //����ʽԪ��
    struct Polynomial *next;    //ָ����һ������ʽ�Ľṹ��ָ��
}*PolyList;
 
//����һԪ����ʽ����
void CreatePolyn(PolyList *ha,int n)
{
    float coe;          //coe��ʾϵ��
    int   exp;          //x2��ʾָ��
    PolyList p;         //������ʱ����ʽ����
    *ha=NULL;           //����Ϊ��ʱhaָ���
 
    while(n--){
        scanf("%f%d",&coe,&exp);
        p=(PolyList)malloc(sizeof(struct Polynomial));  //��������ʽ
        p->elem.coeff=coe;                              //��ֵ�����ϵ��
        p->elem.expn=exp;                               //��ֵ�����ָ��
        p->next=*ha;        //����pָ��*ha����Ľ���
        *ha=p;              //ָ��ĸ�ֵ��ʹ��*haʼ��ָ���´�������
    }
}
 
//���һԪ����ʽ
void ShowSqList(PolyList ha)
{
    if(ha==NULL)
        printf("F(x)=0");
    else
    {
        printf("����ʽF(x)=%.0fX^(%d)",ha->elem.coeff,ha->elem.expn);
        ha=ha->next;    //��һ��
        while(ha!=NULL)
        {
            if(ha->elem.coeff>0)
                printf("+");
            printf("%.0fX^(%d)",ha->elem.coeff,ha->elem.expn);
            ha=ha->next;//��һ��
        }
    }
    printf("\n");
}
 
//ð����������
void SortPolyn(PolyList head,int n)
{
    int i,j;
    struct node temp;   //������ʱ�Ƚ������
    PolyList p1,p2;     //��������λ����ʽָ��Ƚ�ǰ��ָ����С
    for(p1=head,i=0;i<n-1;i++,p1=p1->next)
        for(p2=p1->next,j=0;j<n-i-1;j++,p2=p2->next)
            if(p1->elem.expn < p2->elem.expn) //��ָ���Ӵ�С����
            {
                temp=p2->elem;                //������Ԫ�أ�ָ���������
                p2->elem=p1->elem;
                p1->elem=temp;
            }
}
 
//����ʽ���
PolyList add(PolyList ha,PolyList hb)   //��������Ķ���ʽha,hb�������
{
    int t=0;            //tΪϵ����
    int polynsize=0;    //hc������
    PolyList p,hc=NULL; //����ʽp,hc hcΪ����ֵ
    while(ha&&hb)       //ha,hbͬʱ��Ϊ��
    {
    if(ha->elem.expn==hb->elem.expn)
    {//��ָ����ͬʱ��ϵ�����
        t=ha->elem.coeff+hb->elem.coeff;
        if(t)
        {//ϵ���Ͳ�Ϊ�㣬�����Ͷ���ʽhc������
            p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
            p->elem.coeff=t;            //��ϵ���͸�������ϵ��p->elem.coeff
            p->elem.expn=ha->elem.expn; //��ָ����������ָ��p->elem.expn
            p->next=hc;                 //����pָ��hc����Ľ���
            hc=p;                       //ָ��ĸ�ֵ��ʹhcʼ��ָ���´�������
 
            ha=ha->next;        //����ha�ĵ��β���
            hb=hb->next;        //����hb�ĵ��β���
            polynsize++;    //��ɱ��κ�hc������++
        }
        else
        {//ϵ����Ϊ�㣬��ha��hb������
            ha=ha->next;    //����ha�ĵ��β���
            hb=hb->next;    //����hb�ĵ��β���
        }
    }
    else if(ha->elem.expn>hb->elem.expn)
    {//ha��ָ���������в���hc
        p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
        p->elem=ha->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        ha=ha->next;    //����ha�ĵ��β���
        polynsize++;    //��ɱ��κ�hc������++
    }
    else
    {//hb��ָ���������в���hc
        p=(PolyList)malloc(sizeof(struct Polynomial));
        p->elem=hb->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        hb=hb->next;    //����hb�ĵ��β���
        polynsize++;    //��ɱ��κ�hc������++
    }
    }
    while(ha)
    {//ha��Ϊ�գ��򽫵�ǰhaʣ����ȫ������hc
        p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
        p->elem=ha->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        ha=ha->next;    //����ha�ĵ��β���
        polynsize++;    //��ɱ��κ�hc������++
    }
    while(hb)
    {//hb��Ϊ�գ��򽫵�ǰhbʣ����ȫ������hc
    p=(PolyList)malloc(sizeof(struct Polynomial));      //�½���
    p->elem=hb->elem;       //��hb��Ԫ�ظ�������
    p->next=hc;             //����pָ��hc����Ľ���
    hc=p;                   //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
    hb=hb->next;        //����ha�ĵ��β���
    polynsize++;        //��ɱ��κ�hc������++
    }
    SortPolyn(hc,polynsize);//����hc
return hc;
}
 
int main ()
{
    PolyList ha,hb,hc;      //����ʽha,hb,hc
    int m,n;                //����ʽha,hb������
 
    scanf("%d",&m);CreatePolyn(&ha,m);      //���벢����ha
    scanf("%d",&n);CreatePolyn(&hb,n);      //���벢����hb
    printf("\n");
 
    printf("ԭʼ��������ʽ\n");             //���ԭʼ����ʽ
    ShowSqList(ha);ShowSqList(hb);          //�����ȳ�
    printf("\n");
 
    SortPolyn(ha,m);SortPolyn(hb,n);    //����ha,hb
    printf("��ָ���Ӹߵ����������������ʽ\n");
    ShowSqList(ha);ShowSqList(hb);
    printf("\n");
 
    hc=add(ha,hb);                  //����ʽ���
    printf("�Ͷ���ʽ\n");
    ShowSqList(hc);                 //����Ͷ���ʽhc
    printf("��������ʽ\n");
    ShowSqList(ha);ShowSqList(hb);  //���ԭ����ʽ(������)
return 0;
}
 
/*
��������
��һ��ha������
�ڶ���Ϊ��i���Ӧϵ����ָ��,i++,i��1��ʼ
������hb������
������Ϊ��i���Ӧϵ����ָ��,i++,i��1��ʼ
3
1 3 2 2 4 1
4
2 2 5 1 -1 3 6 6
*/
