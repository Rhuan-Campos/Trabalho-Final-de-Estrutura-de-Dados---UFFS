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

// Consultar: permite fazer consultas: pela data e pelo cultivar. A consulta por data exibe a quantidade de fardos produzidos naquele dia, indicando o tipo de feno (A, B ou C) e cultivar, no seguinte formato: “<data>: <cultivar> - <tipoDeFeno> - <qtDeFardos>”. Já a consulta por cultivar exibe o resultado no seguinte formato: <cultivar>: <tipoDeFeno> - <soma da quantidade de fardos>. Caso houver mais de um tipoDeFeno, exibir cada um em uma nova linha. Mostrar uma mensagem ao usuário caso não haja registros com a chave de busca utilizada.

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

//É possível fazer um encadeamento duplo mas não sei se não será somente desperdício de linha

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct producao{
   int codigo;
   Data dataProducao;
   Fardo tipoDeFardo;  
   int qtDeFardos;
   float duracao;
   struct Producao *prox;
} Producao;

typedef struct fardo{
   char cultivar[20];
   char tipoDeFeno;
   int diametro; //80cm a 160cm e Altura de 150cm 
} Fardo;

typedef struct data{
   int dia;
   int mes;
   int ano;
} Data;

// typedef struct nos{
//    Producao producao;
//   //  struct Nos *ante = NULL;
//    struct Nos *prox = NULL;
// } Nos;

void incluirProducao(){

}

int consultar(){

}

int alterar(){

}

int excluir(){

}

int listarTodos(){

}

int main(){
  int continuar = 1;
  Producao inicio = malloc(sizeof(Producao));

  while(continuar){
    int opcao;
    printf("Bem vindo ao Sistema de Acompanhamento de Produção Agrícola X\nDigite a opção que deseja:\n\t1.Incluir Produção\n\t2.Consultar\n\t3.Alterar\n\t4.Excluir\n\t5.Listar todos\n\t6.Sair");
    scanf("%d", &opcao);

    switch (opcao){
    case 1:
      incluirProducao();
      break;
    
    case 2:
      consultar();
      break;
    
    case 3:
      alterar();
      break;

    case 4:
      excluir();
      break;

    case 5:
      listarTodos();
      break;

    case 6:
      printf("Programa encerrado!");
      continuar = 0;
      break;      
    default:
      printf("Opção inválida, tente novamente!");
      break;
    }
  }


  return 0;
}