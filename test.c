#include"aes.h"
#include<stdio.h>

/****************************************************************
Interface to this AES implementation:
1. struct block encrypt(struct block data,struct block key);
****************************************************************/

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
