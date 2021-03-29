
#include "iostream.h"
#include "stdlib.h"
#include "math.h"

int isdid[4][4][2];
struct mv
{
	int c;
	int s;

}mv1[1000];
void move(int c,int s,int z)
{
	int i;
	if(c+s<=2&&z%2==0)
	{
		mv1[z].c=c;
		mv1[z].s=s;
		cout<<"the following is a successful movement\n";
		for(i=0;i<=z;i++)
		{
			if(i%2==0)
			{
				if(mv1[i].c>0)
				{
					cout<<mv1[i].c<<"个传教士";
				}
				if(mv1[i].s>0)
				{
					cout<<mv1[i].s<<" 个食人者";
				}
				cout<<"----->\n";
			}
			else
			{
				cout<<"<-----";
				if(mv1[i].c>0)
				{
					cout<<mv1[i].c<<"个传教士";
				}
				if(mv1[i].s>0)
				{
					cout<<mv1[i].s<<" 个食人者";
				}
				cout<<"\n";
			}
		}
		cout<<"the end of this movement\n";
		return;
	}
	if(z%2==0)
	{
		isdid[c][s][0]=1;
		if(c==3&&s==3)
		{
			if(isdid[2][2][1]==0)
			{
				mv1[z].c=1;
				mv1[z].s=1;
				move(2,2,z+1);
			}
			if(isdid[3][2][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(3,2,z+1);
			}
			if(isdid[3][1][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=2;
				move(3,1,z+1);
			}
		}
		else if(c==3&&s==2)
		{
			if(isdid[2][2][1]==0)
			{
				mv1[z].c=1;
				mv1[z].s=0;
				move(2,2,z+1);
			}
			if(isdid[3][1][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(3,1,z+1);
			}
			if(isdid[3][0][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=2;
				move(3,0,z+1);
			}
		}
		else if(c==3&&s==1)
		{
			
			if(isdid[1][1][1]==0)
			{
				mv1[z].c=2;
				mv1[z].s=0;
				move(1,1,z+1);
			}
			if(isdid[3][0][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(3,0,z+1);
			}
		}
		else if(c==3&&s==0)
		{
			isdid[c][s][0]=0;
			return;
		}

		else if(c==2&&s==2)
		{
			if(isdid[1][1][1]==0)
			{
				mv1[z].c=1;
				mv1[z].s=1;
				move(1,1,z+1);
			}
			if(isdid[0][2][1]==0)
			{
				mv1[z].c=2;
				mv1[z].s=0;
				move(0,2,z+1);
			}
		}
		else if(c==0&&s==3)
		{
			if(isdid[0][2][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(0,2,z+1);
			}
			if(isdid[0][1][1]==0)
			{
				mv1[z].c=0;
				mv1[z].s=2;
				move(0,1,z+1);
			}
		}
		isdid[c][s][0]=0;
	}
	else
	{
		isdid[c][s][1]=1;
		if(c==3&&s==2)
		{
			if(isdid[3][3][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(3,3,z+1);
			}
			
		}
		else if(c==3&&s==1)
		{
			if(isdid[3][2][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(3,2,z+1);
			}
			if(isdid[3][3][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=2;
				move(3,3,z+1);
			}
		
		}
		else if(c==3&&s==0)
		{
			
			if(isdid[3][1][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(3,1,z+1);
			}
			if(isdid[3][2][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=2;
				move(3,2,z+1);
			}
		}
		else if(c==2&&s==2)
		{
			if(isdid[3][3][0]==0)
			{
				mv1[z].c=1;
				mv1[z].s=1;
				move(3,3,z+1);
			}
			if(isdid[3][2][0]==0)
			{
				mv1[z].c=1;
				mv1[z].s=0;
				move(3,2,z+1);
			}
		}

		else if(c==1&&s==1)
		{
			if(isdid[2][2][0]==0)
			{
				mv1[z].c=1;
				mv1[z].s=1;
				move(2,2,z+1);
			}
			if(isdid[3][1][0]==0)
			{
				mv1[z].c=2;
				mv1[z].s=0;
				move(3,1,z+1);
			}
			
		}
		else if(c==0&&s==3)
		{
			isdid[c][s][1]=0;
			return;
		}
		else if(c==0&&s==2)
		{
			if(isdid[0][3][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(0,3,z+1);
			}
			if(isdid[2][2][0]==0)
			{
				mv1[z].c=2;
				mv1[z].s=0;
				move(2,2,z+1);
			}
		}
		else if(c==0&&s==1)
		{
			if(isdid[1][1][0]==0)
			{
				mv1[z].c=1;
				mv1[z].s=0;
				move(1,1,z+1);
			}
			if(isdid[0][2][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=1;
				move(0,2,z+1);
			}
			if(isdid[0][3][0]==0)
			{
				mv1[z].c=0;
				mv1[z].s=2;
				move(0,3,z+1);
			}
		}
		
		isdid[c][s][1]=0;
	}

}

int main()
{
	int i,j,k;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			for(k=0;k<2;k++)
				isdid[i][j][k]=0;
	move(3,3,0);
	cin>>i;
	return 0;
}