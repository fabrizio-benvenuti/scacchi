#ifndef ALFIERE_H
#define ALFIERE_H

#include "Pezzo.h"

class Alfiere: public Pezzo{
	private:
		string ID;
		
	public:
		Alfiere(char colore, int riga, int colonna, string ID);
		virtual bool** mosse_disponibili(char color, int colonna, int riga, Pezzo*** tabellone);
		virtual ~Alfiere();
		virtual string get_ID();
};
#endif
