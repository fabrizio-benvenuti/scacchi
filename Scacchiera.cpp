#include "Scacchiera.h"

Scacchiera::Scacchiera(){     //costruttore
	this->tabellone=new Pezzo**[N];
	for(int i=0;i<N;i++){
		tabellone[i]=new Pezzo*[N];
	}
	this->init();
}

Scacchiera::~Scacchiera(){   //distruttore
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(tabellone[i][j]!=nullptr) delete tabellone[i][j];
		}
		delete[] tabellone[i];
	}
	delete[] tabellone;
}

void Scacchiera::init(){//gli oggetti figli vanno allocati dinamicamente per sfruttare il polimorfismo
	//vanno deallocati gli oggetti a fine partita
	Cavallo* C1W=new Cavallo('W',0,1,"C1");
	this->set_pezzo(C1W,0,1);
	Cavallo* C2W=new Cavallo('W',0,6,"C2");
	this->set_pezzo(C2W,0,6);
	Torre* T1W=new Torre('W',0,0,"T1");
	this->set_pezzo(T1W,0,0);
	Torre* T2W=new Torre('W',0,7,"T2");
	this->set_pezzo(T2W,0,7);
	Regina* DW=new Regina('W',0,3,"D-");
	this->set_pezzo(DW,0,3);
	Re* RW=new Re('W',0,4,"R-");
	this->set_pezzo(RW,0,4);
	Alfiere* A1W=new Alfiere('W',0,2,"A1");
	this->set_pezzo(A1W,0,2);
	Alfiere* A2W=new Alfiere('W',0,5,"A2");
	this->set_pezzo(A2W,0,5);
	Cavallo* C1B=new Cavallo('B',7,1,"C1");
	this->set_pezzo(C1B,7,1);
	Cavallo* C2B=new Cavallo('B',7,6,"C2");
	this->set_pezzo(C2B,7,6);
	Torre* T1B=new Torre('B',7,0,"T1");
	this->set_pezzo(T1B,7,0);
	Torre* T2B=new Torre('B',7,7,"T2");
	this->set_pezzo(T2B,7,7);
	Regina* DB=new Regina('B',7,3,"D-");
	this->set_pezzo(DB,7,3);
	Re* RB=new Re('B',7,4,"R-");
	this->set_pezzo(RB,7,4);
	Alfiere* A1B=new Alfiere('B',7,2,"A1");
	this->set_pezzo(A1B,7,2);
	Alfiere* A2B=new Alfiere('B',7,5,"A2");
	this->set_pezzo(A2B,7,5);
	Pedone* P1W=new Pedone('W',1,0,"P1");
	this->set_pezzo(P1W,1,0);
	Pedone* P2W=new Pedone('W',1,1,"P2");
	this->set_pezzo(P2W,1,1);
	Pedone* P3W=new Pedone('W',1,2,"P3");
	this->set_pezzo(P3W,1,2);
	Pedone* P4W=new Pedone('W',1,3,"P4");
	this->set_pezzo(P4W,1,3);
	Pedone* P5W=new Pedone('W',1,4,"P5");
	this->set_pezzo(P5W,1,4);
	Pedone* P6W=new Pedone('W',1,5,"P6");
	this->set_pezzo(P6W,1,5);
	Pedone* P7W=new Pedone('W',1,6,"P7");
	this->set_pezzo(P7W,1,6);
	Pedone* P8W=new Pedone('W',1,7,"P8");
	this->set_pezzo(P8W,1,7);
	Pedone* P1B=new Pedone('B',6,0,"P1");
	this->set_pezzo(P1B,6,0);
	Pedone* P2B=new Pedone('B',6,1,"P2");
	this->set_pezzo(P2B,6,1);
	Pedone* P3B=new Pedone('B',6,2,"P3");
	this->set_pezzo(P3B,6,2);
	Pedone* P4B=new Pedone('B',6,3,"P4");
	this->set_pezzo(P4B,6,3);
	Pedone* P5B=new Pedone('B',6,4,"P5");
	this->set_pezzo(P5B,6,4);
	Pedone* P6B=new Pedone('B',6,5,"P6");
	this->set_pezzo(P6B,6,5);
	Pedone* P7B=new Pedone('B',6,6,"P7");
	this->set_pezzo(P7B,6,6);
	Pedone* P8B=new Pedone('B',6,7,"P8");
	this->set_pezzo(P8B,6,7);
	for(int i=2;i<6;i++){
		for(int j=0;j<N;j++){
			Pezzo* p=nullptr;
			this->set_pezzo(p,i,j);
		}
	}		
}

void Scacchiera::print(){   
	cout<<"     a   b   c   d   e   f   g   h  "<<endl;
	for(int i=0;i<N;i++){
		cout<<i+1<<" | ";
		for(int j=0;j<N;j++){
			if(this->tabellone[i][j]==nullptr)
				cout<<"000 ";
			else
				cout<<this->tabellone[i][j]->get_ID()<<this->tabellone[i][j]->get_colore()<<" ";
		}	
		cout<<"|"<<endl;
	}
}
void Scacchiera::set_pezzo(Pezzo* p, int i, int j){
	if((i<0 || i>N)&&(j<0 || j>N)){
		cout<<"error";
	}
	this->tabellone[i][j]=p;
}
Pezzo* Scacchiera::get_pezzo(int i, int j){   //restituisce l'indirizzo del pezzo in posizione i j
	if((i<0 || i>N)&&(j<0 || j>N)){
		cout<<"error";
	}
	return this->tabellone[i][j];
}
Pezzo*** Scacchiera::get_tabellone(){
	return tabellone;
}
void Scacchiera::mossa(int i,int j,int i_new,int j_new){
	this->set_pezzo(this->tabellone[i][j],i_new,j_new);
	this->set_pezzo(nullptr,i,j);
	this->get_pezzo(i_new,j_new)->set_riga(i_new);
	this->get_pezzo(i_new,j_new)->set_colonna(j_new);
}

void Scacchiera::print_file(){
	//ofstream of("scacchiera_attuale.doc",ios::app);//apertura del file in modalità append per salvare tutte le scacchiere progressive
	ofstream of("scacchiera_attuale.doc");
	of<<"   \u24B6\u24B7\u24B8\u24B9\u24BA\u24BB\u24BC\u24BD"<<endl;
	of<<"-----------------"<<endl;
	for(int i=0;i<N;i++){
		of<<i+1<<"| ";
		for(int j=0;j<N;j++){
			if(j==0 && this->tabellone[i][j]==nullptr){
				of<<" ";
			}
			if(this->tabellone[i][j]==nullptr)
				of<<"\u2610";
			else{
				of<<stampa_carattere(this->tabellone[i][j]->get_ID().at(0),this->tabellone[i][j]->get_colore());
			}	
		}
		of<<endl;
	}
	of<<"-----------------"<<endl;
	of<<"   \u24B6\u24B7\u24B8\u24B9\u24BA\u24BB\u24BC\u24BD";
	of.close();
}

string Scacchiera::stampa_carattere(char ID, char colore){
	switch(ID){
		case 'D':   //Donna
			if(colore=='W') return "\u2655";
			return "\u265B";
		case 'R':    //Re
			if(colore=='W') return "\u2654";
			else return "\u265A";
		case 'C':    //Cavallo
			if(colore=='W') return "\u2658";
			else return "\u265E";
		case 'A':    //alfiere
			if(colore=='W') return "\u2657";
			else return "\u265D";
		case 'P':    //Pedone
			if(colore=='W') return "\u2659";
			else return "\u265F";
		case 'T':    //Torre
			if(colore=='W') return "\u2656";
			else return "\u265C";
	}
}
