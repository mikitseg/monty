#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stacks by the top element of the stacks.
 * @stacks: Pointer to a pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void mod(stack_t **stacks, unsigned int line_num)
{
	int modulus;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)

		print_errors(8, line_num, "mod");


	if ((*stacks)->n == 0)
		print_errors(9, line_num);
	(*stacks) = (*stacks)->next;
	modulus = (*stacks)->n % (*stacks)->prev->n;
	(*stacks)->n = modulus;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}

/**
 * print_char - Prints the character at the top of the stacks
 * followed by a new line.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void print_char(stack_t **stacks, unsigned int line_num)
{
	int character;

	if (stacks == NULL || *stacks == NULL)
		print_more_eror(11, line_num);

	character = (*stacks)->n;
	if (character < 0 || character > 127)
		print_more_eror(10, line_num);
	printf("%c\n", character);
}

/**
 * print_string - Prints the string at the top of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void print_string(stack_t **stacks, unsigned int line_num)
{
	int character;
	stack_t *temp;

	(void) line_num;

	if (stacks == NULL || *stacks == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stacks;
	while (temp != NULL)
	{
		character = temp->n;
		if (character <= 0 || character > 127)
			break;
		printf("%c", character);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stacks to the bottom
 * and the second top element of the stacks becomes the first one.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void rotl(stack_t **stacks, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		return;

	temp = *stacks;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stacks;
	(*stacks)->prev = temp;
	*stacks = (*stacks)->next;
	(*stacks)->prev->next = NULL;
	(*stacks)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stacks to the top.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void rotr(stack_t **stacks, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		return;

	temp = *stacks;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stacks;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stacks)->prev = temp;
	(*stacks) = temp;
}
