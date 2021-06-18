
#include "stdio.h"
#define ROTATE1(p) {int i,temp;temp=perm1[p];for(i=p-1;i>=0;i--) perm1[i+1]=perm1[i];perm1[0]=temp;}
#define ROTATE2(p) {int i,temp;temp=perm2[p];for(i=p-1;i>=0;i--) perm2[i+1]=perm2[i];perm2[0]=temp;}
#define ROTATE3(p) {int i,temp;temp=perm3[p];for(i=p-1;i>=0;i--) perm3[i+1]=perm3[i];perm3[0]=temp;}
#define ROTATE4(p) {int i,temp;temp=perm4[p];for(i=p-1;i>=0;i--) perm4[i+1]=perm4[i];perm4[0]=temp;}
#define ROTATE5(p) {int i,temp;temp=perm5[p];for(i=p-1;i>=0;i--) perm5[i+1]=perm5[i];perm5[0]=temp;}

void main(void)
    {
	//perm1 烟：K,C,W,L,P,对 1，2，3，4，5下同
	//perm2 宠物：狗，狐狸，蜗牛，马，斑马
	//perm3 国家：英，西，日，乌，挪威左一
	//perm4 颜色：红，绿，白，黄，蓝左二
	//perm5 饮料：桔子，茶，水，咖啡，牛奶中一
		int perm1[5];
		int position1;
		int n1=5;
		int i;
		for(i=0;i<n1;i++)
			perm1[i]=i+1;
		position1 =n1-1;
		while(position1!=0)
		{
			int perm2[5];
		int position2;
		int n2=5;
		int i;
		for(i=0;i<n2;i++)
			perm2[i]=i+1;
		position2 =n2-1;
		while(position2!=0)
		{
			int perm3[4];
		int position3;
		int n3=4;
		int i;
		for(i=0;i<n3;i++)
			perm3[i]=i+1;
		position3 =n3-1;
		while(position3!=0)
		{
			int perm4[4];
		int position4;
		int n4=4;
		int i;
		for(i=0;i<n4;i++)
			perm4[i]=i+1;
		position4 =n4-1;
		while(position4!=0)
		{
			int perm5[4];
		int position5;
		int n5=4;
		int i;
		for(i=0;i<n5;i++)
			perm5[i]=i+1;
		position5 =n5-1;
		while(position5!=0)
		{
			//在这里加进你的代码
			int bol=0;
			for(int i=0;i<4;i++)
			{
				if((perm3[i]==1&&perm4[i]!=1)||(i==0&&perm3[i]==1))
					bol=1;
			}
			for(i=0;i<4;i++)
			{
				if((perm3[i]==2&&perm2[i+1]!=1)||(i==0&&perm3[i]==2))
					bol=1;
			}
			if(perm1[0]==1&&perm4[0]!=4||perm1[1]==1)
				bol=1;
			for(i=2;i<5;i++)
			{
				if(perm1[i]==1&&perm4[i-1]!=4)
					bol=1;
			}

			if(bol==0)
			{
				for(int i=0;i<5;i++)
				{
					printf("%d ",perm1[i]);
				}
				printf("\n");
				for(i=0;i<5;i++)
				{
					printf("%d ",perm2[i]);
				}
				printf("\n");
				printf("5 ");
				for(i=0;i<4;i++)
				{
					printf("%d ",perm3[i]);
				}
				printf("\n");
				printf("%d ",perm4[0]);
				printf("5 ");
				printf("%d ",perm4[1]);
				printf("%d ",perm4[2]);
				printf("%d ",perm4[3]);
				printf("\n");
				printf("%d ",perm4[0]);
				printf("%d ",perm4[1]);
				printf("5 ");
				printf("%d ",perm4[2]);
				printf("%d ",perm4[3]);
				return;
			}
			position5=n5-1;
			ROTATE5(position5);
			while(perm5[position5]==position5+1&&position5!=0)
			{
				position5--;
				ROTATE5(position5);
			}
		}

			position4=n4-1;
			ROTATE4(position4);
			while(perm4[position4]==position4+1&&position4!=0)
			{
				position4--;
				ROTATE4(position4);
			}
		}
			position3=n3-1;
			ROTATE3(position3);
			while(perm3[position3]==position3+1&&position3!=0)
			{
				position3--;
				ROTATE3(position3);
			}
		}
			position2=n2-1;
			ROTATE2(position2);
			while(perm2[position2]==position2+1&&position2!=0)
			{
				position2--;
				ROTATE2(position2);
			}
		}
			position1=n1-1;
			ROTATE1(position1);
			while(perm1[position1]==position1+1&&position1!=0)
			{
				position1--;
				ROTATE1(position1);
			}
		}
		printf("finish\n");
    }
