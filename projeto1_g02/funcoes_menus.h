#ifndef FUNCOES_MENUS_H_INCLUDED
#define FUNCOES_MENUS_H_INCLUDED

#include "constantes.h"

char menu(tipoUc vetorUc[], int numUc, int quantAulasAgendadas, int quantAulasRealizadas);
char menuAulas();
char subMenuUc();
char submenuAulas();
char subMenuSalasOnline();
char subMenuEstudantes();
char subMenuDadosEstatisticos();

char subMenuAlteraUC();
char subMenuAlteraAula();
char subMenuAlteraEstudante();
#endif // FUNCOES_MENUS_H_INCLUDED
