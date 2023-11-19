#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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

/**
 * struct main_s - Environ for Monty
 * @arg: value
 * @file: pointer to monty
 * @content: line data
 * @lifi: flag to change stack <-> queue
 * Description: Carries values through the program for Monty interpreter
 */
typedef struct main_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} main_t;

extern main_t sup;

int is_valid_integer(const char *str);
void exit_with_error(stack_t **head, unsigned int checker);
void my_push(stack_t **head, unsigned int checker);
void my_pall(stack_t **head, unsigned int line_number);
void my_pint(stack_t **head, unsigned int line_number);
void my_pop(stack_t **head, unsigned int line_number);
void my_swap(stack_t **head, unsigned int line_number);
void my_add(stack_t **head, unsigned int line_number);
void my_nop(stack_t **head, unsigned int line_number);
void my_sub(stack_t **head, unsigned int line_number);
void my_div(stack_t **head, unsigned int line_number);
void my_mul(stack_t **head, unsigned int line_number);
void my_mod(stack_t **head, unsigned int line_number);
void my_pchar(stack_t **head, unsigned int line_number);
void my_pstr(stack_t **head, unsigned int line_number);
void my_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number);
void my_rotl(stack_t **head, __attribute__((unused)) unsigned int line_number);
void my_stack(stack_t **head, unsigned int line_number);
void my_queue(stack_t **head, unsigned int line_number);
void process_file(const char *file_path);
int execute_opcode(char *content, stack_t **stack,
unsigned int line_number, FILE *file);
void release_stack(stack_t *head);
void add_queue(stack_t **head, int n);
void add_node(stack_t **head, int n);

#endif
