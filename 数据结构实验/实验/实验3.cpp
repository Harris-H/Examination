#include<stdio.h>
#include<stdlib.h>
//�������״̬����
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
 
#define MAX_StaticTree  100
typedef int Status;         //Status�Ǻ��������ͣ���ֵ�Ǻ����������
typedef char TElemType;     //������������Ͷ���Ϊchar��
 
//------�������Ķ�������洢��ʾ-------
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild; //���Һ���ָ�룬ָ���ӽ��
    int index;                      //���򴴽�ʱ�ı��
}BiTNode,*BiTree;                   //�ṹ�������ԭ�ͺ�ָ����
 
//------������洢�ľ�̬���洢��ʾ-----
typedef struct static_BiTNode
{
    TElemType data;
    int lchild,rchild;   //lchild��rdhild�ֱ����ڴ洢���Һ��ӵ��±ꡣ
}static_BiTNode;
 
 
//------���������ĺ���ԭ��˵��------
static int counts=0;     //���ڸ������
Status CreateBiTree(BiTree *T);
    //�������������������н���ֵ(һ���ַ�),#�ַ���ʾ������
    //������������ʾ�Ķ�����T��
Status PrintElement(TElemType e);
    //��򵥵�Visit����
    //���Ԫ��e��ֵ
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�
    //һ��Visit()ʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�
    //һ��Visit()ʧ�ܣ������ʧ��
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�
    //һ��Visit()ʧ�ܣ������ʧ��
Status LevelOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T����ÿ�������ú���Visitһ���ҽ�һ�Ρ�
    //һ��Visit()ʧ�ܣ������ʧ��
int LevelSub(BiTree T, int level,Status (*Visit)(TElemType e));
    //�������ݹ麯��
Status TreeToArray(BiTree T,static_BiTNode t[]);
    //����̬������ת��Ϊ��̬��������
    //��������������ţ�lchild��rdhild�ֱ����ڴ洢���Һ��ӵ��±�
 
int main()
{
    BiTree T;
    static_BiTNode  a[MAX_StaticTree];//��̬������������������Ϊ�洢�ռ�
    CreateBiTree(&T);           //����������
 
    printf("����");
    PreOrderTraverse (T,PrintElement);printf("\n");
    printf("����");
    InOrderTraverse(T,PrintElement);printf("\n");
    printf("����");
    PostOrderTraverse(T,PrintElement);printf("\n");
    printf("����");
    LevelOrderTraverse(T,PrintElement);printf("\n");
 
    TreeToArray(T,a);       //��̬ת��̬
    printf("��̬��������Ϊ��\n");   //�������ʽ
    printf("counts\tdata\tlchild\trchild\t\n");
    int m;
    for(m=0;m<counts;m++)       //counts���ڸ������
        printf("%d\t%c\t%d\t%d\n",m,a[m].data,a[m].lchild,a[m].rchild);
return 0;
}
 
//------���������ĺ���ʵ��------
Status CreateBiTree(BiTree *T){
    //�������������������еĽ���ֵ(һ���ַ�)��#�ַ���ʾ������
    //������������ʾ�Ķ�����T��
    //ע�⣺Ҷ�ӽ���Ҫ��������#����ʾ����������Ϊ��
    char ch;scanf("%c",&ch);
    if(ch == '#')   *T = NULL;
    else{
        if (!(*T = (BiTNode *)malloc(sizeof(BiTNode))))  exit(OVERFLOW);
        (*T)->data = ch;            //���ɸ����
        (*T)->index= counts++;      //�������
        CreateBiTree(&(*T)->lchild);//����������
        CreateBiTree(&(*T)->rchild);//����������
    }
    return OK;
}
 
Status PrintElement(TElemType e){//���Ԫ��e��ֵ
    printf("%c",e);
    return OK;
}
 
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    if (T){//DLR
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild,Visit))
                if (PreOrderTraverse(T->rchild,Visit))  return OK;
        return ERROR;
    }else return OK;
}
 
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    if (T){//LDR
        if (InOrderTraverse(T->lchild,Visit))
            if (Visit(T->data))
                if (InOrderTraverse(T->rchild,Visit))  return OK;
        return ERROR;
    }else return OK;
}
 
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    if (T){//LRD
        if (PostOrderTraverse(T->lchild,Visit))
            if (PostOrderTraverse(T->rchild,Visit))
                if (Visit(T->data)) return OK;
        return ERROR;
    }else return OK;
}
 
Status LevelOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //���ö�������洢��ʽ��Visit�ǶԽ�������Ӧ�ú�����
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    int i = 0;
    for (i=1; ;i++) {//�ӵ�1�㿪ʼ����
        if (!LevelSub(T, i,Visit))//����ʧ�ܾ�����ѭ��
            break;
    }
    return OK;
}
 
int LevelSub(BiTree T, int level,Status (*Visit)(TElemType e)){
	if (!T || level<1)  //�����Ϊ�ջ��߲��С��1�ͱ���ʧ��
		return 0;       //����ʧ�ܷ���0
	if (level==1) {     //��ε���1�ͷ����������
		Visit(T->data); //���������
		return 1;
	}//���������ݹ�
	return LevelSub(T->lchild,level-1,Visit) + LevelSub(T->rchild,level-1,Visit);
}
 
static int num=0;//����ת��Ϊ��̬����
Status TreeToArray(BiTree T,static_BiTNode t[]){
    t[num].data=T->data;                //���ݸ�ֵ
    if (T->lchild==NULL)    //����Ϊ������-1
        t[num].lchild=-1;
    else
        t[num].lchild=T->lchild->index;
 
    if (T->rchild==NULL)    //�Һ���Ϊ������-1
        t[num].rchild=-1;
    else
        t[num].rchild=T->rchild->index;
 
    num++;
 
    if (T->lchild!=NULL)    //���Ӳ�����ݹ�
        TreeToArray(T->lchild,&t[0]);
    if (T->rchild!=NULL)    //�Һ��Ӳ�����ݹ�
        TreeToArray(T->rchild,&t[0]);
return OK;
}
 
/*
��������(P129ͼ6.9)
-+a##*b##-c##d##/e##f##
*/
 
 
