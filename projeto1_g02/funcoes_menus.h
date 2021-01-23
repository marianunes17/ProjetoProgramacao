#ifndef FUNCOES_MENUS_H_INCLUDED
#define FUNCOES_MENUS_H_INCLUDED

#include "constantes.h"

char menu(int numUc, int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas);
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
