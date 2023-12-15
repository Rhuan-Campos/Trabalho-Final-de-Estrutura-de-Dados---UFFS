#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Production *head = NULL;

    head = insertProduction(head, 1, 5, 3, 2023, "Cultivar A", 'A', 120, 5, 10.5);
    head = insertProduction(head, 2, 10, 6, 2023, "Cultivar B", 'B', 100, 8, 7.2);
    head = insertProduction(head, 3, 15, 9, 2023, "Cultivar C", 'C', 140, 3, 12.8);

    Production *current = head;
    while (current != NULL) {
        Production *temp = current;
        current = current->next;
        free(temp);
    }

    while (1) {
        showMenu();
        
        int chosenOption;
        scanf("%d", &chosenOption);

        switch (chosenOption) {
            // case 1:
            //     insertProduction();
            //     break;
            case 2:
                getProduction();
                break;
            case 3:
                changeData();
                break;
            case 4:
                deleteData();
                break;
            case 5:
                printProductionList(head);
                break;
            case 6:
                reverseListAll();
                break;
            case 7:
                printf("Programa encerrado!");
                fflush(head);
                exit(0); // Encerra o programa imediatamente
            default:
                printf("Opção inválida, tente novamente!\n");
                break;
        }
    }

    return 0;
}