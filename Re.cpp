#include "Re.h"

Re::Re(char colore, int riga, int colonna, string ID): Pezzo(colore, riga, colonna){
	this->ID=ID;
}

bool** Re::mosse_disponibili(char color, int i, int j, Pezzo*** tabellone){
	bool** posizioni = new bool*[N];
	for(int a=0;a<N;a++){
		posizioni[a]=new bool[N];
	}
	this->init_mosse_disp(posizioni);
	for(int x=i-1;x<=i+1;x++){
		for(int y=j-1;y<=j+1;y++){
			if(x>=0 && y>=0 && x<N && y<N){
				if(x!=i || y!=j){
					if(tabellone[x][y]==nullptr){
						posizioni[x][y]=1;
					}
					else if(tabellone[x][y]->get_colore()!=color) {
						posizioni[x][y]=1;
					}
				}
			}
		}
	}	
	return posizioni;
}

string Re::get_ID(){
	return this->ID;
}

Re::~Re(){}
