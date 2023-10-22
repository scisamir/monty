#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @lineno: current line number of input file
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int lineno)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}

	(*stack)->prev->n += (*stack)->n;
	temp = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->next = NULL;
	free(temp);
}
