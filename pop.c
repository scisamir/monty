#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: current line number of the bytecode file
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	pall(stack, line_number);

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->prev;
	free(temp);
	temp = NULL;

	if (*stack)
		(*stack)->next = NULL;
}
