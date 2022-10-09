#include "monty.h"

/**
 * _pstr - prints a string
 * @stack: pointer to top of stack
 * @line_number: number of line opcode is on
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;

	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotates values on the stack to the left
 * @stack: pointer to top of stack
 * @line_number: number of line opcode is on
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux;
}

/**
 * _rotr - rotates values on the stack to the right
 * @stack: pointer to top of stack
 * @line_number: number of line opcode is on
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;
	while (runner->next)
		runner = runner->next;
	aux = runner ->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux;
}
