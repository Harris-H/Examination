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
void adj(int *a,int l,int r){
	int i=l,j=(i<<1);
	while(j<=r){
		if(j+1<=r&&a[j]<a[j+1]) ++j;
		if(a[i]>a[j]) break;
		swap(a[i],a[j]),i=j,j=(i<<1);
	}
} 
void heap_sort(int *a,int n){
	for(int i=(n>>1);i;i--)
		adj(a,i,n);	//�������� ת��Ϊ�󶥶�. 
	for(int i=n;i;i--){	//ÿ�ζ��źõ�ǰ���Ԫ�� 
		swap(a[1],a[i]);
		adj(a,1,i-1);	//����һ�κ�,��������Ӱ��,ά���󶥶� 
	}
}
int main(){
	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	heap_sort(a,n);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
