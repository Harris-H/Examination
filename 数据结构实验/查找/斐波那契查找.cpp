 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define pb push_back
ll f[105];
vector<int>a;
void pre(int n){
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
	}
} 
int  fib_search(vector<int>a,int val){
	int idx=0,m=a.size();pre(20);
	while(f[idx]<a.size()){
		idx++;
	}
	for(int i=a.size();i<f[idx];i++){
		a.pb(a[a.size()-1]);
	} 
	int l=0,r=a[a.size()-1];
	while(l<=r&&idx>=0){
		int mid=l+f[idx-1]-1;
		if(a[mid]==val)	return mid>=m?m-1:mid;
		else if(a[mid]>val) r=mid-1,idx--;
		else l=mid+1,idx-=2;
	}return -1;
}
int main(){
	freopen("1.in","r",stdin);
	for(int i=0,x;i<10;i++){
		scanf("%d",&x);a.pb(x);
	}sort(a.begin(),a.end());
	printf("查询的结果为:\n");
	printf("%d\n",fib_search(a,7));
	return 0;
}
