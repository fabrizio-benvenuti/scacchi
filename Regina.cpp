#include "Regina.h"

Regina::Regina(char colore, int riga, int colonna, string ID): Pezzo(colore,riga,colonna){
	this->ID=ID;
}

bool** Regina::mosse_disponibili(char color, int i, int j, Pezzo*** tabellone){
	bool** posizioni = new bool*[N];
	for(int a=0;a<N;a++){
		posizioni[a]=new bool[N];
	}
	this->init_mosse_disp(posizioni);

	//Adesso vado ad analizzare le mosse lungo le colonne
	Pezzo::mosse_ver(-1,color,&i,&j,posizioni,tabellone);//parte alta
	Pezzo::mosse_ver(1,color,&i,&j,posizioni,tabellone);//parte bassa
	//Adesso vado ad analizzare le mosse lungo le righe
	Pezzo::mosse_ori(1,color,&i,&j,posizioni,tabellone);//parte destra
	Pezzo::mosse_ori(-1,color,&i,&j,posizioni, tabellone);//parte sinistra
	//Vado ad analizzare le mosse lungo la diagonale primaria
	Pezzo::mosse_diag(-1,-1,color,&i,&j,posizioni,tabellone);//parte alta
	Pezzo::mosse_diag(1,1,color,&i,&j,posizioni,tabellone);//parte bassa
	//Vado ad analizzare le mosse lungo la diagonale secondaria
	Pezzo::mosse_diag(-1,1,color,&i,&j,posizioni,tabellone);//parte alta
	Pezzo::mosse_diag(1,-1,color,&i,&j,posizioni,tabellone);//parte bassa
	return posizioni;  //ritorna la posizione del primo elemento del vettore
}

string Regina::get_ID(){
	return this->ID;
}

Regina::~Regina(){}
