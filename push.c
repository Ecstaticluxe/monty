#include <stdio.h>
#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int j = 0;
	int flag = 0;

for (; bus.arg[j] != '\0'; j++)
{
if ((bus.arg[j] == '-' && j == 0) || (bus.arg[j] > '9' || bus.arg[j] < '0'))
	{
	flag = 1;
break;
	}
}

if (flag == 1)
	{
fprintf(stderr, "L%d: push: \"%s\" is not a valid integer\n",
		counter, bus.arg);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
  printf("Pushing valid integer: %s\n", bus.arg);
}
