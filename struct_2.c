#include "monty.h"

/**
 * Tokenize_q - tokenizes the input
 * @input: line from the file
 * @line_number: line number
 * @data_structure:  If 0, nodes will be added as a stack.
 * If 1, nodes will be added as a queue.
 * Return: 0 If the data structure is a stack.
 * 1 if it's a queue.
 */

int Tokenize_q(char *input, int line_number, int data_structure)

{
	char *opcode, *opcode_argument;
	const char *delimiter = "\n ";

	if (input == NULL)
		print_errors(4);

	opcode = strtok(input, delimiter);
	if (opcode == NULL)
		return (data_structure);

	opcode_argument = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, opcode_argument, line_number, data_structure);
	return (data_structure);
}

/**
 * read_input_in_file - reads input after opening a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_input_in_file(FILE *fd)

{
	int line_number, data_structure = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		data_structure = Tokenize_q(buffer, line_number, data_structure);
	}
	free(buffer);
}

/**
 * open_file - opens a file
 * @path_name: file whose name is the string
 * pointed to by path_name and associates a stream with it
 * Return: void
 */

void open_file(char *path_name)
{
	FILE *fd = fopen(path_name, "r");

	if (path_name == NULL || fd == NULL)
		print_errors(2, path_name);

	read_input_in_file(fd);
	fclose(fd);
}
