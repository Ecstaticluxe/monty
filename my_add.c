#include "monty.h"
/**
 * my_add - Adds top two elements
 * @head: head
 * @line_number: Line number to the top
 */
void my_add(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = first->next;
	sum = first->n + second->n;
	second->n = sum;
	*head = second;
	free(first);
}
