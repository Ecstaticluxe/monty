#include "monty.h"

/**
 * execute_opcode - executes the opcode based on the instruction table
 * @content: opcode and argument string
 * @stack: stack head
 * @line_number: line number in the Monty file
 * @file: Monty file
 * Return: 0 on success, 1 on failure
 */
int execute_opcode(char *content, stack_t **stack,
		unsigned int line_number, FILE *file)
{
	unsigned int i;
	char *opcode = strtok(content, " \n\t");

	instruction_t opcodes[] = {
		{"push", my_push},
		{"pall", my_pall},
		{NULL, NULL}
	};


	if (opcode && opcode[0] == '#')
		return (0);

	sup.arg = strtok(NULL, " \n\t");

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return (0);
		}
	}

	if (opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		release_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
