#include "Cavallo.h"

Cavallo::Cavallo(char colore, int riga, int colonna, string ID): Pezzo(colore,riga,colonna){
	this->ID=ID;
}

bool** Cavallo::mosse_disponibili(char colore, int i, int j, Pezzo*** tabellone){
	//abbiamo i=righe, j=colonne
	bool** posizioni = new bool*[N];
	for(int a=0;a<N;a++){
		posizioni[a]=new bool[N];
	}
	//se abbiamo 1, vuol dire che quella posizione è possibile, con 0 non lo è
	this->init_mosse_disp(posizioni);
	//tutte le otto mosse massime che il cavallo può compiere
	for(int r=i-2;r<=i+2;r++){
		for(int c=j-2;c<=j+2;c++){
			if(r!=i && c!=j && r>=0 && r<N && c>=0 && c<N){//controllo anche che gli indici k e l non vadano fuori dalla matrice 8x8
				if((abs(r-i)==2 && abs(c-j)==1)||(abs(r-i)==1 && abs(c-j)==2)){
					if(tabellone[r][c]==nullptr){
						posizioni[r][c]=1;
					}else if(tabellone[r][c]->get_colore()!=colore){
						posizioni[r][c]=1;
					}
				}	
			}
		}
	}
	return posizioni;
}

string Cavallo::get_ID(){
	return this->ID;
}

Cavallo::~Cavallo(){}

