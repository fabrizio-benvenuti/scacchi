#include "BoolMat.h"

BoolMat::BoolMat(){//costruttore senza parametri
	data=new bool*[N];
	for(int i=0;i<N;i++){
		data[i]=new bool[N];
	}
}

BoolMat::BoolMat(bool value){//costruttore con parametro per inizializzare la matrice
	data=new bool*[N];
	for(int i=0;i<N;i++){
		data[i]=new bool[N];
	}
	this->init(value);
}

BoolMat::BoolMat(bool** data){//costruttore tramite copia del pontatore
	this->data=data;
}

BoolMat::~BoolMat(){
	for(int i=0;i<N;i++){
		delete[] data[i];
	}
	delete data;
}

void BoolMat::set(bool val, int i, int j){
	this->data[i][j]=val;
}

void BoolMat::set_data(bool** data){
	this->data=data;
}

void BoolMat::print(ostream& out){
	for(int i=0;i<N;i++){
		out<<"[ ";
		for(int j=0;j<N;j++){
			out<<this->data[i][j]<<" ";
		}
		out<<" ]"<<endl;
	}
}

void BoolMat::init(bool value){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			this->data[i][j]=value;
		}
	}
}

BoolMat BoolMat::somma(BoolMat& m1, BoolMat& m2){
	BoolMat m(false);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			m.data[i][j]=m1.data[i][j]+m2.data[i][j];
		}
	}
	return m;
}

void BoolMat::somma_in_place(BoolMat& m){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			this->data[i][j]+=m.data[i][j];
		}
	}
}

BoolMat operator+(BoolMat& mLeft, BoolMat& mRight){	
	return BoolMat::somma(mLeft,mRight);
}

BoolMat& operator+=(BoolMat& mLeft, BoolMat& mRight){	
	mLeft.somma_in_place(mRight);
	return mLeft;
}

ostream& operator<<(ostream& out, BoolMat& mRight){	
	mRight.print(out);
}

void BoolMat::rand_position(int& r, int& c){
	//vettori di char contententi le posizioni (r,c) delle celle true
	vector<char> row;
	vector<char> col;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(this->data[i][j]==1){//se la cella è true salvo le coordinate (r,c) in row e col
				row.push_back((char)i);
				col.push_back((char)j);
			}
		}
	}
	int dim=row.size();//numero di celle true
	if(dim!=0){
		int n=rand()%dim;//num casuale tra 0 e dim-1
		//salvo le coordinate della cella casuale in r e c
		r=(int)row[n];
		c=(int)col[n];
	}else{//se tutte le celle sono false
		r=-1;
		c=-1;
	}	
}

