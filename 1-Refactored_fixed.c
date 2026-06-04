/**
 * 1-refactored_fixed.c - Corrected linked list append function
 *
 * This file contains the REFACTORED version produced after AI code review.
 * All identified flaws have been resolved:
 *
 *   FIX 1 (Logical)       - Loop stops AT the last node via current->next
 *   FIX 2 (Logical)       - current->next = new_node links into the heap struct
 *   FIX 3 (Memory Safety) - malloc return is checked before any dereference
 *   FIX 4 (Correctness)   - Fields initialised before any early-return branch
 *
 * Project constraints: only malloc, free, exit permitted; no global variables.
 *
 * Data structure:
 *   typedef struct list_s {
 *       int n;
 *       struct list_s *next;
 *   } list_t;
 */

#include <stdlib.h>

/**
 * add_node_end - Appends a new node containing @n to the end of the list.
 *
 * @head: Pointer to the first node (NULL if list is empty).
 * @n:    Integer value to store in the new node.
 *
 * Return: Pointer to the head of the list, or NULL on allocation failure.
 */
list_t *add_node_end(list_t *head, const int n)
{
    list_t *new_node;
    list_t *current;

    /* FIX 3: Allocate then immediately validate */
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);              /* graceful failure; caller can check */

    /* FIX 4: Initialise fields before any branching */
    new_node->n    = n;
    new_node->next = NULL;

    /* Empty list: new node becomes the head */
    if (!head)
        return (new_node);

    /* FIX 1: Stop AT the last node, not past it */
    current = head;
    while (current->next)
        current = current->next;

    /* FIX 2: Write into the last node's ->next field on the heap */
    current->next = new_node;

    return (head);
}
