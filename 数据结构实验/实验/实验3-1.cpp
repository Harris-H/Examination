///����һ��������������ö�̬���������з����������þ�̬���������ʾ��
///�������Ķ�̬��������ṹ�е�ÿ������������ֶΣ�data��lchild��rchild��
///��̬������������������Ϊ�洢�ռ䣬ÿ������Ԫ�ش洢��������һ����㣬
///Ҳ�������ֶΣ�data��lchild��rchild��lchild��rdhild�ֱ����ڴ洢���Һ��ӵ��±ꡣ
///�����ͱ����ò���ǰ�����򡢺���Ͳ�α����е�2��
#include<stdio.h>
#include<stdlib.h>
#define MAX 7
using namespace std;
typedef struct node///���ṹ
{
    char data;///������
    struct node *lchild;///����ָ��
    struct node *rchild;///�Һ���ָ��
}BiTNode,*BiTree;///���н������
typedef struct BiTNode_s///���ṹ
{
    char data;
    int lchild;///�����±�
    int rchild;///�Һ����±�
}BiTNode_s,*BiTree_s;
int i=0;
 
///ǰ�򷨹���������
void PreCreatBiTree(BiTree&T)
{
    ///�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
    char ch;///����ֵ
    if((ch=getchar())=='*')///��*��ʾ��
        T=NULL;///�ݹ������������
    else
    {
        T=(BiTNode *)malloc(sizeof(BiTNode));///�����µĿռ�
        T->data=ch;///���ɸ���㸳ֵ
        PreCreatBiTree(T->lchild);///�ݹ鴴��������
        PreCreatBiTree(T->rchild);///�ݹ鴴��������
    }
}
 
 
///ǰ�������������
void PreTravel(BiTree &T)
{
    if(T)
    {
        printf("%c ",T->data);///��
        PreTravel(T->lchild);///��������
        PreTravel(T->rchild);///��������
    }
}
///���������������
void MidTravel(BiTree&T)
{
    if(T)
    {
        MidTravel(T->lchild);
        printf("%c ",T->data);
        MidTravel(T->rchild);
    }
}
///���������������
void AftTravel(BiTree &T)
{
    if(T)
    {
        AftTravel(T->lchild);
        AftTravel(T->rchild);
        printf("%c ",T->data);
    }
}
 
void LevelTravel(BiTree &T){
	BiTree Queue[MAX],b;
    ///��һά�����ʾ���У�front��rear�ֱ��ʾ���׺Ͷ�βָ��
    int front,rear;
    front=rear=0;
    if(T) ///�����ǿ�
    {
        Queue[rear++]=T;///����������
        while(front!=rear) ///�����зǿ�
        {
            b=Queue[front++];///����Ԫ�س����У�������������
            printf("%c ",b->data);
            if(b->lchild!=NULL)
            {
                Queue[rear++]=b->lchild;
                ///�������ǿգ��������

            }
            if(b->rchild!=NULL)
            {
                Queue[rear++]=b->rchild;
                ///�������ǿգ��������
            }
        }
    }
} 
///����̬������ת��Ϊ�þ�̬��������
void TreeToArray(BiTree &T,BiTNode_s a[])
{
    int k;
    a[i].data=T->data;
    k=i;///k���ڼ�¼�ݹ���õ�ÿһ��˽���Ӧ�������±�,i������ͱ���ʼ��Ϊ0
    if(T->lchild)
    {
        i++;
        a[k].lchild=i;///�����ӽ���Ӧ���±긳��˫�׽��
        TreeToArray(T->lchild,a);///�ݹ����Tree_to_Array����
    }
    else
        a[k].lchild=-1;///û�����ӽ��
    if(T->rchild)
    {
        i++;
        a[k].rchild=i;///���Һ��ӽ���Ӧ���±긳��˫�׽���rcjild
        TreeToArray(T->rchild,a);///�ݹ����Tree_to_Array����
    }
    else
        a[k].rchild=-1;///û���Һ��ӽ��
}
 
int main()
{
    int j;
    BiTree T;
    BiTNode_s a[MAX];
    printf("�밴�������˳������������ĸ��ڵ㣬û�е��÷���*���棺\n");
    PreCreatBiTree(T);
    printf("ǰ����������\n");
    PreTravel(T);
    printf("\n");
    printf("������������\n");
    MidTravel(T);
    printf("\n");
    printf("������������\n");
    AftTravel(T);
    printf("\n");
    printf("��α��������\n");
    LevelTravel(T);
    printf("\n");
    TreeToArray(T,a);
    printf("ת���ɾ�̬��������Ϊ��\n");
    printf("�����   �����ĸ   ����   �Һ���\n");
    for(j=0;j<MAX;j++){
		
        printf("%5d %10c",j,a[j].data);
        if(a[j].lchild==-1) printf(" %8c",'*');
        else printf(" %8d",a[j].lchild);
        if(a[j].rchild==-1) printf(" %8c",'*');
        else printf(" %8d",a[j].rchild);
        printf("\n");
	}
    return 0;
}
//ABD**E**CF**G**
 //ABC**DE*G**F***
///ABCD***E**FG*H***
