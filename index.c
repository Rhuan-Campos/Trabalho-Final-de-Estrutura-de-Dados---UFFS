#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Production *head = NULL;
    head = addSampleData(head);

    while (1) {
        showMenu();

        int chosenOption;
        scanf("%d", &chosenOption);


        switch (chosenOption) {
            case 1:
                // insertProduction(head);
                // break;
            case 2:
                getProduction(head);
                break;
            case 3:
                getIdForChangeData(head);
                break;
            case 4:
                getIdForDeleteData(head);
                break;
            case 5:
                showProductionList(head);
                break;
            case 6:
                showReverseProductionList(head);
                break;
            case 7:
                printf("Programa encerrado!");
                exit(0);
            default:
                printf("Opção inválida, tente novamente!\n");
                break;
        }
    }

    return 0;
}