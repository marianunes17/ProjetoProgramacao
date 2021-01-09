#ifndef FUNCOES_MENUS_H_INCLUDED
#define FUNCOES_MENUS_H_INCLUDED

#include "constantes.h"

char menu(tipoUc vetorUc[], int numUc, tipoAula vAulas[], int numTotalAulas);
char menuAulas();
char subMenuUc(tipoUc vetorUc[]);
char submenuAulas();
char subMenuSalasOnline();

char subMenuAlteraUC();
char subMenuAlteraAula();
#endif // FUNCOES_MENUS_H_INCLUDED
