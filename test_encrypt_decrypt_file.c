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

void encrypt()
{
	FILE *fp_input, *fp_output;
	fp_input = fopen("README", "rb");
	fp_output = fopen("readme.enc", "wb");

	char *key = "mynameisslimshad";

	aes_encrypt_file(fp_input, fp_output, key);

	fclose(fp_input);
	fclose(fp_output);
}

void decrypt()
{
	FILE *fp_input, *fp_output;
	fp_input = fopen("readme.enc", "rb");
	fp_output = fopen("readme.dec", "wb");

	char *key = "mynameisslimshad";

	aes_decrypt_file(fp_input, fp_output, key);

	fclose(fp_input);
	fclose(fp_output);
}

void main(int argc, char* argv[])
{	
	encrypt();
	decrypt();
}
