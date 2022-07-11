#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include "Pezzo.h"
#include "Cavallo.h"
#include "Alfiere.h"
#include "Regina.h"
#include "Pedone.h"
#include "Re.h"
#include "Torre.h"
#include "BoolMat.h"

class Scacchiera
{
	private:
        Pezzo*** tabellone;   //abbiamo una matrice di tipo puntatore a Pezzo
        void init();
        string stampa_carattere(char ID, char colore);
    public:
    	Scacchiera();   //costruttore
		~Scacchiera();   //distruttore
		void print();
		void set_pezzo(Pezzo* p,int i,int j);  //se il pezzo si muove, serve per modificare la cella
		Pezzo* get_pezzo(int i, int j);  //restituisce il contenuto della cella, ovvero se è occupata e in caso dal tipo di pezzo
		Pezzo*** get_tabellone();   //restituisce un puntatore alla matrice di tipo cella 
		void mossa(int i, int j, int i_new, int j_new);
		void print_file();
};

#endif
