#include "monty.h"

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *head, *ptr = *stack;

	if (ptr == NULL)
		return;

	while (ptr != NULL)
	{
		head = ptr;
		ptr = ptr->prev;
	}

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
