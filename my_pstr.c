#include "monty.h"
/**
 * my_pstr - Function prints the string
 * @head: Head
 * @line_number: line number to the function
 * Return: Nothing
 */
void my_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;
	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
