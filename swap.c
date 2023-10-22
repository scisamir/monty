#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @lineno: current line number of input file
 *
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int lineno)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
