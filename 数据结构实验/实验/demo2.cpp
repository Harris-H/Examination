#include<stdio.h>
#include<stdlib.h>
struct node{     //����ÿһ�� 
    double   c;      //ϵ��coefficient
    int     e;       //ָ��exponent
};
 
typedef struct Polynomial{      //����ʽ
    struct node  elem;          //����ʽԪ��
    struct Polynomial *next;    //ָ����һ������ʽ�Ľṹ��ָ�� 
}*PolyList;
 
//����һԪ����ʽ����
void CreatePolyn(PolyList *ha,int n)
{
    double c1;          //coe��ʾϵ��
    int   e1;          //x2��ʾָ��
    PolyList p;         //������ʱ����ʽ����
    *ha=NULL;           //����Ϊ��ʱhaָ���
 
    while(n--){
        scanf("%lf%d",&c1,&e1);
        p=(PolyList)malloc(sizeof(struct Polynomial));  //��������ʽ
        p->elem.c=c1;                              //��ֵ�����ϵ��
        p->elem.e=e1;                               //��ֵ�����ָ��
        p->next=*ha;        //����pָ��*ha����Ľ���
        *ha=p;              //ָ��ĸ�ֵ��ʹ��*haʼ��ָ���´�������
    }
}
 
//���һԪ����ʽ
void ShowSqList(PolyList ha,char op)
{
    if(ha==NULL)
        printf("����ʽ%c: F(x)=0",op);
    else
    {
        printf("����ʽ%c: F(x)=%.0fX^(%d)",op,ha->elem.c,ha->elem.e);
        ha=ha->next;    //��һ��
        while(ha!=NULL)
        {
            if(ha->elem.c>0)
                printf("+");
            printf("%.0fX^(%d)",ha->elem.c,ha->elem.e);
            ha=ha->next;//��һ��
        }
    }
    printf("\n");
}
 
//ð����������
void SortPolyn(PolyList head,int n,int option)			//option==1 �ݼ��� option==2 ������ 
{
    int i,j;
    struct node temp;   //������ʱ�Ƚ������
    PolyList p1,p2;     //��������λ����ʽָ��Ƚ�ǰ��ָ����С
    for(p1=head,i=0;i<n-1;i++,p1=p1->next)
        for(p2=p1->next,j=0;j<n-i-1;j++,p2=p2->next)
        {
        	if(option==1){
        		if(p1->elem.e < p2->elem.e) //��ָ���Ӵ�С����
            {
                temp=p2->elem;                //������Ԫ�أ�ָ���������
                p2->elem=p1->elem;
                p1->elem=temp;
            }
			}
			else if(option==2){
				if(p1->elem.e > p2->elem.e) //��ָ����С��������
            {
                temp=p2->elem;                //������Ԫ�أ�ָ���������
                p2->elem=p1->elem;
                p1->elem=temp;
            }
			}
		}
}
 
//����ʽ���
PolyList add(PolyList ha,PolyList hb)   //��������Ķ���ʽha,hb�������
{
    int t=0;            //tΪϵ����
    int ptot=0;    //hc������
    PolyList p,hc=NULL; //����ʽp,hc hcΪ����ֵ
    while(ha&&hb)       //ha,hbͬʱ��Ϊ��
    {
    if(ha->elem.e==hb->elem.e)
    {//��ָ����ͬʱ��ϵ�����
        t=ha->elem.c+hb->elem.c;
        if(t)
        {//ϵ���Ͳ�Ϊ�㣬�����Ͷ���ʽhc������
            p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
            p->elem.c=t;            //��ϵ���͸�������ϵ��p->elem.coeff
            p->elem.e=ha->elem.e; //��ָ����������ָ��p->elem.expn
            p->next=hc;                 //����pָ��hc����Ľ���
            hc=p;                       //ָ��ĸ�ֵ��ʹhcʼ��ָ���´�������
 
            ha=ha->next;        //����ha�ĵ��β���
            hb=hb->next;        //����hb�ĵ��β���
            ptot++;    //��ɱ��κ�hc������++
        }
        else
        {//ϵ����Ϊ�㣬��ha��hb������
            ha=ha->next;    //����ha�ĵ��β���
            hb=hb->next;    //����hb�ĵ��β���
        }
    }
    else if(ha->elem.e>hb->elem.e)
    {//ha��ָ���������в���hc
        p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
        p->elem=ha->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        ha=ha->next;    //����ha�ĵ��β���
        ptot++;    //��ɱ��κ�hc������++
    }
    else
    {//hb��ָ���������в���hc
        p=(PolyList)malloc(sizeof(struct Polynomial));
        p->elem=hb->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        hb=hb->next;    //����hb�ĵ��β���
        ptot++;    //��ɱ��κ�hc������++
    }
    }
    while(ha)
    {//ha��Ϊ�գ��򽫵�ǰhaʣ����ȫ������hc
        p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
        p->elem=ha->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        ha=ha->next;    //����ha�ĵ��β���
        ptot++;    //��ɱ��κ�hc������++
    }
    while(hb)
    {//hb��Ϊ�գ��򽫵�ǰhbʣ����ȫ������hc
    p=(PolyList)malloc(sizeof(struct Polynomial));      //�½���
    p->elem=hb->elem;       //��hb��Ԫ�ظ�������
    p->next=hc;             //����pָ��hc����Ľ���
    hc=p;                   //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
    hb=hb->next;        //����ha�ĵ��β���
    ptot++;        //��ɱ��κ�hc������++
    }
    SortPolyn(hc,ptot,2);//����hc
return hc;
}



