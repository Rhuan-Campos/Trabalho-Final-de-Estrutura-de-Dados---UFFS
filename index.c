#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Production *begin = NULL;
    begin = addSampleData(begin);

    while (1) {
        showMenu();

        int chosenOption;
        scanf("%d", &chosenOption);


        switch (chosenOption) {
            case 1:
                // insertProduction(begin);
                // break;
            case 2:
                getProduction(begin);
                break;
            case 3:
                changeProduction(begin);
                break;
            case 4:
                deleteProduction(begin);
                break;
            case 5:
                showProductionList(begin);
                break;
            case 6:
                showReverseProductionList(begin);
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
