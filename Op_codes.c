#include "monty.h"

/**
 * push - Adds a node to the top of the stacks.
 * @Newa_node: Pointer to the new node to be pushed.
 * @line_num: Integer representing the line number of the opcode.
 */

void push(stack_t **Newa_node, unsigned int line_num)
{
	
	stack_t *temp;
	(void) line_num;

	if (Newa_node == NULL || *Newa_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *Newa_node;
		return;
	}
	temp = head;
	head = *Newa_node;
	head->next = temp;
	temp->prev = head;

}

/**
 * print_the_entire_stacks - Prints all the values in a stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: line number of  the opcode.
 */

void print_the_entire_stacks(stack_t **stacks,
		__attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stacks == NULL)
		exit(EXIT_FAILURE);
	temp = *stacks;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_stachs_tops - Prints the top node of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */

void print_stachs_tops(stack_t **stacks, unsigned int line_num)
{
	if (stacks == NULL || *stacks == NULL)
		print_errors(6, line_num);
	printf("%d\n", (*stacks)->n);
}

/**
 * pop - Removes the top node from the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */


void pop(stack_t **stacks, unsigned int line_num)
{
	stack_t *temp;

	if (stacks == NULL || *stacks == NULL)
		print_errors(7, line_num);

	temp = *stacks;
	*stacks = temp->next;
	if (*stacks != NULL)
		(*stacks)->prev = NULL;
	free(temp);
}

/**
 * Swaps - Swaps the top two elements of the stacks.
 * @stacks: Double pointer pointing to the top node of the stacks.
 * @line_num: Integer representing the line number of the opcode.
 */


void Swaps(stack_t **stacks, unsigned int line_num)
{
	stack_t *temp;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		print_errors(8, line_num, "Swaps");
	temp = (*stacks)->next;
	(*stacks)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stacks;
	temp->next = *stacks;
	(*stacks)->prev = temp;
	temp->prev = NULL;
	*stacks = temp;
}
