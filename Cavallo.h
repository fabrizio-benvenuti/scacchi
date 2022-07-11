#ifndef CAVALLO_H
#define CAVALLO_H

#include "Pezzo.h"

class Cavallo: public Pezzo{
	private:
		string ID;
	public:
		Cavallo(char colore, int riga, int colonna, string ID);
		virtual bool** mosse_disponibili(char colore, int riga, int colonna, Pezzo*** tabellone);
		virtual ~Cavallo();
		virtual string get_ID();
};

#endif		
	




