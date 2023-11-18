#include "monty.h"
/**
 * my_pall - prints stack
 * @head: Head
 * @line_number: line info
 */
void my_pall(stack_t **head, unsigned int line_number)
{
	stack_t *data;
	(void)line_number;

	data = *head;
	if (data == NULL)
	{
		return;
	}
	while (data)
	{
		printf("%d\n", data->n);
		data = data->next;
	}
}
