#include "Pezzo.h"

Pezzo::Pezzo(char colore, int riga, int colonna){
	this->colore=colore;
	this->riga=riga;
	this->colonna=colonna;
}

void Pezzo::mosse_diag(int x, int y, char color,const int* i,const int* j, bool** posizioni, Pezzo*** tabellone){
	while((*i+x)<N&&(*j+y)<N&&(*i+x)>=0&&(*j+y)>=0){
		if(tabellone[*i+x][*j+y]==nullptr){
			posizioni[*i+x][*j+y]=1;
		}else if(((color=='B')&&(tabellone[*i+x][*j+y]->get_colore()=='W'))||
				((color=='W')&&(tabellone[*i+x][*j+y]->get_colore()=='B'))){
			posizioni[*i+x][*j+y]=1;
			break;
		}else break;
		x=x+1*((-2)*signbit((float)x)+1);//((-2)*signbit((float)x)+1) restituisce -1 se x è negativo, +1 altrimenti
		y=y+1*((-2)*signbit((float)y)+1);	
	}
}

void Pezzo::mosse_ver(int xx, char Bcolor,const int* r,const int* c, bool** posizioni, Pezzo*** tabellone){
	while((*r+xx)<N&&(*r+xx)>=0&&(*c)<N&&(*c)>=0){//controlla che non esca fuori dalla matrice
		if(tabellone[*r+xx][*c]==nullptr){
			posizioni[*r+xx][*c]=1;
		}else if(((Bcolor=='B')&&(tabellone[*r+xx][*c]->get_colore()=='W'))||((Bcolor=='W')&&(tabellone[*r+xx][*c]->get_colore()=='B'))){   //se trovo un pezzo del colore avversario, posso mangiarlo ma non posso "saltarlo"
			posizioni[*r+xx][*c]=1;
			break;
		}else{     //se trovo un pezzo del mio stesso colore mi fermo
			posizioni[*r+xx][*c]=0;
			break;
		}
		xx=xx+1*((-2)*signbit((float)xx)+1);
	}
}

void Pezzo::mosse_ori(int yy, char Ccolor,const int* rr,const int* cc, bool** posizioni, Pezzo*** tabellone){
	while((*cc+yy)<N&&(*cc+yy)>=0&&(*rr<N)&&(*rr>=0)){
		if(tabellone[*rr][*cc+yy]==nullptr){
			posizioni[*rr][*cc+yy]=1;
		}else if(((Ccolor=='B')&&(tabellone[*rr][*cc+yy]->get_colore()=='W'))||((Ccolor=='W')&&(tabellone[*rr][*cc+yy]->get_colore()=='B'))){   //se trovo un pezzo del colore avversario, posso mangiarlo ma non posso "saltarlo"
			posizioni[*rr][*cc+yy]=1;
			break;
		}else{     //se trovo un pezzo del mio stesso colore mi fermo
			posizioni[*rr][*cc+yy]=0;
			break;
		}
		yy=yy+1*((-2)*signbit((float)yy)+1);
	}
}

char Pezzo::get_colore(){
	return this->colore;
}

int Pezzo::get_colonna(){
	return this->colonna;
}

int Pezzo::get_riga(){
	return this->riga;
}

void Pezzo::set_riga(int riga){
	this->riga=riga;
}

void Pezzo::set_colonna(int colonna){
	this->colonna=colonna;
}

Pezzo::~Pezzo(){}

void Pezzo::init_mosse_disp(bool** posizioni){// inizializza la matrice delle mosse disponibili a 0
	for(int a=0;a<N;a++){
		for(int b=0;b<N;b++){
			posizioni[a][b]=0;
		}
	}
}
