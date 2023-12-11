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

typedef struct production{
   int id;
   Data prodDate;
   GrazingBundle gzBundleType;  
   int gzBundleQuantity;
   float duration;
   struct Production *prox;
   struct Production *prev;
} Production;

typedef struct grazingBundle {
   char cultivar[20];
   char bundleType;
   int diameter; //80cm a 160cm e Altura de 150cm 
} GrazingBundle;

typedef struct data{
   int day;
   int month;
   int year;
} Data;

void insertProduction(Production **last, int id, int day, int month, int year, char cultivar[], char bundleType, int diameter, int gzBundleQuantity, float duration) {
    Production *newNode = malloc(sizeof(Production));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return;
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
    newNode->prox = NULL;

    if (*last != NULL) {
        (*last)->prox = newNode;
    }
    newNode->prev = *last;
    *last = newNode;
}

int getProduction(){

}

int changeData(){

}

int deleteData(){

}

int listAll(){

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

int main() {
    Production *begin = malloc(sizeof(Production));

    // Adding generic sample data...
    insertProduction(&begin, 1, 10, 12, 2023, "Cultivar A", 'A', 100, 5, 3.5);
    insertProduction(&begin, 2, 15, 11, 2023, "Cultivar B", 'B', 120, 7, 4.2);
    insertProduction(&begin, 3, 20, 10, 2023, "Cultivar C", 'C', 140, 3, 2.1);
    insertProduction(&begin, 4, 25, 9, 2023, "Cultivar D", 'D', 160, 6, 4.8);
    insertProduction(&begin, 5, 30, 8, 2023, "Cultivar E", 'E', 130, 4, 3.0);

    while (1) {
        showMenu();

        int chosenOption;
        scanf("%d", &chosenOption);

        switch (chosenOption) {
            case 1:
                insertProduction();
                break;
            case 2:
                getProduction();
                break;
            case 3:
                changeData();
                break;
            case 4:
                delete();
                break;
            case 5:
                listAll();
                break;
            case 6:
                reverseListAll();
                break;
            case 7:
                printf("Programa encerrado!");
                exit(0); // Encerra o programa imediatamente
            default:
                printf("Opção inválida, tente novamente!\n");
                break;
        }
    }

    return 0;
}