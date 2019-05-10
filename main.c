#include <stdio.h>
#include "list.h"
#include <stdlib.h>

int main () {

    int menu = 0;
    int input = 0;
    int position;
    int control = 0;
    list * lista;
    char c;

    lista = create();

    while (menu != 6) {

        printf("\nWhat would you like to test?\n");
        printf("\n[1] Add element on tail\n");
        printf("[2] Get element by position\n");
        printf("[3] Remove element by position\n");
        printf("[4] Edit element by position\n");
        printf("[5] Destroy list\n");
        printf("[6] Exit\n");
        scanf("%d", &menu);

        if (menu > 6 || menu < 1)
            while((c = getchar()) != '\n' && c != EOF);

        if (menu == 1) {
          do {
            printf("\nPlease Enter an Integer:");
            if(scanf("%d%c", &input, &c) != 2 || c != '\n') {
              while((c = getchar()) != '\n' && c != EOF);
              control = 1;
            } else {
              control = 0;
            }
          } while (control == 1);

          lista = addElement(lista, input);

          printf("Current List:");
          printList(lista);

        }

        if (menu == 2) {
          do {
            printf("%s %d\n", "Please enter the position, max: ", lista->length);
            if(scanf("%d%c", &position, &c) != 2 || c != '\n') {
              while((c = getchar()) != '\n' && c != EOF);
              control = 1;
            } else {
              control = 0;
            }
          } while (control == 1);

            getElement(lista, position);

            printf("\nCurrent List:");
            printList(lista);

        }

        if (menu == 3) {
          do {
            printf("%s %d\n", "Please enter the position, max:", lista->length);
            if(scanf("%d%c", &position, &c) != 2 || c != '\n') {
              while((c = getchar()) != '\n' && c != EOF);
              control = 1;
            } else {
              control = 0;
            }
          } while (control == 1);

            lista = removeElement(lista, position);

            printf("Current List:");
            printList(lista);

        }

        if (menu == 4) {
          do {
            printf("%s%d\n", "Please enter the position, max:", lista -> length);
            if(scanf("%d%c", &position, &c) != 2 || c != '\n') {
              while((c = getchar()) != '\n' && c != EOF);
              control = 1;
            } else {
              control = 0;
            }
          } while (control == 1);
          do {
            printf("%s\n", "Please enter the new value:" );
            if(scanf("%d%c", &input, &c) != 2 || c != '\n') {
              while((c = getchar()) != '\n' && c != EOF);
              control = 1;
            } else {
              control = 0;
            }
          } while (control == 1);

          editElementPosition(lista, position, input);
          printf("Current List:");
          printList(lista);
        }

        if (menu == 5) {

            delete(lista);
            lista = create();
        }
    }
    printf("%s\n", "Goodbye");
    return 0;
}
