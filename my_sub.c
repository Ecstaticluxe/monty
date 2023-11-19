#include "monty.h"
/**
 *my_sub- Function to handle subtration
 *@head: Head
 *@line_number: line number to the function
 *Return: Nothing
 */
void my_sub(stack_t **head, unsigned int line_number)
{
	stack_t *nwachi;
	int emul;
	int element;

	nwachi = *head;
	for (element = 0; nwachi != NULL; element++)
		nwachi = nwachi->next;
	if (element < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	nwachi = *head;
	emul = nwachi->next->n - nwachi->n;
	nwachi->next->n = emul;
	*head = nwachi->next;
	free(nwachi);
}
