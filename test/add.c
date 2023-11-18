#include "monty.h"
/**
 *add - add the top elemnet to preceeding element and pop
 *@stack: pointer to the head pointer
 *@line_number: line number
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int count = 0;
	int x;
	stack_t *ptr = NULL;
	*stack = store.head;

	ptr = *stack;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack();
		fclose(store.myfile);
		exit(EXIT_FAILURE);
	}
	else
	{
		x = (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n + x;
		pop(stack, line_number);
	}
}
