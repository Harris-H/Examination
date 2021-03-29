#include<stdio.h>
#include<stdlib.h>
//函数结果状态代码
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
 
#define MAX_StaticTree  100
typedef int Status;         //Status是函数的类型，其值是函数结果代码
typedef char TElemType;     //树结点数据类型定义为char型
 
//------二叉树的二叉链表存储表示-------
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild; //左右孩子指针，指向孩子结点
    int index;                      //先序创建时的标号
}BiTNode,*BiTree;                   //结构体变量，原型和指针型
 
//------用数组存储的静态树存储表示-----
typedef struct static_BiTNode
{
    TElemType data;
    int lchild,rchild;   //lchild和rdhild分别用于存储左右孩子的下标。
}static_BiTNode;
 
 
//------基本操作的函数原型说明------
static int counts=0;     //用于给结点标号
Status CreateBiTree(BiTree *T);
    //按先序次序输入二叉树中结点的值(一个字符),#字符表示空树，
    //构造二叉链表表示的二叉树T。
Status PrintElement(TElemType e);
    //最简单的Visit函数
    //输出元素e的值
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //采用二叉链表存储方式，Visit是对结点操作的应用函数。
    //先序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
    //一旦Visit()失败，则操作失败
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //采用二叉链表存储方式，Visit是对结点操作的应用函数。
    //中序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
    //一旦Visit()失败，则操作失败
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //采用二叉链表存储方式，Visit是对结点操作的应用函数。
    //后序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
    //一旦Visit()失败，则操作失败
Status LevelOrderTraverse(BiTree T,Status (*Visit)(TElemType e));
    //采用二叉链表存储方式，Visit是对结点操作的应用函数。
    //层序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
    //一旦Visit()失败，则操作失败
int LevelSub(BiTree T, int level,Status (*Visit)(TElemType e));
    //层序辅助递归函数
Status TreeToArray(BiTree T,static_BiTNode t[]);
    //将动态二叉树转换为静态二叉链表
    //按先序次序给结点编号，lchild和rdhild分别用于存储左右孩子的下标
 
int main()
{
    BiTree T;
    static_BiTNode  a[MAX_StaticTree];//静态二叉链表是用数组作为存储空间
    CreateBiTree(&T);           //创建二叉树
 
    printf("先序：");
    PreOrderTraverse (T,PrintElement);printf("\n");
    printf("中序：");
    InOrderTraverse(T,PrintElement);printf("\n");
    printf("后序：");
    PostOrderTraverse(T,PrintElement);printf("\n");
    printf("层序：");
    LevelOrderTraverse(T,PrintElement);printf("\n");
 
    TreeToArray(T,a);       //动态转静态
    printf("静态二叉链表为：\n");   //输出及格式
    printf("counts\tdata\tlchild\trchild\t\n");
    int m;
    for(m=0;m<counts;m++)       //counts用于给结点标号
        printf("%d\t%c\t%d\t%d\n",m,a[m].data,a[m].lchild,a[m].rchild);
return 0;
}
 
//------基本操作的函数实现------
Status CreateBiTree(BiTree *T){
    //按先序次序输入二叉树中的结点的值(一个字符)，#字符表示空树，
    //构造二叉链表表示的二叉树T。
    //注意：叶子结点后要输入两个#来表示左右子树都为空
    char ch;scanf("%c",&ch);
    if(ch == '#')   *T = NULL;
    else{
        if (!(*T = (BiTNode *)malloc(sizeof(BiTNode))))  exit(OVERFLOW);
        (*T)->data = ch;            //生成根结点
        (*T)->index= counts++;      //给结点标号
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
    return OK;
}
 
Status PrintElement(TElemType e){//输出元素e的值
    printf("%c",e);
    return OK;
}
 
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //采用二叉链表存储方式，Visit是对结点操作的应用函数，
    //先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    if (T){//DLR
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild,Visit))
                if (PreOrderTraverse(T->rchild,Visit))  return OK;
        return ERROR;
    }else return OK;
}
 
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //采用二叉链表存储方式，Visit是对结点操作的应用函数，
    //中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    if (T){//LDR
        if (InOrderTraverse(T->lchild,Visit))
            if (Visit(T->data))
                if (InOrderTraverse(T->rchild,Visit))  return OK;
        return ERROR;
    }else return OK;
}
 
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //采用二叉链表存储方式，Visit是对结点操作的应用函数，
    //后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    if (T){//LRD
        if (PostOrderTraverse(T->lchild,Visit))
            if (PostOrderTraverse(T->rchild,Visit))
                if (Visit(T->data)) return OK;
        return ERROR;
    }else return OK;
}
 
Status LevelOrderTraverse(BiTree T,Status (*Visit)(TElemType e)){
    //采用二叉链表存储方式，Visit是对结点操作的应用函数，
    //层序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    int i = 0;
    for (i=1; ;i++) {//从第1层开始遍历
        if (!LevelSub(T, i,Visit))//遍历失败就跳出循环
            break;
    }
    return OK;
}
 
int LevelSub(BiTree T, int level,Status (*Visit)(TElemType e)){
	if (!T || level<1)  //如果树为空或者层次小于1就遍历失败
		return 0;       //遍历失败返回0
	if (level==1) {     //层次等于1就访问树根结点
		Visit(T->data); //遍历根结点
		return 1;
	}//左右子树递归
	return LevelSub(T->lchild,level-1,Visit) + LevelSub(T->rchild,level-1,Visit);
}
 
static int num=0;//用于转换为静态函数
Status TreeToArray(BiTree T,static_BiTNode t[]){
    t[num].data=T->data;                //数据赋值
    if (T->lchild==NULL)    //左孩子为空则置-1
        t[num].lchild=-1;
    else
        t[num].lchild=T->lchild->index;
 
    if (T->rchild==NULL)    //右孩子为空则置-1
        t[num].rchild=-1;
    else
        t[num].rchild=T->rchild->index;
 
    num++;
 
    if (T->lchild!=NULL)    //左孩子不空左递归
        TreeToArray(T->lchild,&t[0]);
    if (T->rchild!=NULL)    //右孩子不空左递归
        TreeToArray(T->rchild,&t[0]);
return OK;
}
 
/*
测试数据(P129图6.9)
-+a##*b##-c##d##/e##f##
*/
 
 
