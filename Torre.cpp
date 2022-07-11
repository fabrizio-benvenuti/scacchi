#include "Torre.h"

Torre::Torre(char colore, int riga, int colonna, string ID): Pezzo(colore,riga,colonna){
	this->ID=ID;
}

bool** Torre::mosse_disponibili(char color, int i, int j, Pezzo*** tabellone){
	//abbiamo i=righe, j=colonne
	bool** posizioni = new bool*[N];
	for(int a=0;a<N;a++){
		posizioni[a]=new bool[N];
	}
	this->init_mosse_disp(posizioni);
	//Adesso vado ad analizzare le mosse lungo le righe
	Pezzo::mosse_ver(-1,color,&i,&j,posizioni,tabellone);//parte alta
	Pezzo::mosse_ver(1,color,&i,&j,posizioni,tabellone);//parte bassa
	Pezzo::mosse_ori(1,color,&i,&j,posizioni,tabellone);//parte destra
	Pezzo::mosse_ori(-1,color,&i,&j,posizioni,tabellone);//parte sinistra
	return posizioni;  //ritorna la posizione del primo elemento del vettore
}

string Torre::get_ID(){
	return this->ID;
}

Torre::~Torre(){}
