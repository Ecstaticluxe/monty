#include "monty.h"
/**
 *my_rotl- Function rotates the stack
 *@head: Head
 *@line_number: line number to the function
 *Return: Nothing
 */
void my_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *emu = *head, *chay;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	chay = (*head)->next;
	chay->prev = NULL;
	while (emu->next != NULL)
	{
		emu = emu->next;
	}
	emu->next = *head;
	(*head)->next = NULL;
	(*head)->prev = emu;
	(*head) = chay;
}
