#ifndef contantes
#define contantes

#define MAX_ESTUDANTES 100
#define MAX_UC 40
#define MAX_STRING 100

typedef struct{
    int dia;
    int mes;
    int ano;
} tipoData;


typedef struct{
    int h;
    int m;
} tipoHora;


typedef struct{
    int codigo;
    char designacao[MAX_STRING];
    char tipoDeUc[MAX_STRING];
    char tipoAula[MAX_STRING];
    int semestre;
    char regime[MAX_STRING];
    int quantidadeTotalHoras;
    int duracao;
    int quantidadeAulas;
    int quantidadeHoras;
    int quantidadeAulasAgendadas;
    int quantAulasRealizadas; //para fazer estatistica
    int numGravacoes;
    int quantAcessosGravacoes;
} tipoUc;


typedef struct{
    char designacao[MAX_STRING];
    char regimeAula[MAX_STRING];
    char docente[MAX_STRING];
    tipoData data;
    tipoHora hora;
    int horaFim;
    int minFim;
    char estadoAula[MAX_STRING];
    char gravacao[MAX_STRING];
    //int numAssecoGravacao;
    int codigo; //chave primaria UCs
} tipoAula;


typedef struct{
    int numEstudante;
    int nome;
    char designacaoAula[MAX_STRING];
    char tipoAcesso[MAX_STRING];
} tipoAulasAssistidas;


typedef struct{
    int numeroEstudante;
    char nome[MAX_STRING];
    char regime[MAX_STRING];
} tipoEstudante;




#endif // contantes
