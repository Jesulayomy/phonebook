#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>

void add_entry();
void _exist();

/**
 * main - stores data in a container
 *
 *
 *
 * Return: 0 at successful exit
 */
int main()
{
	
	printf("Enter an operation no to select\n");
	printf("1. Add new entry\n"
		"2. Delete Entry\n"
		"#. Modify entry\n"
		"3. View all entries\n");

	_exist();
	add_entry();

	return (0);
}

void add_entry()
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

void _exist()
{
	FILE *new;

	new = fopen("./phonebook.txt", "r");
	if (new == NULL)
	{
		new = fopen("./phonebook.txt", "w");
		fprintf(new, "Firstname \t|\t  Lastname\t|\tPhone Number\n");
		fprintf(new, "________________|_______________________|___________________\n");
		fclose(new);
		return;
	}

	fclose(new);
	return;
}


