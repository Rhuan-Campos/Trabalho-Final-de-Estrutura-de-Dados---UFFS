#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

// Função para inserir um novo nó na lista duplamente encadeada
Production* insertProduction(Production *head, int id, int day, int month, int year, const char *cultivar, char bundleType, int diameter, int gzBundleQuantity, float duration) {
    Production *newNode = malloc(sizeof(Production));
    if (newNode == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    newNode->id = id;
    newNode->prodDate.day = day;
    newNode->prodDate.month = month;
    newNode->prodDate.year = year;
    strcpy(newNode->gzBundleType.cultivar, cultivar);
    newNode->gzBundleType.bundleType = bundleType;
    newNode->gzBundleType.diameter = diameter;
    newNode->gzBundleQuantity = gzBundleQuantity;
    newNode->duration = duration;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        // Se a lista estiver vazia, o novo nó se torna a cabeça da lista
        head = newNode;
    } else {
        // Encontra o último nó da lista
        Production *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        // Adiciona o novo nó após o último nó
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    return head;
}

void getProduction(Production *prod) {
    int option;
    printf("Por qual das seguintes opções deseja consultar?\n1. Data\n2. Cultivar\n");
    scanf("%d", &option);

    switch (option) {
        case 1: {
            int day, month, year;
            printf("Insira o dia que deseja consultar: ");
            scanf("%d", &day);
            printf("Insira o mês que deseja consultar: ");
            scanf("%d", &month);
            printf("Insira o ano que deseja consultar: ");
            scanf("%d", &year);

            int totalQuantity = 0;
            int found = 0;

            Production *current = prod;
            while (current != NULL) {
                if (current->prodDate.day == day && current->prodDate.month == month && current->prodDate.year == year) {
                    printf("Data: %d/%d/%d\n", current->prodDate.day, current->prodDate.month, current->prodDate.year);
                    printf("Cultivar: %s\n", current->gzBundleType.cultivar);
                    printf("Tipo de Feno: %c\n", current->gzBundleType.bundleType);
                    printf("Quantidade de Fardos: %d\n", current->gzBundleQuantity);
                    printf("\n");
                    totalQuantity += current->gzBundleQuantity;
                    found = 1;
                }
                current = current->next;
            }

            if (!found) {
                printf("Nenhum registro encontrado para a data informada.\n");
            } else {
                printf("Total de Fardos para a Data: %d\n", totalQuantity);
            }
            break;
        }
        case 2:
            // Lógica para consulta por cultivar
            char searchCultivar[20];
            printf("Insira o cultivar que deseja consultar: ");
            scanf("%s", searchCultivar);

            int found = 0;

            Production *current = prod;
            //Lembra de implementar dnv, pq o professor quer de outra maneira que eu não entendi
            while (current != NULL) {
                if (strcmp(current->gzBundleType.cultivar, searchCultivar) == 0) {
                    printf("Cultivar: %s\n", current->gzBundleType.cultivar);
                    printf("Tipo de Feno: %c\n", current->gzBundleType.bundleType);
                    printf("Quantidade de Fardos: %d\n", current->gzBundleQuantity);
                    printf("\n"); 
                    found = 1;
                }
                current = current->next;
            }

            if (!found) {
                printf("Nenhum registro encontrado para o cultivar informado.\n");
            }
            break;
            break;
        default:
            printf("Operação inválida, tente novamente!\n");
    }
    return 0;
}

// int searchId(Production prodList, int id){
//     int correctId = -1;
//     for(Production aux = prodList; aux!=NULL; aux = aux -> next ){
//         if(aux.id == id){
//             correctId = id;
//         }
//     }
//     return correctId;
// }

int changeData(){

}

int deleteData(){

}

void printProductionList(Production *head) {
    Production *current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("Date: %d/%d/%d\n", current->prodDate.day, current->prodDate.month, current->prodDate.year);
        printf("Cultivar: %s\n", current->gzBundleType.cultivar);
        printf("Bundle Type: %c\n", current->gzBundleType.bundleType);
        printf("Diameter: %d\n", current->gzBundleType.diameter);
        printf("Quantity: %d\n", current->gzBundleQuantity);
        printf("Duration: %.2f\n", current->duration);
        printf("\n");

        current = current->next;
    }
}

int reverseListAll(){

}

void showMenu() {
    printf("Bem vindo ao Sistema de Acompanhamento de Produção Agrícola X\n");
    printf("Digite a opção desejada:\n");
    printf("\t1. Incluir Produção\n");
    printf("\t2. Consultar\n");
    printf("\t3. Alterar\n");
    printf("\t4. Excluir\n");
    printf("\t5. Listar todos\n");
    printf("\t6. Listar de maneira inversa\n");
    printf("\t7. Sair\n");
}