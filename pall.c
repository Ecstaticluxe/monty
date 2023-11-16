 #include "monty.h"
/**
 * f_pall - prints all the values on the stack, starting from the top of the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/

void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;

    if (head == NULL || *head == NULL)
        return;

    h = *head;
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

