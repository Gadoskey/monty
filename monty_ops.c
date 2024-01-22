#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		handle_error("Error: malloc failed", 0);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
/**
 * pall - Prints all values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * free_stack - Frees the entire stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}
/**
 * handle_error - Handles errors by printing an error message and exiting
 * @message: Error message to be printed
 * @line_number: Line number in the Monty byte code file
 */
void handle_error(const char *message, unsigned int line_number)
{
	fprintf(stderr, "%s %u\n", message, line_number);
	exit(EXIT_FAILURE);
}
