#include "monty.h"
/**
 * add_queue - Function add node to the bottom
 * @head: Head
 * @n: n val
 * Return: Nothing
 */
void add_queue(stack_t **head, int n)
{
	stack_t *chay, *emu;

	emu = *head;

	chay = malloc(sizeof(stack_t));

	if (chay == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	chay->n = n;
	chay->next = NULL;
	if (emu)
	{
		while (emu->next)
			emu = emu->next;
	}
	if (!emu)
	{
		*head = chay;
		chay->prev = NULL;
	}
	else
	{
		emu->next = chay;
		chay->prev = emu;
	}
}
