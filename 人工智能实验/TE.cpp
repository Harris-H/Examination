#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct path{
	int m,w,f;//missionary wildman flag(船在左为0,船在右为1) 
	path(int m=3,int w=3,int f=0):m(m),w(w),f(f){} 
}p[105];
bool check(int a,int b,int c,int d){	//a,b: 左岸牧师,野人个数  c,d:右岸牧师,野人个数. 
	return (!a||a>=b)&&(!c||c>=d);
} 
bool dfs(int m,int w,int f,int s,int li){//s:step,li:limit_step
	p[s]={m,w,f};//记录状态. 
	if(s==li) return m==3&&w==3&&f==1;//判断是否到达目标状态. 
	if(m>=2){//5种状态转移. 
		int a=m-2,b=w,c=3-a,d=3-b;
		if(check(a,b,c,d)&&dfs(c,d,!f,s+1,li)) return true;
	}
	if(w>=2){
		int a=m,b=w-2,c=3-a,d=3-b;
		if(check(a,b,c,d)&&dfs(c,d,!f,s+1,li)) return true;
	}
	if(m>=1&&w>=1){
		int a=m-1,b=w-1,c=3-a,d=3-b;
		if(check(a,b,c,d)&&dfs(c,d,!f,s+1,li)) return true;
	}
	if(m>=1){
		int a=m-1,b=w,c=3-a,d=3-b;
		if(check(a,b,c,d)&&dfs(c,d,!f,s+1,li)) return true;
	}
	if(w>=1){
		int a=m,b=w-1,c=3-a,d=3-b;
		if(check(a,b,c,d)&&dfs(c,d,!f,s+1,li)) return true;
	}
	return false;
}
int main(){
	int li=1;while(li<=25){
		if(dfs(3,3,0,0,li)) break;li++;
	}printf("初始状态:(3,3,0)\n");
	for(int i=1;i<=li;i++){
		int a=p[i].m-(3-p[i-1].m);
		int b=p[i].w-(3-p[i-1].w);
		if(p[i].f==1) printf("%d个传教士和%d个野人乘船从左岸到右岸:",a,b);
		else printf("%d个传教士和%d个野人乘船从右岸到左岸:",a,b);
		printf("(%d %d %d)\n",p[i].m,p[i].w,p[i].f);
	} 
}
