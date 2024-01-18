#include "monty.h"
/**
 * pop - fun
 * stack: stack
 * @line_number: um
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
