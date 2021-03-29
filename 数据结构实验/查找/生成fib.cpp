#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
int f[N];
void pre(int n){
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
		printf("f[%d]=%d\n",i,f[i]);
	}
} 
int main(){
	pre(50); 
	return 0;
}
