#include <stdio.h>
#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_push(stack_t **head, unsigned int counter)
{
    int j = 0;
    int flag = 0;

    if (bus.arg == NULL || bus.arg[0] == '\0')  // Check for empty argument
    {
        fprintf(stderr, "L%d: push: empty argument\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    {
        fprintf(stderr, "L%d: push: \"%s\" is not a valid integer\n", counter, bus.arg);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    // Convert bus.arg to an integer and push it onto the stack
    int value = atoi(bus.arg);
    push_stack(head, value);  // Assuming you have a push_stack function

    printf("Pushing valid integer: %s\n", bus.arg);
}
