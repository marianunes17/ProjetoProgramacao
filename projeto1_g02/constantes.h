#ifndef contantes
#define contantes

#define MAX_ALUNOS 100
#define MAX_UC 40
#define MAX_STRING 100
#define MAX_STRING_AULAS 50

typedef struct{
    int dia, mes, ano;
} tipoData;


typedef struct{
    int codigo;
    char designacao[MAX_STRING];
    char tipo[MAX_STRING];
    int semestre;
    char regime[MAX_STRING];
    int duracao;
} tipoUc;


typedef struct{
    int numero;
    char nome[MAX_STRING];
} tipoEstudante;


typedef struct{
    char designacao[MAX_STRING_AULAS];
    char tipoDeAula;
    char docente[MAX_STRING_AULAS];
    tipoData data;
    float hora;
    char estadoAula;
    int gavacao;
    int codigo; //chave primaria UCs
} tipoAula;



#endif // contantes
