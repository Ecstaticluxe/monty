#include "monty.h"
/**
 * my_div - Function to divide the top two elements
 * @head: Head
 * @line_number: line number of the function
 * Return: Nothing
 */
void my_div(stack_t **head, unsigned int line_number)
{
	stack_t *nwachi;
	int s;
	int emul;

	s = 0;

	nwachi = *head;
	while (nwachi)
	{
		nwachi = nwachi->next;
		s++;
	}
	if (s < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	nwachi = *head;
	if (nwachi->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	emul = nwachi->next->n / nwachi->n;
	nwachi->next->n = emul;
	*head = nwachi->next;
	free(nwachi);
}








