#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack Create_stack(){

    stack s;

    s = (struct Node_stack *) malloc(sizeof(struct Node_stack ));

        if ( s == NULL){
            printf("Out of memory...");
        }

    s->next = NULL;
    s->size_of_stack = 0;

return s;
}


stack push(int data,stack s){


        if (s == NULL){

            s= Create_stack();

            s->val = data;
            s->next = NULL;
            s->size_of_stack = 1;  }

        else{

            stack new_node;

            new_node = Create_stack();

            new_node ->val = data;
            new_node->size_of_stack = 1;
            new_node ->next = s;
            s = new_node;     }


return s;
}


stack pop(stack s){

    if ( s != NULL){


        stack remove_node;

        remove_node = s;

        s = s->next;

        free(remove_node);

        return s;
    }

}

