#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/**搜索路径**/
const int maxn=105;
struct Path{
    int missionary,wildman,boat_loc;
    Path(int missionary=3,int wildman=3,int boat_loc=0):
        missionary(missionary),wildman(wildman),boat_loc(boat_loc){}
}path[maxn];
bool check(int a,int b,int c,int d){	//左岸的牧师数,野人数,右岸的牧师数,野人数 
    return (a==0||a>=b)&&(c==0||c>=d);
}
bool dfs(int missionary,int wildman,int boat_loc,int step,int limit_step){
    path[step]=Path(missionary,wildman,boat_loc);
    if(step==limit_step)
        return missionary==3&&wildman==3&&boat_loc==1;
    int a,b,c,d;
    if(missionary>=2){
        a=missionary-2,b=wildman;
        c=3-a,d=3-b;
        if(check(a,b,c,d)){
           if( dfs(c,d,!boat_loc,step+1,limit_step) )
              return true;
        }
    }
    if(wildman>=2){
        a=missionary,b=wildman-2;
        c=3-a,d=3-b;
        if(check(a,b,c,d)){
           if( dfs(c,d,!boat_loc,step+1,limit_step) )
              return true;
        }
    }
    if(missionary>=1&&wildman>=1){
        a=missionary-1,b=wildman-1;
        c=3-a,d=3-b;
        if(check(a,b,c,d)){
           if( dfs(c,d,!boat_loc,step+1,limit_step) )
              return true;
        }
    }
    if(missionary>=1){
        a=missionary-1,b=wildman;
        c=3-a,d=3-b;
        if(check(a,b,c,d)){
           if( dfs(c,d,!boat_loc,step+1,limit_step) )
              return true;
        }
    }
    if(wildman>=1){
        a=missionary,b=wildman-1;
        c=3-a,d=3-b;
        if(check(a,b,c,d)){
           if( dfs(c,d,!boat_loc,step+1,limit_step) )
              return true;
        }
    }
    return false;
}

int main(){
    int limit_step=1;
    while(limit_step<=25){
        if(dfs(3,3,0,0,limit_step)) break;
        limit_step++;
    }
    printf("初始状态:(3,3,0)\n");
    for(int i=1;i<=limit_step;i++){
        int a=path[i-1].missionary+path[i].missionary-3;
        int b=path[i-1].wildman+path[i].wildman-3;
        if(path[i].boat_loc==1){
            printf("%d个传教士和%d个野人乘船从左岸到右岸:",a,b);
        }
        else{
            printf("%d个传教士和%d个野人乘船从右岸到左岸:",a,b);
        }
        printf("(%d %d %d)\n",path[i].missionary,path[i].wildman,path[i].boat_loc);
    }
    return 0;
}
