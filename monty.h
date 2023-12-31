#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/** Stack **/

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

extern stack_t *head;

/* Struct */

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

typedef void (*opcode_function)(stack_t **, unsigned int);

/* Data structure operations*/
stack_t *create_node(int data);
void Free_nodes(void);
void call_function(opcode_function func, char *op_code, char *num, int line_number, int data_structure);
void find_function(char *opcode, char *opcode_argument, int line_number, int data_structure);
int Tokenize_q(char *input, int line_number, int data_structure);
void open_file(char *pathname);
void read_input_in_file(FILE *fd);
void add_to_queue(stack_t **new_node, unsigned int line_number);

/* Opcode operations */
void push(stack_t **new_node, unsigned int line_number);
void print_the_entire_stacks(stack_t **stack, __attribute__((unused))unsigned int line_number);
void print_stachs_tops(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void Swaps(stack_t **stack, unsigned int line_number);
void add_1(stack_t **stack, unsigned int line_number);
void nop_1(stack_t **stack, unsigned int line_number);
void sub_1(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/** Print errors **/
void print_errors(int error_code, ...);
void print_eror(int error_code, ...);
void print_more_eror(int error_code, ...);

#endif
