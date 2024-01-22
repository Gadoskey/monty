#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	execute_instructions(file);
	fclose(file);
	return (EXIT_SUCCESS);
}
/**
 * execute_instructions - Executes Monty byte code instructions from a file
 * @file: File pointer to the Monty byte code file
 */
void execute_instructions(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode, *arg;
	instruction_t *instruction;

	while ((read_bytes = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[read_bytes - 1] == '\n')
			line[read_bytes - 1] = '\0';
		if (read_bytes > 1)
		{
			opcode = strtok(line, " ");
			arg = strtok(NULL, " ");
			if (opcode != NULL)
			{
				instruction = get_instruction(opcode);
				if (instruction != NULL)
				{
					if (arg != NULL)
						instruction->f(&stack, line_number);
					else
						instruction->f(&stack, line_number);
				}
				else
				{
					fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
					free(line);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	free(line);
	free_stack(stack);
}
/**
 * get_instruction - Finds the instruction structure for a given opcode
 * @opcode: Opcode to search for
 * Return: Pointer to the instruction structure or NULL if not found
 */
instruction_t *get_instruction(char *opcode)
{
	int i;
	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&instructions[i]);
	}
	return (NULL);
}
