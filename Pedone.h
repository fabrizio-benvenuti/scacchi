#ifndef PEDONE_H
#define PEDONE_H

#include "Pezzo.h"

class Pedone: public Pezzo{
	private:
		string ID;
	public:
		Pedone(char colore, int riga, int colonna, string ID);
		virtual bool** mosse_disponibili(char colore, int colonna, int riga, Pezzo*** tabellone);
		virtual ~Pedone();
		virtual string get_ID();
		void promozione(Pezzo*** tabellone);
};

#endif
