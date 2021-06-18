//�ó���ʵ�ֵĹ���:
//1.��ͼ
//2.���������������ʾ
//3.ɾ����㣨����Ϊ�����ӽ�㣬Ҫ����ɾ�����ڵ�������
//4.��������������ʾ
//5.�ַ�ͳ�ƹ��� 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
struct node{	//���ṹ�� 
    char ch;	//�ַ�	 
    int v;	//����ͳ���ַ����� 
    node *l,*r;	//�������Ҷ��� 
};
node* search(node *x,node *fa,char key){	//����ֵΪkey�Ľ���Ƿ������������ֹ� 
    if(!x){
        return NULL;
    }
    else if(x->ch==key) return x;
    else if(x->ch<key) return search(x->l,x,key);
    else return search(x->r,x,key);
}
node* build(node *x,char key){	//�������������� 
    node *tmp =search(x,NULL,key);
    if(tmp==NULL){	//Ϊ�����½�һ����� 
        if(!x){
        	x=new node();
        	x->ch=key;
        	x->v=1;
        	x->l=x->r=NULL;
		}
        else if(key<=x->ch) x->l=build(x->l,key);	//������������ 
        else x->r=build(x->r,key);	//������������ 
    }
    else {	//������ֹ�ֱ�Ӵ���+1 
        tmp->v++;
    }
    return x;
}
node * del(node *x,char key){	//ɾ��һ����� 
	node *p,*fa;
	p=x,fa=NULL;
	while(p){
		if(p->ch==key) break;	//����ҵ���ֱ������ 
		fa=p;
		 if(p->ch>=key) p=p->l;
		else p=p->r;
	}
	if(p==NULL) return x;
	if(p->l==NULL){
		if(fa==NULL) x=p->r;
		else if(fa->l==p) fa->l=p->r;
		else fa->r=p->r;
		free(p);
	}
	else {
	node *q=p;
	node *s=p->l;//��ʱ��p��ֵΪq��sΪp������������qΪs��˫��
		while(s->r)//����p���������в��������½�㡪�������
			{
				q=s;
				s=s->r;//sΪ����������㣬qΪ���������ڵ�ĸ�ĸ���
			}
	if(q==p)//�����ж�p�����������Ƿ�����������
		 q->l=s->l;//sΪp������������������������û����������
	else   q->r=s->l;
		p->ch=s->ch;
		free(s);
	}
	return x;
}
void P(int f){	//�����ж�������ӻ����Ҷ��� 
	if(f==-1) putchar('L');
	else if(f==1) putchar('R');
}
void fun(node *x,int sp,int f){	//��ӡ�������Ľṹ 
	if(!x) return;
	for(int i=0;i<sp;i++) printf(" ");
	P(f);printf("[%c:%d]\n",x->ch,x->v);
	fun(x->l,sp+2,-1);
	fun(x->r,sp+2,1);
}
void in(node *x){	//������� 
	if(!x) return;
	in(x->l);
	printf("[%c,%d]\n",x->ch,x->v);
	in(x->r);
}
void pre(node *x){	//ǰ����� 
	if(!x) return;
	printf("[%c,%d]\n",x->ch,x->v);
	in(x->l);
	in(x->r);
}
void post(node *x){	//������� 
	if(!x) return;
	in(x->l);
	in(x->r);
	printf("[%c,%d]\n",x->ch,x->v);
}
int main(){
	printf("ͳ�������ı��и����ַ����ֵĴ���\n"); 
	printf("--------------------------------------\n");
    node* rt=NULL;
    char ch;
   	while((ch=getchar())!='\n'){
   		rt=build(rt,ch);
	}
	printf("--------------------------------------\n");
	  rt=del(rt,'y');
	fun(rt,0,0);
	printf("\n---------\n");
	printf("1��ǰ��������\n");
	printf("2������������\n");
	printf("3������������\n");
	printf("--------------------------------------\n");
	printf("��ѡ��˵���: ");
	int op;scanf("%d",&op); 
	if(op==1){
		pre(rt);
	}else if(op==2) in(rt);
	else post(rt);
    return 0;
}
