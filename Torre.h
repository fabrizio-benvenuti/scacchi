#ifndef TORRE_H
#define TORRE_H

#include "Pezzo.h"

class Torre: public Pezzo{
	private:
		string ID;
	public:
		Torre(char colore, int riga, int colonna, string ID);
		virtual bool** mosse_disponibili(char color, int colonna, int riga, Pezzo*** tabellone);
		virtual ~Torre();
		virtual string get_ID();
};

#endif

