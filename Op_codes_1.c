#include "monty.h"

/**
 * add_1 - Adds the top two elements of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void add_1(stack_t **stacks, unsigned int line_num)
{
	int Sum;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		print_errors(8, line_num, "add_1");

	(*stacks) = (*stacks)->next;
	Sum = (*stacks)->n + (*stacks)->prev->n;
	(*stacks)->n = Sum;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}

/**
 * nop_1 - Does nothing.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void nop_1(stack_t **stacks, unsigned int line_num)
{
	(void)stacks;
	(void)line_num;
}

/**
 * sub_nodes - Subtracts the top element of the stacks from the
 * second top element of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void sub_1(stack_t **stacks, unsigned int line_num)
{
	int difference;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)

		print_errors(8, line_num, "sub_1");


	(*stacks) = (*stacks)->next;
	difference = (*stacks)->n - (*stacks)->prev->n;
	(*stacks)->n = difference;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}

/**
 * div_nodes - Divides the second top element of the stacks
 * by the top element of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void div_nodes(stack_t **stacks, unsigned int line_num)
{
	int division;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		print_errors(8, line_num, "div");

	if ((*stacks)->n == 0)
		print_errors(9, line_num);
	(*stacks) = (*stacks)->next;
	division = (*stacks)->n / (*stacks)->prev->n;
	(*stacks)->n = division;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}

/**
 * mul - Multiplies the second top element of the stacks
 * with the top element of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */
void mul(stack_t **stacks, unsigned int line_num)
{
	int product;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		print_errors(8, line_num, "mul");

	(*stacks) = (*stacks)->next;
	product = (*stacks)->n * (*stacks)->prev->n;
	(*stacks)->n = product;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}

