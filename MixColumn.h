#include<stdio.h>
#include"MixColumnData.h"

struct block
{	unsigned char b[4][4];
};

struct block mix_column(struct block data,int matrix[4][4])
{	struct block temp;
	int i,j,k;
	int x,y;
	unsigned char r;
	for(i=0;i<4;i++)
	{	for(j=0;j<4;j++)
		{	temp.b[i][j]=0x00;
			for(k=0;k<4;k++)
			{	x=matrix[i][k];
				y=(int)data.b[k][j];
				switch(x)
				{	case 1:
						r=y;
						break;
					case 2:
						r=mix_col_2[y];
						break;
					case 3:
						r=mix_col_3[y];
						break;
					case 9:
						r=mix_col_9[y];
						break;
					case 11:
						r=mix_col_11[y];
						break;
					case 13:
						r=mix_col_13[y];
						break;
					case 14:
						r=mix_col_14[y];
						break;					
				}	
				temp.b[i][j]=temp.b[i][j]^(r);
			}
		}
	}
	return temp;
}
