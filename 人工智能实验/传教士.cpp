#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/**搜索路径**/
const int maxn=105;
int real_step;
int limit_step=25;
// Path 结构体，代表状态   path[]: answer path 上的状态序列
struct Path{
    //（左岸传教士个数，左岸野人个数，船在左岸）或者 （右岸传教士个数，右岸野人个数，船在右岸）
    int missionary,wildman,boat_loc; 
	Path(int missionary=3,int wildman=3,int boat_loc=0):
        missionary(missionary),wildman(wildman),boat_loc(boat_loc){} 
}path[maxn];//path：结构体数组，每个元素是一个Path对象即状态
// 检测 a、b、c、d 是否满足传教士不被野人吃掉的条件
// a:乘船后某岸剩余传教士数量  b:乘船后某岸剩余野人数量  c:乘船后另一岸传教士数量  d：乘船后另一岸野人数量
bool check(int a,int b,int c,int d){
 	 return (a==0||a>=b)&&(c==0||c>=d);
}

// 状态：[missionary: 某岸传教士数量  wildman: 某岸野人数量  boat_loc:船的位置]
//深度优先搜索 此处采用递归，没用栈和队列


//  step: 第step次过河     limit_step:限制的最多次数
bool dfs(int missionary,int wildman,int boat_loc,int step)
{
    path[step]=Path(missionary,wildman,boat_loc);
    // 如果满足边界条件step达到了limit_step值结束递归调用
    if(missionary==3&&wildman==3&&boat_loc==1)
       {real_step = step;
        // 返回此时状态是否满足目标状态[3,3,1]
        return true;
       }
    // 结束递归调用的另一个条件
    if(step>limit_step)
        return false;
    // a:乘船后某岸剩余传教士数量  b:乘船后某岸剩余野人数量  c:乘船后另一岸传教士数量  d：乘船后另一岸野人数量
    int a,b,c,d;
    //如果某岸传教士数量>=2 方法:(2,0)
    if(missionary>=2){
        //2:乘船传教士数量  0:乘船野人数量
        a=missionary-2,b=wildman;
		c=3-a,d=3-b;
        // 如果 a,b,c,d 满足条件
        if(check(a,b,c,d)){
           // step+1: 第step+1次  limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    //如果某岸野人数量>=2 方法:(0,2)
    if(wildman>=2){
        //0:乘船传教士数量    2:乘船野人数量
        a=missionary,b=wildman-2;
	    c=3-a,d=3-b;
        // 如果 a,b,c,d 满足条件
        if(check(a,b,c,d)){
           // step+1: 第step+1次   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    // 如果某岸传教士数量>=1并且某岸野人数量>=1 方法:(1,1)
    if(missionary>=1&&wildman>=1){
        //1:乘船传教士数量   1:乘船野人数量
        a=missionary-1,b=wildman-1;
	    c=3-a,d=3-b;
        //如果 a,b,c,d 满足条件
        if(check(a,b,c,d)){
           // step+1: 第step+1次   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    // 如果某岸传教士数量>=1 方法:(1,0)
    if(missionary>=1){
        //1:乘船传教士数量    0:乘船野人数量
        a=missionary-1,b=wildman;
	    c=3-a,d=3-b;
        //如果 a,b,c,d 满足条件
        if(check(a,b,c,d)){
           //  step+1: 第step+1次   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    // 如果某岸野人数量>=1 方法:(0,1)
    if(wildman>=1){
        //0:乘船传教士数量     1:乘船野人数量
        a=missionary,b=wildman-1;
	    c=3-a,d=3-b;
        //如果 a,b,c,d 满足条件
        if(check(a,b,c,d)){
            // step+1: 第step+1次   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }

    return false;
}

//
int main()
{

    //如果dfs function返回真值，说明已到达目标状态，结束循环不再继续搜索;
    //如果dfs function返回假值，说明还没有到达目标状态，继续搜索.
    //missionary:左岸传教士数量：3； wildman:左岸野人数量：3； boat_loc:船的位置：0即左岸； step:深度优先搜索步骤：第0次；  limit_step:限制的最多次数
    if(dfs(3,3,0,0))
      {
       // 输出初始状态
       printf("初始状态:(3,3,0)\n");
       //循环输出每一次渡河后岸上的状态（交替输出左右两岸的情况）和每次渡河动作，即 answer path
	   for(int i=1;i<=real_step;i++)
       {   // x:乘船的传教士个数  y:乘船的野人个数 
           int x=path[i-1].missionary+path[i].missionary-3;
           int y=path[i-1].wildman+path[i].wildman-3;
           // 如果船在右岸  0：左岸  1：右岸
           if(path[i].boat_loc==1){
              printf("%d个传教士和%d个野人乘船从左岸到右岸:",x,y);
            }
           // 如果船在左岸 0：左岸  1：右岸
            else{
              printf("%d个传教士和%d个野人乘船从右岸到左岸:",x,y);
            }
            //输出状态:（左岸传教士个数，左岸野人个数，船在左岸）或者 （右岸传教士个数，右岸野人个数，船在右岸）
            printf("(%d %d %d)\n",path[i].missionary,path[i].wildman,path[i].boat_loc);
       }
      }
    else printf("no answer\n");
      return 0;
}

