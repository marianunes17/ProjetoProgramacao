#ifndef contantes
#define contantes

#define MAX_ALUNOS 100
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
    int numero;
    char nome[MAX_STRING];
} tipoEstudante;


typedef struct{
    char designacao[MAX_STRING];
    char tipoDeAula[MAX_STRING];
    char regimeAula;
    char docente[MAX_STRING];
    tipoData data;
    float horaInicio;
    float horaFim;
    char *estadoAula;
    int gavacao;
    int codigo; //chave primaria UCs
} tipoAula;



#endif // contantes
