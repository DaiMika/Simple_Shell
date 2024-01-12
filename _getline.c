#include "shell.h"

#define BUFF 150

/**
 * read_input - Read input from the standard input into a buffer.
 * @buffer: The buffer to store the input.
 * @index: The current index in the buffer.
 * @bytesRead: The number of bytes read.
 * Return: 0 on success, -1 on failure.
 */
int read_input(char *buffer, int *index, int *bytesRead)
{
	if (*index == *bytesRead)
	{
		*bytesRead = read(STDIN_FILENO, buffer, BUFF);

		if (*bytesRead <= 0)
		{
			return (-1);
		}

		*index = 0;
	}

	return (0);
}

/**
 * allocate_line_buffer - Allocate memory for the line buffer.
 * @line: The current line buffer.
 * @line_len: The length of the line buffer.
 * Return: 0 on success, -1 on failure.
 */
int allocate_line_buffer(char **line, int line_len)
{
	if (line_len % BUFF == 0)
	{
		*line = realloc(*line, line_len + BUFF + 1);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	return (0);
}

/**
 * _getline - Read a line from the standard input.
 * Return: A dynamically allocated string containing the line.
 *         NULL if an error occurs or end of file is reached.
 */
char *_getline(void)
{
	static char buffer[BUFF];
	static int index;
	static int bytesRead;
	char curr_input;
	char *line = NULL;
	int line_len = 0;

	while (1)
	{
		if (read_input(buffer, &index, &bytesRead) == -1)
		{
			if (line != NULL)
			{
				free(line);
			}
			return (NULL);
		}

		if (allocate_line_buffer(&line, line_len) == -1)
		{
			if (line != NULL)
			{
				free(line);
			}
			return (NULL);
		}

		curr_input = buffer[index++];

		if (curr_input == '\n')
		{
			line[line_len] = '\0';
			return (line);
		}

		line[line_len++] = curr_input;
	}
}

