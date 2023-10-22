#include "monty.h"

/**
 * free_stack - free stack
 * @stack: the stack to be freed
 *
 * Return: Nothing
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->prev;
		free(temp);
	}
}


/**
 * free_words - frees parse_line output
 * @words: to be freed
 *
 * Return: Nothing
 */

void free_words(char **words)
{
	int i;

	if (words != NULL)
	{
		for (i = 0; words[i]; i++)
			free(words[i]);
		free(words);
	}
}
