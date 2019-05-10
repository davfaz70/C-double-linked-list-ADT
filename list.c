#include <stdio.h>
#include <stdlib.h>
#include "list.h"


list * create() {
  /* This is the first node of list, it's an invisible node and have
  length = -1, for now the next is NULL and it not have any previous node.
  the headpun ( head pointer ) will alwais point to it for every node, for
  keep the head of list*/
  list * lista_fantoccio;
  lista_fantoccio = malloc(sizeof(list));
  lista_fantoccio -> length = -1;
  lista_fantoccio -> inf = 0;
  lista_fantoccio -> next = NULL;
  lista_fantoccio -> previous = NULL;
  lista_fantoccio -> headpun = lista_fantoccio;

  return lista_fantoccio;

}

list * addElement(list * tail, int val) {
  /* a new node is created and the value is assigned to it */
  list * newList;
  newList = malloc(sizeof(list));
  newList -> inf = val;
  /* Now the new node is the tail of list, so its next item is NULL,
  its previous item is the old tail, the position ( length ) is increased
  and the next item of old tail is the new node*/
  newList -> next =  tail -> next;
  newList -> previous = tail;
  newList -> headpun = tail -> headpun;
  newList -> length = tail -> length + 1;
  tail -> next = newList;
  return newList;

}

int getElement(list * tail, int position) {
  list * temp = tail;
  int i = 0;
  if (position <= tail -> length && position >= 0 ) {
    while (temp -> previous != NULL && i == 0 ) {
      if (temp -> length == position) {
        printf("Front Value: %d", temp -> inf);
        i = 1;
      } else {
        temp = temp -> previous;
      }
    }
  } else {
    printf("%s\n", "The position not exist in list");
  }
  return 0;
}

list * removeElement(list * tail, int position) {

  list * tempPtr;
  list * control;
  int i = 0;
  tempPtr = tail;
  if (position <= tail -> length && position >= 0) {
    while (tempPtr != NULL && i == 0 ) {
      if (tempPtr -> length == position) {
        if(tempPtr -> next != NULL) {
          /* if the node to delete is not the last, the next node of the previous node
          of node to delete must be the next node of node to delete*/
          tempPtr -> previous -> next = tempPtr -> next;
          /* the previous node of next node of node to delete must be the previous
          node of node to delete*/
          tempPtr -> next -> previous = tempPtr -> previous;
          control = tempPtr -> next;
          printf("%d\n", control -> inf );
          while(control != NULL) {
            /* We must reduce the position of every node after node to delete*/
            control -> length = control -> length - 1;
            control = control -> next;
          }
        } else {
          tempPtr -> previous -> next = NULL;
          /* if the node to delete is the tail, the new tail will be the previous
          node of old tail*/
          tail = tempPtr -> previous;
        }
        free(tempPtr);
        i = 1;
        return tail;
      } else {
        tempPtr = tempPtr -> previous;
      }
    }
  } else {
    printf("%s\n", "The position entered is not valid!" );
  }
  return tail;
}

list * editElementPosition(list * tail, int position, int val) {

  list * tempPos;
  int i = 0;
  if ( position <= (tail -> length ) && position >= 0 ) {
    tempPos = tail;
    while (tempPos != NULL && i == 0) {
        if (tempPos -> length == position) {
          tempPos -> inf = val;
          i = 1;
        } else {
          tempPos = tempPos -> previous;
        }
    }
  } else {
    printf("The position is not valid!");
  }
  return 0;
}

void printList(list * tail) {
  list * L;
  /*The loop start from head*/
  L = tail -> headpun -> next;
  while (L != NULL) {
    printf("%s%d%s%d%s","[",L->inf,"{", L -> length, "}]");
    L = L->next;
  }
  printf("\n");
}

void delete(list * tail) {
  list * temp = tail;
  while (temp -> previous != NULL) {
    temp = temp-> previous;
    free(tail);
    tail = temp;
  }
}
