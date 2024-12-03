/**********************************************************************
 * Copyright (c) 2023
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

 /*====================================================================*/
 /*          ****** DO NOT MODIFY ANYTHING FROM THIS LINE ******       */
#include <stdio.h>
#include "types.h"
#include "list_head.h"

/* Declaration for the stack instance defined in pa0.c */
extern struct list_head stack;
/*          ****** DO NOT MODIFY ANYTHING ABOVE THIS LINE ******      */
/*====================================================================*/


/*====================================================================*
 * The rest of this file is all yours. This implies that you can      *
 * include any header files if you want to ...                        */

#include <stdlib.h>                    /* like this */
#include <string.h>
 /**
  * push_stack()
  *
  * DESCRIPTION
  *   Push @string into the @stack. The @string should be inserted into the top
  *   of the stack. You may use either the head or tail of the list for the top.
  */
void push_stack(char* const string)
{
	/* TODO: Implement this function */
  struct entry* new_node = (struct entry*)malloc(sizeof(struct entry));
  INIT_LIST_HEAD(&new_node->list);
  new_node->string = (char*)malloc(strlen(string) + 1);
  strcpy(new_node->string, string);
  list_add_tail(&(new_node->list), &stack);
}


/**
 * pop_stack()
 *
 * DESCRIPTION
 *   Pop a value from @stack and return it through @buffer. The value should
 *   come from the top of the stack, and the corresponding entry should be
 *   removed from @stack.
 *
 * RETURN
 *   If the stack is not empty, pop the top of @stack, and return 0
 *   If the stack is empty, return -1
 */
int pop_stack(char* const buffer)
{
	/* TODO: Implement this function */
  if(!list_empty(&stack)){
    struct entry *node = list_last_entry(&stack, struct entry, list);
    strcpy(buffer, node->string);
    list_del(&node->list);
    free(node->string);
    free(node);
    return 0;
  }
	return -1;
}


/**
 * dump_stack()
 *
 * DESCRIPTION
 *   Dump the contents in @stack. Print out @string of stack entries while
 *   traversing the stack from the bottom to the top. Note that the value
 *   should be printed out to @stderr to get properly graded in pasubmit.
 */
void dump_stack(void)
{
	/* TODO: Implement this function */
  struct list_head* pos;
  struct entry *node;
  list_for_each(pos, &stack){
    node = list_entry(pos, struct entry, list);
    fprintf(stderr, "%s\n", node->string);
  }
}
