#ifndef FUNCOES_MENUS_H_INCLUDED
#define FUNCOES_MENUS_H_INCLUDED

#include "constantes.h"

char menu(tipoUc vetorUc[], int numUc, tipoAula vAulas[], int numTotalAulas);
char menuAulas();
//char menuAulas(tipoUc vetorUc[], int numUc);
char subMenuUc(tipoUc vetorUc[]);
char submenuAulas();

char subMenuAlteraUC();
char subMenuAlteraAula();
#endif // FUNCOES_MENUS_H_INCLUDED
