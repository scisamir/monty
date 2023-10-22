#include "monty.h"

/**
 * push_err - handles wrong push command
 * @stack: the stack
 * @line_num: current line number of the bytecode file being read
 *
 * Return: Nothing
 */

int push_err(stack_t *stack, int line_num)
{
	free_stack(&stack);
	dprintf(2, "L%d: usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}


/**
 * push - pushes a new member to the stack
 * @num_char: the number to be pushed to the stack
 * @stack_top: pointer to a pointer to the top of the stack
 * @lineno: current line number of the bytecode file being read
 *
 * Return: On Success, EXIT_SUCCESS. On failure, EXIT_FAILURE
 */

int push(char *num_char, stack_t **stack_top, int lineno)
{
	int num;
	stack_t *new = NULL;

	if (!num_char)
		return (push_err(*stack_top, lineno));

	if (strspn(num_char, "-0123456789") != strlen(num_char))
		return (push_err(*stack_top, lineno));

	num = atoi(num_char);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	new->prev = *stack_top;
	new->n = num;
	new->next = NULL;

	*stack_top = new;

	return (EXIT_SUCCESS);
}
