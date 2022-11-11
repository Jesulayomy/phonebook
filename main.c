#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>

void add_entry(void);
void _exist(void);
void _countl(void);

/**
 * main - stores data in a container
 *
 *
 *
 * Return: 0 at successful exit
 */
int main(void)
{
	char m;

	printf("Enter an operation no to select\n");
	printf("1. Add new entry\n"
		"2. Delete Entry\n"
		"#. Modify entry\n"
		"3. View all entries\n");

	scanf("%c", &m);

	switch (m)
	{
	case '1':
	_exist();
	add_entry();
	break;
	case '2':
	printf("Not ready foo\n");
	/* delete a line from the file */
	case '3':
	/* open the file and display its contents */
	break;
	default:
	printf("Wrong selection\n");
	}

	_countl();

	return (0);
}

void add_entry(void)
{
	FILE *fptr;
	char *name, *phone;

	name = malloc(sizeof(char) * 11);
	if (name == NULL)
	{
		printf("Unable to create: memfault(263)\n");
		return;
	}

	phone = malloc(sizeof(char) * 15);
	if (phone == NULL)
	{
		printf("Unable to create: memfault(267)\n");
		return;
	}

	fptr = fopen("./phonebook.txt", "a");
	printf("Enter your surname\n");
	scanf("%s", name);
	fprintf(fptr, "%10s\t", name);
	printf("Enter your firstname\n");
	scanf("%s", name);
	fprintf(fptr, "|\t%10s\t", name);
	printf("Enter your phone number, beginning with country code\n");
	scanf("%s", phone);
	fprintf(fptr, "|\t%s\n", phone);
	fclose(fptr);

	return;
}

void _exist(void)
{
FILE *nw;

nw = fopen("./phonebook.txt", "r");
if (nw == NULL)
{
	nw = fopen("./phonebook.txt", "w");
	printf("Creating file in current directory ...\n\n");
	fprintf(nw, "Firstname \t|\t  Lastname\t|\tPhone Number\n");
	fprintf(nw, "________________|_______________________|___________________\n");
	fclose(nw);
	return;
}

printf("Opening the existing file to modify\n\n");
fclose(nw);
return;
}

void _countl(void)
{
	FILE *lc;
	int line = 0;
	char c;

	lc = fopen("./phonebook.txt", "r");

	while ((c = fgetc(lc) ) != 10)
		line++;

	printf("%d lines\n", line);
}





