#ifndef REGINA_H
#define REGINA_H

#include "Pezzo.h"

class Regina: public Pezzo{
	private:
		string ID;
	public:
		Regina(char colore, int riga, int colonna, string ID);
		virtual bool** mosse_disponibili(char color, int colonna, int riga, Pezzo*** tabellone);
		virtual ~Regina();
		virtual string get_ID();
};

#endif	



