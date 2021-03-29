#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
int n,l[N],r[N],a[N],id,in[N],rt;
void lev(){
	queue<int>q;
	q.push(rt);
	while(!q.empty()){
		int u=q.front();q.pop();
		a[id++]=u;
		if(~l[u]) q.push(l[u]);
		if(~r[u]) q.push(r[u]);
	}
}
bool check(int x){
	if(x*2+1<n&&a[x*2+1]!=l[a[x]]) return false;
	if(x*2+2<n&&a[x*2+2]!=r[a[x]]) return false;
	int f=1;
	if(x*2+1<n) f&=check(x*2+1);
	if(x*2+2<n) f&=check(x*2+2);
	return f;
}
int main(){
	scanf("%d",&n);for(int i=0;i<n;i++){
		string x,y;cin>>x>>y;
		//cout<<"x="<<x<<" "<<"y="<<y<<endl;
		if(x!="-") in[stoi(x)]++,l[i]=stoi(x);
		else l[i]=-1;
		if(y!="-") in[stoi(x)]++,r[i]=stoi(x);
		else r[i]=-1;
		a[i]=-1;
	}
	for(int i=0;i<n;i++) if(!in[i]){
		rt=i;break;
	} 
	lev();
	if(check(0)){
		printf("YES %d\n",a[n-1]);
	}
	else printf("NO %d\n",rt);
}
