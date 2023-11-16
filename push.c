#include <stderr.h>
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
    int n, j = 0;
    
    if (!bus.arg || !is_valid_integer(bus.arg))
    {
        print_error_and_exit(counter);
    }

    n = atoi(bus.arg);

    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

int is_valid_integer(const char *str)
{
    int j = 0;

    if (str[0] == '-')
    {
        j++;
    }

    for (; str[j] != '\0'; j++)
    {
        if (!isdigit(str[j]))
        {
            return 0;
        }
    }

    return 1;
}

void print_error_and_exit(unsigned int counter)
{
    fprintf(stderr, "L%d: usage: push integer\n", counter);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}
