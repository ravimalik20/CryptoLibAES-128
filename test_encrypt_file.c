#include"encrypt_file.h"

void main(int argc, char* argv[])
{	struct block key;
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"rb");
	fp2=fopen(argv[3],"wb");
	// Converting the key provided as string into key object.
	key=prepare_key(argv[2]);
	encrypt_file(fp1,key,fp2);
	fclose(fp1);
	fclose(fp2);
}
