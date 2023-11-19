#include "monty.h"
/**
 * my_swap - Func adds the top two elem.
 * @head: Head
 * @line_number: Int line
 * Return: Null
 */
void my_swap(stack_t **head, unsigned int line_number)
{
	stack_t *first, *second;
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	tmp = first->n;

	first->n = second->n;
	second->n = tmp;
}
