#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>

void add_entry(void);
void _exist(void);
void _view(void);
void _delete(int);
void _modify(int);

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
	int rm;

	printf("Enter an operation no to select\n");
	printf("1. Add new entry\n"
		"2. Delete Entry\n"
		"3. Modify entry\n"
		"4. View all entries\n");

	scanf("%c", &m);

	switch (m)
	{
	case '1':
	_exist();
	add_entry();
	break;
	case '2':
	_view();
	printf("Enter a line to remove\n");
	scanf("%d", &rm);
	_delete(rm);
	_view();
	break;
	case '3':
	printf("Enter a line to edit\n");
	scanf("%d", &rm);
	_modify(rm);
	/* delete a line from the file */
	case '4':
	_view();
	/* open the file and display its contents */
	break;
	default:
	printf("Wrong selection\n");
	}

	return (0);
}

void _view(void)
{
	FILE *open;
	char view;

	open = fopen("./phonebook.txt", "r");

	printf("\n\n\t\t_______Phone-book________\n");
	while ((view = fgetc(open)) != EOF)
		putchar (view);

	fclose(open);
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

void _delete(int n)
{
	FILE *src, *temp;
	char c;
	int l = 1;

	/* accounting for table header */
	n += 2;

	/* open both files */
	src = fopen("./phonebook.txt", "r");
	if (src == NULL)
		return;
	temp = fopen("./temp.txt", "w");

	/* create a copy from src to temp.txt */
	for (;(c = fgetc(src)) != EOF;)
	{
		fprintf(temp, "%c", c);
	}

	fclose(src);
	fclose(temp);

	src = fopen ("./phonebook.txt", "w");
	temp = fopen ("./temp.txt", "r");

	/* write n lines, and skip n+1th line, write the remaining lines */
	for (;(c = fgetc(temp)) != EOF;)
	{
		if (n != l)
			fprintf(src, "%c", c);

		if (c == '\n')
			l++;
	}

	fclose(src);
	fclose(temp);

	remove("temp.txt");

}


/* change a line and reenter stuff */
void _modify(int n)
{
	FILE *src, *temp;
	char c;
	char *fname, *sname, *nphone;
	int l = 1;

	/* accounting for table header */
	n += 2;

	fname = malloc(sizeof(char) * 11);
	sname = malloc(sizeof(char) * 11);
	nphone = malloc(sizeof(char) * 15);

	printf("Enter your surname\n");
	scanf("%s", fname);
	printf("Enter your firstname\n");
	scanf("%s", sname);
	printf("Enter your phone number, beginning with country code\n");
	scanf("%s", nphone);

	/* open both files */
	src = fopen("./phonebook.txt", "r");
	if (src == NULL)
		return;
	temp = fopen("./temp.txt", "w");

	/* create a copy from src to temp.txt */
	for (;(c = fgetc(src)) != EOF;)
	{
		fprintf(temp, "%c", c);
	}

	fclose(src);
	fclose(temp);

	src = fopen ("./phonebook.txt", "w");
	temp = fopen ("./temp.txt", "r");

	/* write n lines, and skip n+1th line, write the remaining lines */
	for (;(c = fgetc(temp)) != EOF;)
	{
	if (n != l)
		fprintf(src, "%c", c);
	if (c == '\n' && n == l)
		fprintf(src, "%10s\t|\t%10s\t|\t%s\n", fname, sname, nphone);
	if (c == '\n')
		l++;
	}

	fclose(src);
	fclose(temp);

	remove("temp.txt");
}
