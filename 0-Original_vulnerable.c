/**
 * 0-original_vulnerable.c - Original vulnerable linked list function
 *
 * This file contains the ORIGINAL, UNMODIFIED code submitted for AI review.
 * It contains two documented flaws:
 *   1. Logical flaw   - traversal overshoots the last node
 *   2. Memory flaw    - malloc return value is never checked
 *
 * Data structure:
 *   typedef struct list_s {
 *       int n;
 *       struct list_s *next;
 *   } list_t;
 */

#include <stdlib.h>

/* ---------------------------------------------------------------
 * VULNERABLE CODE - DO NOT USE IN PRODUCTION
 * --------------------------------------------------------------- */
list_t *add_node_end(list_t *head, const int n)
{
    list_t *new_node = malloc(sizeof(list_t)); /* FLAW 2: return never checked */
    list_t *current = head;

    if (!head)
        return (new_node);                     /* FLAW 2: may return NULL     */
                                               /* FLAW 2: fields uninitialised */

    while (current)                            /* FLAW 1: overshoots last node */
        current = current->next;

    current = new_node;                        /* FLAW 1: local reassign only  */
    new_node->n = n;
    new_node->next = NULL;
    return (head);                             /* FLAW 1: new_node never linked */
}
