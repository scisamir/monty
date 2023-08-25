#ifndef __MONTY_H__
#define __MONTY_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>


/*ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int dprintf(int fd, const char *format, ...);
char *strdup(const char *s);*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


extern stack_t *top;
extern int lineno;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char **parse_line(char *str);
int check_opcode(char *str, int lineno, stack_t **stack);
int push(int num, stack_t **stack_top);
void pall(stack_t **stack, unsigned int line_number);

#endif /* __MONTY_H__ */