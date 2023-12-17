#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

// Função para inserir um novo nó na lista duplamente encadeada

int isCultivarValid(const char *cultivar) {
  const char *cultivarValidos[] = {"Tifton-85", "Florakirk", "Jiggs", "Coastcross"};
  int numCultivaresValidos = sizeof(cultivarValidos) / sizeof(cultivarValidos[0]);

  for (int i = 0; i < numCultivaresValidos; ++i) {
    if (strcmp(cultivar, cultivarValidos[i]) == 0) {
      return 1; // O cultivar é válido
    }
  }
  return 0; // O cultivar não é válido
}

int isProductionCodeDuplicate(Production *begin, int newId) {
    Production *current = begin;

    while (current != NULL) {
        if (current->id == newId) {
            // Código de produção já existe na lista
            return 1;
        }
        current = current->next;
    }

    // Código de produção não encontrado na lista
    return 0;
}

void addProduction(Production **begin) {
    int newId;
    printf("Digite o novo código de produção: ");
    scanf("%d", &newId);

    // Verificar se o código de produção já existe
    if (isProductionCodeDuplicate(*begin, newId)) {
        printf("O código de produção já existe. A produção não pode ser incluída.\n");
        return;
    }

    Production *newProduction = (Production*)malloc(sizeof(Production));
    if (newProduction == NULL) {
        printf("Erro ao alocar memória para a nova produção.\n");
        return;
    }

    newProduction->id = newId;

  
    printf("Digite a data de produção (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &newProduction->prodDate.day, &newProduction->prodDate.month, &newProduction->prodDate.year);

    printf("Digite o cultivar (Tifton-85, Florakirk, Jiggs, Coastcross): ");
    scanf("%s", newProduction->gzBundleType.cultivar);
    if (!isCultivarValid(newProduction->gzBundleType.cultivar)) {
        printf("Cultivar inválido. Por favor, insira um cultivar válido.\n");
        free(newProduction);
        return;
    }

    printf("Digite o tipo de fardo (A, B ou C): ");
    scanf(" %c", &newProduction->gzBundleType.bundleType);
    if (!isBundleTypeValid(newProduction->gzBundleType.bundleType)) {
        printf("Tipo de fardo inválido. Por favor, insira um tipo de fardo válido.\n");
        free(newProduction);
        return;
    }

    printf("Digite o diâmetro do fardo (80 a 160 cm): ");
    scanf("%d", &newProduction->gzBundleType.diameter);
    if (newProduction->gzBundleType.diameter < 80 || newProduction->gzBundleType.diameter > 160) {
        printf("Por favor, insira um diâmetro válido (entre 80 e 160 cm).\n");
        return;
    }

    printf("Digite a quantidade de fardos: ");
    scanf("%d", &newProduction->gzBundleQuantity);

    printf("Digite a duração da produção (em dias): ");
    scanf("%f", &newProduction->duration);

    newProduction->next = NULL;
    newProduction->prev = *begin;

    if (*begin != NULL) {
        Production *last = *begin;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newProduction;
        newProduction->prev = last;
} else {
        *begin = newProduction;
}

    printf("Produção adicionada com sucesso!\n");
}



// Função para verificar se o tipo de fardo é válido
int isBundleTypeValid(char bundleType) {
    return (bundleType == 'A' || bundleType == 'B' || bundleType == 'C');
}

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

void changeProduction(Production *begin) {
    int idToSearch;
    printf("\nDigite o ID do registro que deseja alterar: ");
    scanf("%d", &idToSearch);
    printf("\n");

    Production *target = findProductionById(begin, idToSearch);

    if (target != NULL) {
        printf("Registro encontrado. Insira os novos dados:\n");
        updateProductionData(target);
        printf("Registro atualizado com sucesso!\n");
    } else {
        printf("Nenhum registro encontrado para o ID %d.\n", idToSearch);
    }
}

Production* findProductionById(Production *begin, int idToSearch) {
    Production *current = begin;
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
    char searchGzBundle[20];

    switch (option) {
        case 1: {
            int day, month, year;
            printf("Insira o data que deseja consultar (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &day, &month, &year);

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
           printf("Insira o cultivar que deseja consultar (Tifton-85, Florakirk, Jiggs, Coastcross): ");
            scanf("%s", searchGzBundle);

            int found = 0;
            Production *current = prod;

            printf("Insira o cultivar que deseja consultar: ");
            scanf("%s", searchGzBundle);

            // Lógica para consulta por cultivar
            while (current != NULL) {
                if (strcmp(current->gzBundleType.cultivar, searchGzBundle) == 0) {
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
                    if (strcmp(current->gzBundleType.cultivar, searchGzBundle) == 0) {
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
                        printf("%s: ", searchGzBundle);
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
            return;
        }
        current = current->next;
    }
    printf("Produção com o ID %d não encontrada.\n", searchedId);
}

void deleteProduction(Production *begin){
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

void freeProductionList(Production *begin) {
    Production *current = begin;
    while (current != NULL) {
        Production *temp = current;
        current = current->next;
        free(temp);
    }
}