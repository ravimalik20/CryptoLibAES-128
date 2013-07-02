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

void main()
{	struct block data,key,temp;
	//unsigned char c1[16]={0x32,0x88,0x31,0xe0,0x43,0x5a,0x31,0x37,0xf6,0x30,0x98,0x07,0xa8,0x8d,0xa2,0x34};
	//unsigned char c2[16]={0x2b,0x28,0xab,0x09,0x7e,0xae,0xf7,0xcf,0x15,0xd2,0x15,0x4f,0x16,0xa6,0x88,0x3c};
	unsigned char c1[16]="Hello World. 123";
	unsigned char c2[16]="My New Password.";	
	int i,j,c=0;
	struct block round_key[11];
	// Initializing Data and Key
	for(i=0;i<4;i++)
	{	for(j=0;j<4;j++)
		{	data.b[i][j]=c1[c];
			key.b[i][j]=c2[c];
			c++;	
		}
	}

	printf("Data and key before encryption:");
	printf("\n Data:\n");
	print_block(data);
	printf("\n Key:\n");
	print_block(key);

	printf("Generating All the round Keys:");
	round_key[0]=key;
	temp=key;	
	for(i=0;i<10;i++)
	{	temp=next_key(temp,i);
		round_key[i+1]=temp;
	}
	printf("All the keys generated.");

	data=encrypt(data,round_key);

	printf("Data after encryption:");
	printf("\n Data:\n");
	print_block(data);

	printf("\nData After Decryption\n");
	data=decrypt(data,round_key);
	print_block(data);
}
