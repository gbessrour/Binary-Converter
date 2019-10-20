0#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary_database.h"

FILE *ofp;

void isChar(char character);
void isSpecial(char symbol);
void isDigit(int number);

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

	ofp = fopen("binaryToText.txt", "w");

	while((ch = fgetc(ifp)) != EOF)
	{	
		if (ch == ' ')
			fprintf(ofp, "00100000");
		else if ((int) ch >= 48 && (int) ch <= 57)
			isDigit(ch - '0');
		else if (((int) ch >= 65 && (int) ch <= 90) || ((int) ch >= 97 && (int) ch <= 122))
			isChar(ch);
		else
			isSpecial(ch);
	}

	fclose(ifp);
	fclose(ofp);
}

void isChar(char character)
{	
	int x;

	if ((int) character >= 65 && (int) character <= 90)
	{
		x = character - 'A';
		fprintf(ofp, "%s ", upperCase[x]);
	} 
	else
	{
		x = character - 'a';
		fprintf(ofp, "%s ", lowerCase[x]);
	}
}

void isSpecial(char special)
{
	switch(special)
	{
		case '!': fprintf(ofp, "%s ", symbol[0]);
			break;
		case '"': fprintf(ofp, "%s ", symbol[1]);
			break;
		case '#': fprintf(ofp, "%s ", symbol[2]);
			break;
		case '$': fprintf(ofp, "%s ", symbol[3]);
			break;
		case '%': fprintf(ofp, "%s ", symbol[4]);
			break;
		case '&': fprintf(ofp, "%s ", symbol[5]);
			break;
		case '\'': fprintf(ofp, "%s ", symbol[6]);
			break;
		case '(': fprintf(ofp, "%s ", symbol[7]);
			break;
		case ')': fprintf(ofp, "%s ", symbol[8]);
			break;
		case '*': fprintf(ofp, "%s ", symbol[9]);
			break;
		case '+': fprintf(ofp, "%s ", symbol[10]);
			break;
		case ',': fprintf(ofp, "%s ", symbol[11]);
			break;
		case '-': fprintf(ofp, "%s ", symbol[12]);
			break;
		case '.': fprintf(ofp, "%s ", symbol[13]);
			break;
		case '/': fprintf(ofp, "%s ", symbol[14]);
			break;
		case ':': fprintf(ofp, "%s ", symbol[15]);
			break;
		case ';': fprintf(ofp, "%s ", symbol[16]);
			break;
		case '<': fprintf(ofp, "%s ", symbol[17]);
			break;
		case '=': fprintf(ofp, "%s ", symbol[18]);
			break;
		case '>': fprintf(ofp, "%s ", symbol[19]);
			break;
		case '?': fprintf(ofp, "%s ", symbol[20]);
			break;
		case '@': fprintf(ofp, "%s ", symbol[21]);
			break;
		case '[': fprintf(ofp, "%s ", symbol[22]);
			break;
		case ']': fprintf(ofp, "%s ", symbol[23]);
			break;
		case '^': fprintf(ofp, "%s ", symbol[24]);
			break;
		case '_': fprintf(ofp, "%s ", symbol[25]);
			break;
		case '`': fprintf(ofp, "%s ", symbol[26]);
			break;
		case '{': fprintf(ofp, "%s ", symbol[27]);
			break;
		case '|': fprintf(ofp, "%s ", symbol[28]);
			break;
		case '}': fprintf(ofp, "%s ", symbol[29]);
			break;
		case '~': fprintf(ofp, "%s ", symbol[30]);
			break;			
		default: 
			break;																										
	}
}

void isDigit(int number)
{
	switch(number)
	{
		case 0: fprintf(ofp, "%s ", digit[0]);
			break;
		case 1: fprintf(ofp, "%s ", digit[1]);
			break;
		case 2: fprintf(ofp, "%s ", digit[2]);
			break;
		case 3: fprintf(ofp, "%s ", digit[3]);
			break;
		case 4: fprintf(ofp, "%s ", digit[4]);
			break;	
		case 5: fprintf(ofp, "%s ", digit[5]);
			break;	
		case 6: fprintf(ofp, "%s ", digit[6]);
			break;	
		case 7: fprintf(ofp, "%s ", digit[7]);
			break;	
		case 8: fprintf(ofp, "%s ", digit[8]);
			break;	
		case 9: fprintf(ofp, "%s ", digit[9]);
			break;
		default:
			break;									
	}
}
