#include "monty.h"

/**
 * is_valid_integer - checks if a string represents a valid integer
 * @str: string to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_integer(const char *str)
{
	int j = 0;

	if (str[0] == '-')
		j++;

	for (; str[j] != '\0'; j++)
	{
		if (str[j] > '9' || str[j] < '0')
			return (0);
	}

	return (1);
}

/**
 * exit_with_error - exits the program with an error message
 * @head: stack head
 * @checker: line number
 */
void exit_with_error(stack_t **head, unsigned int checker)
{
	fprintf(stderr, "L%d: usage: push integer\n", checker);
	fclose(sup.file);
	free(sup.content);
	release_stack(*head);
	exit(EXIT_FAILURE);
}

/**
 * my_push - add node to the stack
 * @head: stack head
 * @checker: line number
 */
void my_push(stack_t **head, unsigned int checker)
{
	int n;

	if (!sup.arg || !is_valid_integer(sup.arg))
		exit_with_error(head, checker);
	n = atoi(sup.arg);

	if (sup.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
