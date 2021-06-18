/**
������ɫ:  red  yellow blue green ivory

����: englishman spaniard norwegian ukrainian japanese

����: dog fox Snails horse zebra

����: orangejuice tea coffee milk water

��: kools chesterfields winston LuckyStrike parliaments


Ӣ���ˣ�englishman��ס�ں�ɫ��red���ķ����
            11 ----------------- 6
�������ˣ�spaniard������һ������dog����
             12 -----------------16
Ų���ˣ�norwegian��ס����ߵĵ�һ�������
           13----------------1
�Ʒ��ӣ�yellow�������ϲ����kools�Ƶ����̡�
          7------------------26
��winston�����̵�������һֻ��ţ��Snails����
    28----------------------18
��Lucky Strike�����̵���ϲ���Ƚ���֭��orange juice����
    29--------------------------21
�ڿ����ˣ�ukrainian��ϲ���Ȳ裨tea����
14------------------------22
�ձ��ˣ�japanese����parliaments�Ƶ��̡�
15--------------------30
ϲ���ȿ��ȣ�coffee������ס���̣�green�������
23-------------------------------9
�м��Ǹ����������ϲ����ţ�̣�milk����
3-----------------------------24

��chesterfields�����̵����������꣨fox���������ھӡ�
    27------------------------17
�̣�green�������������ף�ivory�����ӵ��ұߣ�ͼ�е��ұߣ���
9------------------------10
Ų���ˣ�norwegian��ס����ɫ��blue���ķ����Աߡ�
13----------------------------8
��kools�Ƶ����̵���������horse���������ھӡ�
26------------------------19
**/
/**
����30*30
Prepare(){
   ȫ����
   ��ĳ����(u,v) ����u������Χ��������x��v�����ü٣���v������Χ��������y��
   u�����ü�
}
���� dfs(){
   ����5��{
      ���жϷ���������Щ����
   }
   ����ĳһ���ӵ��������ԣ�Ȼ����һ������
   ��ĳ�����ͣ���δ����ǵģ�Ȼ�����һ���������б�������δ�����
}
**/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int property_num=5;
const int maxn=31;
bool G[maxn][maxn];
bool vis[maxn];
int ans[property_num][property_num+1];
char property[maxn][20]={
    "#",
    "house 1:","house 2:","house 3:","house 4:","house 5:",
    "red","yellow","blue","green","ivory",
    "englishman","spaniard","norwegian","ukrainian","japanese",
    "dog","fox","Snails","horse","zebra",
    "orangejuice","tea","coffee","milk","water",
    "kools","chesterfields","winston","LuckyStrike","parliaments"
};
void SetFalse(int u,int v){
    int a=(u-1)/5;
    for(int i=a*5+1;i<=(a+1)*5;i++){
        if(i!=u) G[i][v]=G[v][i]=false;
    }
    int b=(v-1)/5;
    for(i=b*5+1;i<=(b+1)*5;i++){
        if(i!=v) G[u][i]=G[i][u]=false;
    }
}
void Prepare(){
    memset(G,true,sizeof(G));
    memset(vis,false,sizeof(vis));
    SetFalse(11,6);
    SetFalse(12,16);
    SetFalse(13,1);
    SetFalse(7,26);
    SetFalse(28,18);
    SetFalse(29,21);
    SetFalse(14,22);
    SetFalse(15,30);
    SetFalse(23,9);
    SetFalse(3,24);
}
int GetIndex(int x){
    for(int i=0;i<property_num;i++){
        for(int j=0;j<=property_num;j++)
            if(ans[i][j]==x) return i+1;
    }
    return -1;
}
bool check(){
    int a=GetIndex(27);
    int b=GetIndex(17);
    if(a!=b+1&&a+1!=b) return false;
    a=GetIndex(9);
    b=GetIndex(10);
    if(a<=b) return false;
    a=GetIndex(13);
    b=GetIndex(8);
    if(a!=b+1&&a+1!=b) return false;
    a=GetIndex(26);
    b=GetIndex(19);
    if(a!=b+1&&a+1!=b) return false;
    return true;
}
void Print(){
    for(int i=0;i<property_num;i++){
            for(int j=0;j<=property_num;j++)
                printf("%s ",property[ans[i][j]]);
            printf("\n");
        }
}
bool Can(int a,int b,int v){
    for(int i=0;i<=b;i++){
        if(!G[ans[a][i]][v]) return false;
    }

    return true;
}

bool dfs(int num,int id,int step){
    if(step==5){
        return check();
    }
    ans[step][num]=id;
    vis[id]=true;
    if(num==5) {
        bool ret=dfs(0,step+2,step+1);
        vis[id]=false;
        return ret;
    }
    int a=num+1;
    for(int i=a*5+1;i<=(a+1)*5;i++){
        if(Can(step,num,i)&&!vis[i]){
            if(dfs(num+1,i,step)) return true;
        }
    }
    vis[id]=false;
    return false;
}
int main(){
    Prepare();
    if(!dfs(0,1,0)) printf("Impossible\n");
    else Print();
	int x;
	scanf("%d",&x);
    return 0;
}
