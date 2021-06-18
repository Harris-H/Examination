#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/**����·��**/
const int maxn=105;
int real_step;
int limit_step=25;
// Path �ṹ�壬����״̬   path[]: answer path �ϵ�״̬����
struct Path{
    //���󰶴���ʿ��������Ұ�˸����������󰶣����� ���Ұ�����ʿ�������Ұ�Ұ�˸����������Ұ���
    int missionary,wildman,boat_loc; 
	Path(int missionary=3,int wildman=3,int boat_loc=0):
        missionary(missionary),wildman(wildman),boat_loc(boat_loc){} 
}path[maxn];//path���ṹ�����飬ÿ��Ԫ����һ��Path����״̬
// ��� a��b��c��d �Ƿ����㴫��ʿ����Ұ�˳Ե�������
// a:�˴���ĳ��ʣ�ഫ��ʿ����  b:�˴���ĳ��ʣ��Ұ������  c:�˴�����һ������ʿ����  d���˴�����һ��Ұ������
bool check(int a,int b,int c,int d){
 	 return (a==0||a>=b)&&(c==0||c>=d);
}

// ״̬��[missionary: ĳ������ʿ����  wildman: ĳ��Ұ������  boat_loc:����λ��]
//����������� �˴����õݹ飬û��ջ�Ͷ���


//  step: ��step�ι���     limit_step:���Ƶ�������
bool dfs(int missionary,int wildman,int boat_loc,int step)
{
    path[step]=Path(missionary,wildman,boat_loc);
    // �������߽�����step�ﵽ��limit_stepֵ�����ݹ����
    if(missionary==3&&wildman==3&&boat_loc==1)
       {real_step = step;
        // ���ش�ʱ״̬�Ƿ�����Ŀ��״̬[3,3,1]
        return true;
       }
    // �����ݹ���õ���һ������
    if(step>limit_step)
        return false;
    // a:�˴���ĳ��ʣ�ഫ��ʿ����  b:�˴���ĳ��ʣ��Ұ������  c:�˴�����һ������ʿ����  d���˴�����һ��Ұ������
    int a,b,c,d;
    //���ĳ������ʿ����>=2 ����:(2,0)
    if(missionary>=2){
        //2:�˴�����ʿ����  0:�˴�Ұ������
        a=missionary-2,b=wildman;
		c=3-a,d=3-b;
        // ��� a,b,c,d ��������
        if(check(a,b,c,d)){
           // step+1: ��step+1��  limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    //���ĳ��Ұ������>=2 ����:(0,2)
    if(wildman>=2){
        //0:�˴�����ʿ����    2:�˴�Ұ������
        a=missionary,b=wildman-2;
	    c=3-a,d=3-b;
        // ��� a,b,c,d ��������
        if(check(a,b,c,d)){
           // step+1: ��step+1��   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    // ���ĳ������ʿ����>=1����ĳ��Ұ������>=1 ����:(1,1)
    if(missionary>=1&&wildman>=1){
        //1:�˴�����ʿ����   1:�˴�Ұ������
        a=missionary-1,b=wildman-1;
	    c=3-a,d=3-b;
        //��� a,b,c,d ��������
        if(check(a,b,c,d)){
           // step+1: ��step+1��   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    // ���ĳ������ʿ����>=1 ����:(1,0)
    if(missionary>=1){
        //1:�˴�����ʿ����    0:�˴�Ұ������
        a=missionary-1,b=wildman;
	    c=3-a,d=3-b;
        //��� a,b,c,d ��������
        if(check(a,b,c,d)){
           //  step+1: ��step+1��   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }
    // ���ĳ��Ұ������>=1 ����:(0,1)
    if(wildman>=1){
        //0:�˴�����ʿ����     1:�˴�Ұ������
        a=missionary,b=wildman-1;
	    c=3-a,d=3-b;
        //��� a,b,c,d ��������
        if(check(a,b,c,d)){
            // step+1: ��step+1��   limit_step:
           if( dfs(c,d,!boat_loc,step+1) )
              return true;
        }
    }

    return false;
}

//
int main()
{

    //���dfs function������ֵ��˵���ѵ���Ŀ��״̬������ѭ�����ټ�������;
    //���dfs function���ؼ�ֵ��˵����û�е���Ŀ��״̬����������.
    //missionary:�󰶴���ʿ������3�� wildman:��Ұ��������3�� boat_loc:����λ�ã�0���󰶣� step:��������������裺��0�Σ�  limit_step:���Ƶ�������
    if(dfs(3,3,0,0))
      {
       // �����ʼ״̬
       printf("��ʼ״̬:(3,3,0)\n");
       //ѭ�����ÿһ�ζɺӺ��ϵ�״̬��������������������������ÿ�ζɺӶ������� answer path
	   for(int i=1;i<=real_step;i++)
       {   // x:�˴��Ĵ���ʿ����  y:�˴���Ұ�˸��� 
           int x=path[i-1].missionary+path[i].missionary-3;
           int y=path[i-1].wildman+path[i].wildman-3;
           // ��������Ұ�  0����  1���Ұ�
           if(path[i].boat_loc==1){
              printf("%d������ʿ��%d��Ұ�˳˴����󰶵��Ұ�:",x,y);
            }
           // ��������� 0����  1���Ұ�
            else{
              printf("%d������ʿ��%d��Ұ�˳˴����Ұ�����:",x,y);
            }
            //���״̬:���󰶴���ʿ��������Ұ�˸����������󰶣����� ���Ұ�����ʿ�������Ұ�Ұ�˸����������Ұ���
            printf("(%d %d %d)\n",path[i].missionary,path[i].wildman,path[i].boat_loc);
       }
      }
    else printf("no answer\n");
      return 0;
}

