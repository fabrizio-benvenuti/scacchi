#include "Pedone.h"
#include "Regina.h"

Pedone::Pedone(char colore, int riga, int colonna, string ID): Pezzo(colore,riga,colonna){
	this->ID=ID;
}

void Pedone::promozione(Pezzo*** tabellone){
	if(riga==0 || riga==7){
		Regina* D1=new Regina(colore,riga,colonna,"D-");
		tabellone[riga][colonna]=D1;
	}
}

bool** Pedone::mosse_disponibili(char colore, int i, int j, Pezzo*** tabellone){
	//abbiamo i=righe, j=colonne
	bool** posizioni = new bool*[N];
	for(int a=0;a<N;a++){
		posizioni[a]=new bool[N];
	}
	this->init_mosse_disp(posizioni);
	if(colore=='W'){  //mosse disponibili se il pedone è bianco
		if(i+1<N && i+1>=0 && j<N && j>=0 && tabellone[i+1][j]==nullptr){ //posso muovere il pedone avanti se non ho nessun pezzo davanti
			posizioni[i+1][j]=1;
		}
		if(i+1<N && i+1>=0 && j+1<N && j+1>=0 && tabellone[i+1][j+1]!=nullptr){ //il pedone mangia in diagonale (destra)
			if(tabellone[i+1][j+1]->get_colore()=='B'){
				posizioni[i+1][j+1]=1;
			}
		}
		if(i+1<N && i+1>=0 && j-1<N && j-1>=0 && tabellone[i+1][j-1]!=nullptr){ //il pedone mangia in diagonale (sinistra)
			if(tabellone[i+1][j-1]->get_colore()=='B'){
				posizioni[i+1][j-1]=1;
			}
		}
		if(j>=0 &&(i==1)&&(tabellone[3][j]==nullptr)&&(tabellone[2][j]==nullptr)){
			posizioni[3][j]=1;   //se il pedone è in posizione iniziale posso muoverlo aventi di due caselle
		}
	}else if(colore=='B'){  //mosse disponibili se il pedone è nero
		if(i-1<N && i-1>=0 && j<N && j>=0 && tabellone[i-1][j]==nullptr){ //posso muovere il pedone avanti se non ho nessun pezzo davanti
			posizioni[i-1][j]=1;
		}if(i-1<N && i-1>=0 && j+1<N && j+1>=0 && tabellone[i-1][j+1]!=nullptr){ //il pedone mangia in diagonale(destra)
			if(tabellone[i-1][j+1]->get_colore()=='W'){
				posizioni[i-1][j+1]=1;
			}
		}
		if(i-1<N && i-1>=0 && j-1<N && j-1>=0 && tabellone[i-1][j-1]!=nullptr){ //il pedone mangia in diagonale(sinistra)
			if(tabellone[i-1][j-1]->get_colore()=='W'){
				posizioni[i-1][j-1]=1;
			}
		}
		if(j>=0 && (i==6)&&(tabellone[4][j]==nullptr)&&(tabellone[5][j]==nullptr)){ //se il pedone è in posizione inisiale posso muoverlo avanti di due caselle
			posizioni[4][j]=1;
		}
	}
	promozione(tabellone);
	return posizioni;  //ritorna il puntatore alla matrice posizioni
}

string Pedone::get_ID(){
	return this->ID;
}

Pedone::~Pedone(){}

