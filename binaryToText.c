#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary_database.h"

void main(int args, char** argv)
{
	FILE *ifp;
	char ch;
	int x;

	ifp = fopen(argv[1], "r");
	if (ifp == NULL)
   	{
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   	}

	ofp = fopen("textToBinary.txt", "w");

	while((ch = fgetc(ifp)) != EOF)
	{	
		
	}

	fclose(ifp);
	fclose(ofp);
}