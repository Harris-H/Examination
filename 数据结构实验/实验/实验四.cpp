#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
// string name[N];
// map<string,int>mp;
int cnt,h[N],st,ed,vis[N],in[N];
int tot;
vector<int>path;
struct edge{
	int to,nt,w;
}e[N<<1];
void add(int u,int v,int w){
	e[++cnt]={v,h[u],w},h[u]=cnt;
	e[++cnt]={u,h[v],w},h[v]=cnt;
}
void dfs(int u,int fa){
//	printf("u=%d,fa=%d\n",u,fa); 
	if(u==ed){
		tot++;
		printf("�� %d ��·��Ϊ:\n",tot); 
		printf("%d",st);
		for(int v:path) printf(" -> %d",v);
		printf("\n");
		return;
	}
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].to;
		if(v==fa||vis[v]) continue;
		path.pb(v);
		vis[v]=1;
		dfs(v,u);
		vis[v]=0; 
		path.pop_back();
	}
}
int d[N],pre[N];
stack<int>sk;
void dij(int st,int ed){
	queue<int>q;
	mst(d,0x3f),d[st]=0;
	q.push(st);in[st]=1;
	while(!q.empty()){
		int u=q.front();q.pop();in[u]=0;
		for(int i=h[u];i;i=e[i].nt){
			int v=e[i].to,w=e[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				pre[v]=u;
				if(!in[v]) q.push(v),in[v]=1;
			}
		}
	}
	while(ed!=st){
		sk.push(ed);
		ed=pre[ed];
	}
}
int main(){
	int n,m;
	printf("�뽨��������·ͼ\n"); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	printf("\n�Ѿ�ʹ���ڽӱ���ɹ�����·ͼ�Ĺ���\n\n"); 
	printf("�������ѯ�������յ�:\n");
	scanf("%d%d",&st,&ed);
	vis[st]=0,dfs(st,0);
	dij(st,ed);
	printf("\n�� %d �� %d ��·������Ϊ: %d\n\n",st,ed,tot);
	printf("����� %d �� �յ� %d �����·����:\n",st,ed);
	printf("%d",st);
	while(!sk.empty()){
		printf(" -> %d",sk.top());
		sk.pop();
	}printf("\n\n"); 
	printf("�ø���·�ĳ���Ϊ: %d\n",d[ed]);
	return 0;
}
/*
9 10
1 2 100
2 3 200
3 4 300
5 6 200
2 6 250
3 6 300
3 7 200
7 8 250
6 8 100
8 9 50

1 9
*/
