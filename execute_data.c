#include "monty.h"

/**
 * execute_opcode - executes the opcode based on the instruction table
 * @stack: Stack head
 * @line_number: line number in the monty file
 * @file: Monty file
 * @content: opcode and argument string
 * Return: 0 on success, -1 on failure
 */
int execute_opcode(char *content, stack_t **stack,
		unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"nop", my_nop},
		{"add", my_add},

		{NULL, NULL},
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	sup.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opcode)
	{
		if (strcmp(opcode, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		release_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
