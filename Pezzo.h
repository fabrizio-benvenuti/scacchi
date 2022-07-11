#ifndef PEZZO_H
#define PEZZO_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#define N 8

using namespace std;

class Pezzo{
	protected:
		char colore;
		int riga;
		int colonna;		
	public:
		Pezzo(char colore, int riga, int colonna);
		virtual bool** mosse_disponibili(char color, int colonna, int riga, Pezzo*** tabellone)=0;//funzione virtuale e astratta
		virtual ~Pezzo();
		char get_colore();
		int get_riga();
		int get_colonna();
		void set_riga(int riga);
		void set_colonna(int colonna);
		static void mosse_diag(int x,int y, char color,const int* i,const int* j, bool** posizioni, Pezzo*** tabellone);
		static void mosse_ver(int x, char color,const int* i,const int* j, bool** posizioni, Pezzo*** tabellone);
		static void mosse_ori(int y, char color,const int* i,const int* j, bool** posizioni, Pezzo*** tabellone);
		virtual string get_ID()=0;
		void init_mosse_disp(bool** posizioni);
};

#endif

