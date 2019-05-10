#include <stdio.h>
#include <string.h>

struct doublelinkedlist {
    int inf;
    int length;
    struct doublelinkedlist *next;
    struct doublelinkedlist *previous;
    struct doublelinkedlist *headpun;
};
typedef struct doublelinkedlist list;

/* Create a new list, usage: name_of_list = create();*/
list * create();

/* Add element to the list, this element will be the new tail of the list,
usage: name_of_list = addElement(name_of_list, value); */
list * addElement(list * tail, int val);

/* This method return a specific value in the list, this value is returned
by position, IMPORTANT: the list must be not empty
usage: getElement(name_of_list, position_of_element)*/
int getElement(list * tail, int position);

/* Remove an element by position, usage: name_of_list = (name_of_list, position);*/
list * removeElement();

/* This method allow you to edit the value of one node, the node is selected by
position.
usage: editElementPosition(name_of_list, position_of_element, new_value);*/
list * editElementPosition(list * tail, int pos, int val);

/* Do you seriously need an explanation of what this method does?*/
void printList(list * tail);

/* The list is deleted, you cannot use it again, unless you call again create()
after this method, in this case the behavior is the same of empity list.
usage: name_of_list = delete()*/
void delete();
