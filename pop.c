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

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	free(*stack);
	*stack = temp;
	if (*stack)
		(*stack)->next = NULL;
}
