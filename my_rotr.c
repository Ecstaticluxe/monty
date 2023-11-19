#include "monty.h"
/**
 *my_rotr- Function rotate the stk
 *@head: Head
 *@line_number: line number to the function
 *Return: Nothing
 */
void my_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *emu;

	emu = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (emu->next)
	{
		emu = emu->next;
	}
	emu->next = *head;
	emu->prev->next = NULL;
	emu->prev = NULL;
	(*head)->prev = emu;
	(*head) = emu;
}
