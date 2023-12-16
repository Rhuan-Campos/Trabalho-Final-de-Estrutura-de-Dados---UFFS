#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

// Função para inserir um novo nó na lista duplamente encadeada

void updateProductionData(Production *target) { //Alterar
    int choice;
    int updateMore = 1;

    while (updateMore) {
        printf("Quais campos você deseja atualizar?\n");
        printf("1. Data de Produção\n");
        printf("2. Cultivar\n");
        printf("3. Tipo de Fardo\n");
        printf("4. Quantidade de Fardos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                updateMore = 0;
                break;
            case 1:
                printf("Digite a nova data (dd mm aaaa): ");
                scanf("%d %d %d", &target->prodDate.day, &target->prodDate.month, &target->prodDate.year);
                break;
            case 2:
                printf("Digite o novo cultivar: ");
                scanf("%s", target->gzBundleType.cultivar);
                break;
            case 3:
                printf("Digite o novo tipo de fardo (A, B ou C): ");
                scanf(" %c", &target->gzBundleType.bundleType);
                break;
            case 4:
                printf("Digite a nova quantidade de fardos: ");
                scanf("%d", &target->gzBundleQuantity);
                break;
            default:
                printf("Escolha inválida.\n");
                break;
        }
    }
}

void getIdForChangeData(Production *head) {
    int idToSearch;
    printf("\nDigite o ID do registro que deseja alterar: ");
    scanf("%d", &idToSearch);
    printf("\n");

    Production *target = findProductionById(head, idToSearch);

    if (target != NULL) {
        printf("Registro encontrado. Insira os novos dados:\n");
        updateProductionData(target);
        printf("Registro atualizado com sucesso!\n");
    } else {
        printf("Nenhum registro encontrado para o ID %d.\n", idToSearch);
    }
}

Production* findProductionById(Production *head, int idToSearch) {
    Production *current = head;
    while (current != NULL) {
        if (current->id == idToSearch) {
            return current; 
        }
        current = current->next;
    }
    return NULL; 
}

void getProduction(Production *prod) { //Consultar
    int option;
    printf("Por qual das seguintes opções deseja consultar?\n1. Data\n2. Cultivar\n");
    scanf("%d", &option);
    char searchCultivar[20];

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
                    printf("%d/%d/%d: %s - %c - %d\n", current->prodDate.day, current->prodDate.month, current->prodDate.year,
                           current->gzBundleType.cultivar, current->gzBundleType.bundleType, current->gzBundleQuantity);
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
           printf("Insira o cultivar que deseja consultar: ");
            scanf("%s", searchCultivar);

            int found = 0;

            Production *current = prod;
            // Lógica para consulta por cultivar
            while (current != NULL) {
                if (strcmp(current->gzBundleType.cultivar, searchCultivar) == 0) {
                    found = 1;
                    break;
                }
                current = current->next;
            }

            if (found) {
                // Array para armazenar os tipos de feno encontrados
                char tiposDeFeno[50][3]; // Assumindo que o tipo de feno pode ter até 2 caracteres
                int quantidadeDeTipos = 0;
                int totalQuantity = 0;

                current = prod; // Reiniciando a busca
                while (current != NULL) {
                    if (strcmp(current->gzBundleType.cultivar, searchCultivar) == 0) {
                        // Verifica se o tipo de feno já foi registrado
                        int tipoJaRegistrado = 0;
                        for (int i = 0; i < quantidadeDeTipos; ++i) {
                            if (tiposDeFeno[i][0] == current->gzBundleType.bundleType) {
                                tipoJaRegistrado = 1;
                                break;
                            }
                        }

                        // Se não estiver registrado, registra
                        if (!tipoJaRegistrado) {
                            tiposDeFeno[quantidadeDeTipos][0] = current->gzBundleType.bundleType;
                            tiposDeFeno[quantidadeDeTipos][1] = '\0';
                            quantidadeDeTipos++;
                        }

                        // Adiciona à quantidade total de fardos
                        totalQuantity += current->gzBundleQuantity;
                    }
                    current = current->next;
                }

                if (quantidadeDeTipos > 0) {
                    for (int i = 0; i < quantidadeDeTipos; ++i) {
                        printf("%s: ", searchCultivar);
                        printf("%s - %d", tiposDeFeno[i], totalQuantity);
                        if (i < quantidadeDeTipos - 1) {
                            printf("\n");
                        }
                    }
                    printf("\n");
                } else {
                    printf("Nenhum registro encontrado para o cultivar informado.\n");
                }
            } else {
                printf("Nenhum registro encontrado para o cultivar informado.\n");
            }
            break;
        default:
            printf("Operação inválida, tente novamente!\n");
    }
}


//Inserir produção
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
        head = newNode;
    } else {
        Production *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    return head;
}

void findProductionByIdForDelete(Production *begin, int searchedId) {
    Production *current = begin;
    while (current != NULL) {
        if (current->id == searchedId) {
            if (current == begin) {
                begin = current->next;
                if (begin != NULL) {
                    begin->prev = NULL;
                }
                free(current);
            } else {
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(current);
            }
            printf("Elemento com o ID %d deletado!! \n", searchedId);
            return ;
        }
        current = current->next;
    }
    printf("Produção com o ID %d não encontrada.\n", searchedId);
}

void getIdForDeleteData(Production *begin){
    int searchedId = 0;
    printf("\nDigite o id do elemento que desejas deletar: ");
    scanf("%d", &searchedId);
    printf("\n");

    findProductionByIdForDelete(begin, searchedId);
}

void printProductionDetails(Production *node) {
    if (node != NULL) {
        printf("ID: %d\n", node->id);
        printf("Date: %d/%d/%d\n", node->prodDate.day, node->prodDate.month, node->prodDate.year);
        printf("Cultivar: %s\n", node->gzBundleType.cultivar);
        printf("Bundle Type: %c\n", node->gzBundleType.bundleType);
        printf("Diameter: %d\n", node->gzBundleType.diameter);
        printf("Quantity: %d\n", node->gzBundleQuantity);
        printf("Duration: %.2f\n", node->duration);
        printf("\n");
    }
}

void showProductionList(Production *begin) {
    Production *current = begin;
    while (current != NULL) {
        printProductionDetails(current);
        current = current->next;
    }
}

void showReverseProductionList(Production *begin){
    if (begin != NULL) {
        showReverseProductionList(begin->next);
        printProductionDetails(begin);
    }
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
    printf("\nEscolha uma das ações acima: ");
}

void freeProductionList(Production *head) {
    Production *current = head;
    while (current != NULL) {
        Production *temp = current;
        current = current->next;
        free(temp);
    }
}

Production* addSampleData(Production *head) {
	freeProductionList(head);
    head = insertProduction(head, 1, 5, 3, 2023, "Coastcross", 'A', 120, 5, 10.5);
    head = insertProduction(head, 2, 10, 6, 2023, "Jiggs", 'B', 100, 8, 7.2);
    head = insertProduction(head, 3, 15, 9, 2023, "Florakirk", 'C', 140, 3, 12.8);
    head = insertProduction(head, 4, 20, 12, 2023, "Florakirk", 'D', 130, 4, 8.0);
    head = insertProduction(head, 5, 25, 5, 2023, "Tifton 85", 'E', 150, 6, 15.3);
    return head;
}
