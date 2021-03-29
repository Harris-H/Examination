#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
int a[N],n;
int ins_search(int *a,int val){
	int l=1,r=n;
	while(l<=r){
		int mid=l+(val-a[l])/(a[r]-a[l])*(r-l);
		if(a[mid]==val) return mid;
		else if(a[mid]>val) r=mid-1;
		else l=mid+1;
	}
	return -1;
}
int main(){
	freopen("2.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+n+1); 
	printf("查询结果为:\n");
	printf("%d\n",ins_search(a,7));
	return 0;
}
