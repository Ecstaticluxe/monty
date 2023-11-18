#include "monty.h"
/**
 * release_stack - Func frees list
 * @head: Head
 */
void release_stack(stack_t *head)
{
	stack_t *emu;

	emu = head;
	while (head)
	{
		emu = head->next;
		free(head);
		head = emu;
	}
}
