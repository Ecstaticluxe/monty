#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void process_file(const char *file_path);
main_t sup;
/**
 * main - my main entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	process_file(argv[1]);

	return (0);
}

/**
 * process_file - processes the Monty file and executes the opcodes
 * @file_path: path to the Monty file
 */
void process_file(const char *file_path)
{
	FILE *file = fopen(file_path, "r");
	char *content = NULL;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		line_number++;

		if (read_line > 0)
		{
			sup.file = file;
			sup.content = content;
			execute_opcode(content, &stack, line_number, file);
		}

		free(content);
	}

	release_stack(stack);
	fclose(file);
}
