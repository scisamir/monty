#include "monty.h"

/**
 * parse_line - splits each line of monty into an array of words
 * @str: the line to be splitted
 *
 * Return: the array of words containing the splitted line
 */

char **parse_line(char *str)
{
	char *word, *str_copy;
	char **words;
	int len = 0, i = 0;

	str_copy = strdup(str);

	word = strtok(str, " \n");
	while (word)
	{
		len++;
		word = strtok(NULL, " \n");
	}

	words = malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
	{
		free(str_copy);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	word = strtok(str_copy, " \n");
	while (word)
	{
		words[i] = strdup(word);
		word = strtok(NULL, " \n");
		i++;
	}
	words[i] = NULL;
	free(str_copy);
	printf("---------------------\n");
	i = 0;
	while (words[i])
	{
		printf("%s\n", words[i]);
		i++;
	}
	printf("---------------------\n");
	return (words);
}

int check_opcode(char *str, int lineno, stack_t **stack)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{NULL, NULL},
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, str) == 0)
		{
			(opcodes[i].f)(stack, lineno);
			exit(EXIT_SUCCESS);
		}
		i++;
	}

	dprintf(2, "L%d: unknown instruction %s\n", lineno, str);
	exit(EXIT_FAILURE);
}


/**
 * main - Entry point to the monty program
 * @ac: argument count to main
 * @av: an array of arguments to main
 *
 * Return: On Success, EXIT_SUCCESS. On failure, EXIT_FAILURE
 */

int main(int ac, char *av[])
{
	FILE *fd;
	int lineno = 0, i = 0;
	size_t len = 0;
	ssize_t line_read;
	char *line = NULL, **words = NULL;
	stack_t *top = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_read = getline(&line, &len, fd)) != -1)
	{
		lineno++;
		words = parse_line(line);
		if (words)
		{
			if (strcmp(words[0], "push") == 0 && isdigit(atoi(words[1])))
				push(atoi(words[1]), &top);
			else
				check_opcode(words[0], lineno, &top);
		}

		free(line);
		if (words)
		{
			while (words[i])
			{
				free(words[i]);
				i++;
			}
			free(words);
		}
	}

	fclose(fd);
	exit(EXIT_SUCCESS);
}
