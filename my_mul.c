#include "monty.h"
/**
 * my_mul - Function to multiply the top two element.
 * @head: Head
 * @line_number: line number of the function
 * Return: Nothing
 */
void my_mul(stack_t **head, unsigned int line_number)
{
	stack_t *nwachi;
	int s, emul;

	s = 0;

	nwachi = *head;
	while (nwachi)
	{
		nwachi = nwachi->next;
		s++;
	}
	if (s < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(sup.file);
		free(sup.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	nwachi = *head;
	emul = nwachi->next->n * nwachi->n;
	nwachi->next->n = emul;
	*head = nwachi->next;
	free(nwachi);
}
