#include "monty.h"
int check_integer(char *str);
void addNode(stack_t **stack);
/**
 *push - push elemnt in to the stack
 *@stack: pointer to the head pointer
 *@line_number: line number
 *Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int data;

	if (check_integer(store.data) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack();
		fclose(store.myfile);
		exit(EXIT_FAILURE);
	}
	data = atoi(store.data);
	*stack = store.head;
	if (*stack == NULL)
	{
		*stack = malloc(sizeof(stack_t));
		if (*stack == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack();
			free(store.data);
			fclose(store.myfile);
			exit(EXIT_FAILURE);
		}
		(*stack)->n = data;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		store.head = *stack;
	}
	else
	{
		(addNode(stack));
	}
}
/**
 *addNode - add node at the top of the stack
 *@stack: pointer to the head pointer
 *Return: void
 */
void addNode(stack_t **stack)
{
	int data = atoi(store.data);
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack();
		fclose(store.myfile);
		exit(EXIT_FAILURE);
	}
	newNode->n = data;
	newNode->next = *stack;
	(*stack)->prev = newNode;
	newNode->prev = NULL;
	*stack = newNode;
	store.head = *stack;
}
/**
 *check_integer - check the integer
 *@str: pointer to a string
 *Return: 1
 */
int check_integer(char *str)
{
	int i;

	if (!str)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] != '0')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
		continue;
	}
	return (0);
}
