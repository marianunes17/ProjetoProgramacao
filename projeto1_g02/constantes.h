#ifndef contantes
#define contantes

#define MAX_ESTUDANTES 100
#define MAX_UC 40
#define MAX_STRING 100

typedef struct{
    int dia, mes, ano;
} tipoData;


typedef struct{
    int codigo;
    char designacao[MAX_STRING];
    char tipoAula[MAX_STRING];
    int semestre;
    char regime[MAX_STRING];
    int quantidadeAulas;
    int duracao;
} tipoUc;


typedef struct{
    char designacao[MAX_STRING];
    char tipoDeAula[MAX_STRING];
    char regimeAula[MAX_STRING];
    char docente[MAX_STRING];
    tipoData data;
    float horaInicio;
    float horaFim;
    char *estadoAula;
    int gavacao;
    int codigo; //chave primaria UCs
} tipoAula;


typedef struct{
    int numeroEstudante;
    char nome[MAX_STRING];
    char regime[MAX_STRING];
} tipoEstudante;



#endif // contantes
