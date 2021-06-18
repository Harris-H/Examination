/**
房子颜色:  red  yellow blue green ivory

国家: englishman spaniard norwegian ukrainian japanese

宠物: dog fox Snails horse zebra

饮料: orangejuice tea coffee milk water

烟: kools chesterfields winston LuckyStrike parliaments


英国人（englishman）住在红色（red）的房子里。
            11 ----------------- 6
西班牙人（spaniard）养了一条狗（dog）。
             12 -----------------16
挪威人（norwegian）住在左边的第一个房子里。
           13----------------1
黄房子（yellow）里的人喜欢抽kools牌的香烟。
          7------------------26
抽winston牌香烟的人养了一只蜗牛（Snails）。
    28----------------------18
抽Lucky Strike牌香烟的人喜欢喝桔子汁（orange juice）。
    29--------------------------21
乌克兰人（ukrainian）喜欢喝茶（tea）。
14------------------------22
日本人（japanese）抽parliaments牌的烟。
15--------------------30
喜欢喝咖啡（coffee）的人住在绿（green）房子里。
23-------------------------------9
中间那个房子里的人喜欢喝牛奶（milk）。
3-----------------------------24

抽chesterfields牌香烟的人与养狐狸（fox）的人是邻居。
    27------------------------17
绿（green）房子在象牙白（ivory）房子的右边（图中的右边）。
9------------------------10
挪威人（norwegian）住在蓝色（blue）的房子旁边。
13----------------------------8
抽kools牌的香烟的人与养马（horse）的人是邻居。
26------------------------19
**/
/**
连边30*30
Prepare(){
   全置真
   连某条边(u,v) ，则u所属范围的其他点x与v连接置假，则v所属范围的其他点y与
   u连接置假
}
深搜 dfs(){
   搜完5个{
      再判断房子相邻这些条件
   }
   搜完某一房子的所有属性，然后到下一个房子
   对某种类型，找未被标记的，然后跟下一种类型找有边相连且未被标记
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
