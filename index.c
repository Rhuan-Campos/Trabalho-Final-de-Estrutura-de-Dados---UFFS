// No universo da produção animal e em função da necessidade, diferentes métodos de conservação de forragens foram desenvolvidos pelo homem como estratégias alternativas, no intuito de atender as demandas alimentares dos animais, especificamente em períodos críticos e desfavoráveis à produção de capim. Neste contexto, a produção de feno é um exemplo prático disto. Este produto é viabilizado através de um processo de conservação muito antigo, mais conhecido por fenação. 

// Um produtor da região trabalha na área e lhe contratou para desenvolver um sistema para acompanhamento da sua produção. O produtor se beneficia de processo mecanizado e sua enfardadeira produz fardos cilíndricos com altura de 150 cm e diâmetro de 80 cm a 160 cm, dependendo da configuração do equipamento. 
// O produtor atua com fenos das cultivares Tifton 85, Florakirk, Jiggs, Coastcross. Cada Cultivar ainda pode ser classificado em três tipos:
 
// Feno tipo A: é o feno de melhor qualidade, conferindo a melhor coloração e aroma característico apresentando uma predominância de folhas e poucos talos e não tomou chuva durante o processo de produção.

// Feno tipo B: é o feno que durante o processo de pode ter tomado um pouco de chuva, prejudicado em sua coloração e aroma ou por ter maior quantidade de talos do que folha. Porém os níveis nutricionais permanecem praticamente inalterados.

// Feno tipo C: é um feno com mais talos e poucas folhas ou que tenha plantas daninhas. 

// Após uma análise dos requisitos você concluiu que o programa deve ser composto pelas seguintes estruturas:


// Agora você deve definir o tipo de lista que vai usar (com encadeamento simples ou duplo) e implementar o programa com estas estruturas e algumas funcionalidades:

// O sistema deve permitir a inclusão, consulta, alteração e exclusão de um registro de Produção. 
// O sistema deverá exibir um menu para o usuário escolher a ação. Por exemplo:
// 1.Incluir Produção
// 2.Consultar
// 3.Alterar
// 4.Excluir  (POR CONTA DISSO -> DUPLAMENTE ENCADEADO)
// 5.Listar todos
// 6.Sair

// O que acontece com cada item do menu:

// Incluir Produção: permite o registro de um período de produção. **Não permitir duplicação do código de produção**, ou seja, se o código 10 já existir e o usuário tentar inserir uma nova produção com o código 10, o sistema deverá avisar que o código já existe e a produção não poderá ser incluída.

// Consultar: permite fazer consultas: pela data e pelo cultivar. A consulta por data exibe a quantidade de fardos produzidos naquele dia, indicando o tipo de feno (A, B ou C) e cultivar, no seguinte formato: “<data>: <cultivar> - <tipoDeFeno> - <gzBundleQuantity>”. Já a consulta por cultivar exibe o resultado no seguinte formato: <cultivar>: <tipoDeFeno> - <soma da quantidade de fardos>. Caso houver mais de um tipoDeFeno, exibir cada um em uma nova linha. Mostrar uma mensagem ao usuário caso não haja registros com a chave de busca utilizada.

// Alterar: permite alterar qualquer campo do registro de produção. A busca do registro para alteração deve ser realizada por código.

// Excluir: permite excluir um registro de produção. A implementação é similar ao da opção Alterar, exceto que o registro é excluído da lista.

// Listar todos: lista todos os registros de produção do programa.

// Sair: finaliza o programa.

// Serão utilizados os seguintes critérios na Avaliação:

// Apresentação do código e funcionalidades implementadas;
// Adequada indentação;
// Implementação de funções para fins de reutilização de código;
// Criatividade no desenvolvimento;
// Exemplo: uso de BST (binary search tree) na função de busca (opcional).
// Utilização do conceito de Tipo Abstrato de Dados (TAD), com arquivo .h e .c.
// Inclusão de registros em ordem de data.
// Outras funcionalidades (opcional).
	

// Obs.: O programa deve ser entregue via SIGAA no espaço disponível para o efeito, nomeado com <matricula-TF>.zip, até o dia indicado no sistema. Para aqueles que fizerem em dupla, o nome do arquivo deve ser <matricula1-matricula2-TF>.zip e apenas um deve submeter o trabalho.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
    int day;
    int month;
    int year;
} Data;

typedef struct grazingBundle {
    char cultivar[20];
    char bundleType;
    int diameter; // 80cm a 160cm e Altura de 150cm 
} GrazingBundle;

typedef struct production {
    int id;
    Data prodDate;
    GrazingBundle gzBundleType;
    int gzBundleQuantity;
    float duration;
    struct production *next;
    struct production *prev;
} Production;

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

void findProductionByIdForShow(Production *begin, int searchedId) {
    Production *current = begin;
    while (current != NULL) {
        if (current->id == searchedId) {
            printf("Resultado: \n");
            printProductionDetails(current);
            return;
        }
        current = current->next;
    }
    printf("Produção com o ID %d não encontrada.\n", searchedId);
}

void getIdForSearch(Production *begin) {
    int searchedId = 0;
    printf("\nDigite o id do projeto que deseja obter informações: ");
    scanf("%d", &searchedId);
    printf("\n");

    findProductionByIdForShow(begin, searchedId);
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
            return;
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

int deleteData(){

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
    head = insertProduction(head, 1, 5, 3, 2023, "Cultivar A", 'A', 120, 5, 10.5);
    head = insertProduction(head, 2, 10, 6, 2023, "Cultivar B", 'B', 100, 8, 7.2);
    head = insertProduction(head, 3, 15, 9, 2023, "Cultivar C", 'C', 140, 3, 12.8);
    head = insertProduction(head, 4, 20, 12, 2023, "Cultivar D", 'D', 130, 4, 8.0);
    head = insertProduction(head, 5, 25, 5, 2023, "Cultivar E", 'E', 150, 6, 15.3);
    return head;
}

int main() {
    Production *head = NULL;
    head = addSampleData(head);

    while (1) {
        showMenu();

        int chosenOption;
        scanf("%d", &chosenOption);

        switch (chosenOption) {
            case 1:
                // insertProduction();
                // break;
            case 2:
                getIdForSearch(head);
                break;
            case 3:
                // getIdForChangeData();
                // break;
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