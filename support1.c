#include "monty.h"

/**
 * add_node - Function adds node
 * @head: Head
 * @n: n val
 * Return: Nothing
 */
void add_node(stack_t **head, int n)
{
	stack_t *chay, *emu;

	emu = *head;
	chay = malloc(sizeof(stack_t));
	if (chay == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (emu)
		emu->prev = chay;

	chay->n = n;
	chay->next = *head;
	chay->prev = NULL;
	*head = chay;
}
