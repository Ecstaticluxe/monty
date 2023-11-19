#include "monty.h"
/**
 * my_pop - Function to print the top
 * @head: Head
 * @line_number: line number to the top
 * Return: Nothing
 */
void my_pop(stack_t **head, unsigned int line_number)
{
	stack_t *data;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	data = *head;
	*head = data->next;
	free(data);
}
