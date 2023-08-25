#include "monty.h"

/**
 * push - pushes a new member to the stack
 * @num: the number to be pushed to the stack
 *
 * Return: On Success, EXIT_SUCCESS. On failure, EXIT_FAILURE
 */

int push(int num, stack_t **stack_top)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = *stack_top;
	new->n = num;
	new->next = NULL;

	*stack_top = new;

	return (EXIT_SUCCESS);
}
