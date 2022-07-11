#ifndef GLOBALS_H
#define GLOBALS_H

#include "Scacchiera.h"
bool scacco(Scacchiera* s,char color,int r, int c, int r_n,int c_n,bool cp,bool no_m);
int get_col(char c);
void input(int* r, int* c, int* r_new, int* c_new, Scacchiera* s, char color);
bool turno_gioco(char color, string player, Scacchiera* s, bool* flag);
bool gioco_computer(char color, Scacchiera* s);
void new_partita(string player1, string player2);
bool controllo_parita(Scacchiera* s,bool cr,char color);
bool cont_part(Scacchiera *s,char color);

#endif
