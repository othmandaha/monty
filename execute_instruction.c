#include "monty.h"

#include <stdlib.h>
#include <stdio.h>
/**
 * execute_instruction - f
 * @line: line
 * @line_number: num
 * @stack: stack
 */

void execute_instruction(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode, *arg;

	opcode = strtok(line, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");

		if (arg == NULL || !is_numeric(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		div_op(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotl(stack, line_number);
	else if (strcmp(opcode, "rotr") == 0)
		rotr(stack, line_number);
	else if (strcmp(opcode, "queue") == 0)
		queue(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