PolyList Sub(PolyList ha,PolyList hb)   //��������Ķ���ʽha,hb�������
{
    int t=0;            //tΪϵ����
    int ptot=0;    //hc������
    PolyList p,hc=NULL; //����ʽp,hc hcΪ����ֵ
    while(ha&&hb)       //ha,hbͬʱ��Ϊ��
    {
    if(ha->elem.e==hb->elem.e)
    {//��ָ����ͬʱ��ϵ�����
        t=ha->elem.c-hb->elem.c;
        if(t)
        {//ϵ���Ͳ�Ϊ�㣬�����Ͷ���ʽhc������
            p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
            p->elem.c=t;            //��ϵ���͸�������ϵ��p->elem.coeff
            p->elem.e=ha->elem.e; //��ָ����������ָ��p->elem.expn
            p->next=hc;                 //����pָ��hc����Ľ���
            hc=p;                       //ָ��ĸ�ֵ��ʹhcʼ��ָ���´�������
 
            ha=ha->next;        //����ha�ĵ��β���
            hb=hb->next;        //����hb�ĵ��β���
            ptot++;    //��ɱ��κ�hc������++
        }
        else
        {//ϵ����Ϊ�㣬��ha��hb������
            ha=ha->next;    //����ha�ĵ��β���
            hb=hb->next;    //����hb�ĵ��β���
        }
    }
    else if(ha->elem.e>hb->elem.e)
    {//ha��ָ���������в���hc
        p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
        p->elem=ha->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        ha=ha->next;    //����ha�ĵ��β���
        ptot++;    //��ɱ��κ�hc������++
    }
    else
    {//hb��ָ���������в���hc
        p=(PolyList)malloc(sizeof(struct Polynomial));
        hb->elem.c=-(hb->elem.c);
        p->elem=(hb->elem);   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        hb=hb->next;    //����hb�ĵ��β���
        ptot++;    //��ɱ��κ�hc������++
    }
    }
    while(ha)
    {//ha��Ϊ�գ��򽫵�ǰhaʣ����ȫ������hc
        p=(PolyList)malloc(sizeof(struct Polynomial));  //�½���
        p->elem=ha->elem;   //��ha��Ԫ�ظ�������
        p->next=hc;         //����pָ��hc����Ľ���
        hc=p;               //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
        ha=ha->next;    //����ha�ĵ��β���
        ptot++;    //��ɱ��κ�hc������++
    }
    while(hb)
    {//hb��Ϊ�գ��򽫵�ǰhbʣ����ȫ������hc
    p=(PolyList)malloc(sizeof(struct Polynomial));      //�½���
    hb->elem.c=-(hb->elem.c);
    p->elem=(hb->elem);       //��hb��Ԫ�ظ�������
    p->next=hc;             //����pָ��hc����Ľ���
    hc=p;                   //ָ��ĸ�ֵ��ʹ��hcʼ��ָ���´�������
 
    hb=hb->next;        //����ha�ĵ��β���
    ptot++;        //��ɱ��κ�hc������++
    }
    SortPolyn(hc,ptot,2);//����hc
return hc;
}
int main ()
{
    PolyList ha,hb,hc,hd;      //����ʽha,hb,hc
    int m,n;                //����ʽha,hb������
 	printf("���������ʽA�Ͷ���ʽB�������Ͷ�Ӧ��ϵ��,ָ��:\n"); 
    scanf("%d",&m);CreatePolyn(&ha,m);      //���벢����ha
    scanf("%d",&n);CreatePolyn(&hb,n);      //���벢����hb
    printf("\n");
 
    printf("ԭʼ��������ʽA �� B\n");             //���ԭʼ����ʽ
    ShowSqList(ha,'A');ShowSqList(hb,'B');          //�����ȳ�
    printf("\n");
 
    SortPolyn(ha,m,2);SortPolyn(hb,n,2);    //����ha,hb
    printf("��ָ����С�����������������ʽ\n");
    ShowSqList(ha,'A');ShowSqList(hb,'B');
    printf("\n");
 
    hc=add(ha,hb);                  //����ʽ���
    printf("�Ͷ���ʽ\n");
    ShowSqList(hc,'C');  
    printf("-------------------------------\n");
	printf("�����ʽ\n"); 
    hd=Sub(ha,hb);
    ShowSqList(hd,'D');                 //����Ͷ���ʽhc
    printf("\n\n");
    printf("��������ʽ\n");
    ShowSqList(ha,'A');ShowSqList(hb,'B');  //���ԭ����ʽ(������)
return 0;
}
 
/*
��������
��һ��ha������
�ڶ���Ϊ��i���Ӧϵ����ָ��,i++,i��1��ʼ
������hb������
������Ϊ��i���Ӧϵ����ָ��,i++,i��1��ʼ
4 
1 3 2 2 4 1 5 8 
4 
2 2 5 1 -1 3 6 6 
*/
