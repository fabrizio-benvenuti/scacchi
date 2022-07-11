#ifndef RE_H
#define RE_H

#include "Pezzo.h"
class Re: public Pezzo{
	private:
		string ID;
	public:
		Re(char colore, int riga, int colonna, string ID);   //Costruttore
		virtual bool** mosse_disponibili(char colore, int colonna, int riga, Pezzo*** tabellone);
		virtual ~Re();
		virtual string get_ID();
};
#endif
