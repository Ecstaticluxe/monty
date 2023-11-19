#include "monty.h"
/**
 * my_pchar - Function to print from the top
 * @head: Head
 * @line_number: line number to the function
 * Return: Nothing
 */
void my_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *nwachi;

	nwachi = *head;
	if (!nwachi)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (nwachi->n > 127 || nwachi->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", nwachi->n);
}
