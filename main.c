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
	return (words);
}

/*int check_opcode(char *str)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pint", pall},
		{NULL, NULL},
	};

	while (opcodes[i][0])
	{
		if (strcmp(opcodes[i][0], str) == 0)
			return((opcodes[i].f)(head, lineno));
		i++;
	}

	dprintf(2, "L%s: unknown instruction %s\n", lineno, str);
	exit(EXIT_FAILURE);
}*/


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
	size_t len = 0;
	ssize_t line_read;
	char *line = NULL, **words = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	while ((line_read = getline(&line, &len, fd)) != -1)
	{
		lineno++;
		words = parse_line(line);
		if (words)
		{
			if (strcmp(words[0], "push") == 0 && isdigit(atoi(words[1])))
				push(atoi(words[1]));
			else if (strcmp(words[0], "push") == 0
				&& (!(isdigit(atoi(words[1]))) || !words[1]))
			{
				dprintf(2, "L%s: usage: push integer\n", lineno);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(fd);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
