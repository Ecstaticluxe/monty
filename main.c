#include "monty.h"
/**
 *main - entry point
 *@argc: argument count
 *@argv: argument vectore
 *Return: 0;
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t size = 0;
	FILE *file = NULL;
	ssize_t bufsize;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	store.head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	store.myfile = file;
	bufsize = getline(&buffer, &size, file);
	while (bufsize != -1)
	{
		line_number++;
		store.content = buffer;
		execute_cmd(&stack, line_number, buffer);
		stack = NULL;
		bufsize = getline(&buffer, &size, file);
	}
	free_stack();
	fclose(file);
	return (0);
}
/**
 *_strdup - duplicate a string
 *@str: pointer to a string
 *Return: str1
 */
char *_strdup(char *str)
{
	char *str1;
	int i, size = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		size++;
	}
	size++;

	str1 = malloc(sizeof(char) * size);

	for (i = 0; str[i] != '\0'; i++)
	{
		str1[i] = str[i];
	}
	str1[i] = '\0';
	return (str1);
}
