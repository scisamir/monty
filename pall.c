#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: the stack
 * @line_number: current line number of the bytecode file
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
		return;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}
