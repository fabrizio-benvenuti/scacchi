#ifndef BOOLMAT_H
#define BOOLMAT_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#define N 8

using namespace std;

class BoolMat{
	private:
		bool** data;
	public:
		BoolMat();
		BoolMat(bool value);//costruttore con inizializzazione della matrice a "value"
		BoolMat(bool** data);//costruttore tramite set del puntatore
		~BoolMat();
		void init(bool value);
		void set(bool val, int i, int j);
		inline bool get(int i, int j) {return this->data[i][j];}
		void set_data(bool** data);
		inline bool** get_data() {return this->data;}
		void print(ostream& out);
		static BoolMat somma(BoolMat& m1, BoolMat& m2);//restituisce la matrice somma di m1 e m2
		void somma_in_place(BoolMat& m);//somma di m sull'istanza a cui è applicato
		void rand_position(int& r, int& c);//(r,c): riga e colonna di una cella casuale tra quelle che sono true 
		friend BoolMat operator+(BoolMat& mLeft, BoolMat& mRight);
		friend BoolMat& operator+=(BoolMat& mLeft, BoolMat& mRight);//somma di mRight su mLeft, restituisce il riferimento di mLeft
		friend ostream& operator<<(ostream& out, BoolMat& mRight);//operatore per la stampa della matrice
};

#endif
