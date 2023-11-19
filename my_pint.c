#include "monty.h"
/**
 * my_pint - Function to print top
 * @head: Head
 * @line_number: line number of the top
 * Return: Nothing
 */
void my_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*head)->n);
	}

}
