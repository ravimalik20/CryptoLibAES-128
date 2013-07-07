/*==========================================================================================
||	
||	Copyright (C) 2013  Ravi Malik
||	
||	This program is free software; you can redistribute it and/or
||	modify it under the terms of the GNU General Public License
||	as published by the Free Software Foundation; either version 2
||	of the License, or (at your option) any later version.
||	
||	This program is distributed in the hope that it will be useful,
||	but WITHOUT ANY WARRANTY; without even the implied warranty of
||	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
||	GNU General Public License for more details.
||	
||	You should have received a copy of the GNU General Public License
||	along with this program; if not, write to the Free Software
||	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
||	
||
*==========================================================================================*/

#include"aes.h"
#include<stdio.h>

void encrypt_file(FILE *fp_i, struct block key, FILE *fp_o)
{	//Takes the FILE pointer of the file to encrypt, block object containing the key and the file pointer of the file to place encrypted data. It does not close the file pointers passed as arguments and it is the responsibility of the programmer to close it while using it in a wrapper function.
	struct block data;
	struct block round_key[11];
	generate_round_keys(key,round_key);	
	unsigned long size=file_size(fp_i);
	int a,b;
	a=size/16;	// Number of 4*4 blocks fetchable from file.
	b=size%16;	// Number of bytes left to be fetched into the last block of the file.
	int i;		// Counter of number of complete 4*4 blocks fetchable from file.
	int j,k;
	for(i=0;i<a;i++)
	{	for(j=0;j<4;j++)
		{	for(k=0;k<4;k++)
			{	fread(&data.b[j][k],sizeof(data.b[j][k]),1,fp_i);
			}
		}
		data=encrypt(data,round_key);
		for(j=0;j<4;j++)
		{	for(k=0;k<4;k++)
			{	fwrite(&data.b[j][k],sizeof(data.b[j][k]),1,fp_o);
			}
		}
	}
	int c=b;		
	j=0;
	k=0;	
	while(c!=0)
	{	if(k==4)
		{	k=0;
			j++;
		}
		fread(&data.b[j][k],sizeof(data.b[j][k]),1,fp_i);
		k++;
		c--;
	}
	if(k==4)
	{	k=0;
		j++;
	}
	c=(16-b);
	while(c!=0)
	{	if(k==4)
		{	k=0;
			j++;
		}
		data.b[j][k]=(unsigned char)(16-b);
		k++;
		c--;
	}
	data=encrypt(data,round_key);
	for(j=0;j<4;j++)
	{	for(k=0;k<4;k++)
		{	fwrite(&data.b[j][k],sizeof(data.b[j][k]),1,fp_o);
		}
	}
}

int decrypt_file(FILE *fp_i, struct block key, FILE *fp_o)
{	//Takes the FILE pointer of the file to decrypt, block object containing the key and the file pointer of the file to place decrypted data. It does not close the file pointers passed as arguments and it is the responsibility of the programmer to close it while using it in a wrapper function.
	struct block data;
	struct block round_key[11];
	generate_round_keys(key,round_key);	
	unsigned long size=file_size(fp_i);
	int a,b;
	a=size/16;	// Number of 4*4 blocks fetchable from file.
	b=size%16;	// Number of bytes left to be fetched into the last block of the file.
	int i;		// Counter of number of complete 4*4 blocks fetchable from file.
	int j,k;
	for(i=0;i<a-1;i++)
	{	for(j=0;j<4;j++)
		{	for(k=0;k<4;k++)
			{	fread(&data.b[j][k],sizeof(data.b[j][k]),1,fp_i);
			}
		}
		data=decrypt(data,round_key);
		for(j=0;j<4;j++)
		{	for(k=0;k<4;k++)
			{	fwrite(&data.b[j][k],sizeof(data.b[j][k]),1,fp_o);
			}
		}
	}
	for(j=0;j<4;j++)
	{	for(k=0;k<4;k++)
		{	fread(&data.b[j][k],sizeof(data.b[j][k]),1,fp_i);
		}
	}
	data=decrypt(data,round_key);
	char padd_size;
	padd_size=data.b[3][3];
	int c=(int)padd_size;
	j=3;
	k=3;
	while(c!=0)
	{	if(k<0)
		{	k=3;
			j--;
		}
		if(data.b[j][k]!=padd_size)
		{	return -1;
		}
		k--;	
		c--;	
	}
	c=16-((int)padd_size);
	j=0;
	k=0;
	while(c!=0)
	{	if(k==4)
		{	k=0;
			j++;
		}
		fwrite(&data.b[j][k],sizeof(data.b[j][k]),1,fp_o);
		k++;
		c--;
	}
	return 0;
}
