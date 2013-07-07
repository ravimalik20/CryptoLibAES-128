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
