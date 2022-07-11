#include "Alfiere.h"

Alfiere::Alfiere(char colore, int riga, int colonna, string ID): Pezzo(colore,riga,colonna){
	this->ID=ID;
}

bool** Alfiere::mosse_disponibili(char color, int i, int j, Pezzo*** tabellone){
	//abbiamo i=righe, j=colonne
	bool** posizioni = new bool*[N];
	for(int a=0;a<N;a++){
		posizioni[a]=new bool[N];
	}
	this->init_mosse_disp(posizioni);
	//Vado ad analizzare le mosse lungo la diagonale primaria
	Pezzo::mosse_diag(-1,-1,color,&i,&j,posizioni,tabellone);//parte alta
	Pezzo::mosse_diag(1,1,color,&i,&j,posizioni,tabellone);//parte bassa
	//Vado ad analizzare le mosse lungo la diagonale secondaria
	Pezzo::mosse_diag(-1,1,color,&i,&j,posizioni,tabellone);//parte alta
	Pezzo::mosse_diag(1,-1,color,&i,&j,posizioni,tabellone);//parte bassa	
	return posizioni;  //ritorna la posizione del primo elemento del vettore	
}

string Alfiere::get_ID(){
	return this->ID;
}

Alfiere::~Alfiere(){}
