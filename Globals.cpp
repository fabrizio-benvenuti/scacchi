#include "Globals.h"
bool cont_part(Scacchiera *s,char color){   //CONTINUA PARTITA: funzione che verifica se c'è almeno una mossa che si possa fare per evitare lo scacco matto
	char coloreA;//Colore Avversario
	string col_s;//stringa "bianco" invece che B
	bool contP=true;//false=continua la partita; true=non ci sono più mosse disponibili, la partita dovrà terminare
	if(color=='W'){
		coloreA='B';
		col_s="Bianco";
	}	
	else{
		coloreA='W';
		col_s="Nero";
	} 
	//per ogni pezzo dell'avversario controllo le mosse disponibili
	//per ogni mossa disponibile controllo se mette sotto scacco il mio re
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(s->get_pezzo(i,j)!=nullptr){
				if(s->get_pezzo(i,j)->get_colore()==coloreA){
					BoolMat mossDisp(s->get_pezzo(i,j)->mosse_disponibili(coloreA,i,j,s->get_tabellone()));//matrice delle mosse disponibili del pezzo (i,j)
					for(int k=0;k<N;k++){
						for(int y=0;y<N;y++){
							if(mossDisp.get(k,y)==1){
								if(scacco(s,coloreA,i,j,k,y,true,false)==0){ //se c'è almeno una mossa che si può fare per evitare lo scacco matto
									return false;
								}
							}
						}	
					}
				}
			}
		}
	}
	cout<<"La Partita e' finita ";
	if(controllo_parita(s,false,coloreA)==true){//se sono sotto scacco e la partita è finita
		cout<<"in parita'."<<endl;
	}
	else{
		cout<<"per scacco matto, ha vinto il: "<<col_s<<"!!!";
	}
	return true;
}
														//no_m non fa la mossa quando controllo la parita' per il re
bool scacco(Scacchiera* s, char color, int r, int c, int r_n, int c_n, bool cp, bool no_m){ //funzione che controlla se il re, dopo la mossa, è sotto scacco
	//se cp è false: restituisce true se il mio re è sotto scacco, false altrimenti
	//se cp (controllo partita) è true: la funzione è usata per il controllare se la partita è finita
	Pezzo* p_new=s->get_pezzo(r_n,c_n);//salvo il puntatore al pezzo nella posizione in cui vado a fare la mossa
	if(no_m==false){//la mossa non viene eseguita se si controlla la parità
		s->mossa(r,c,r_n,c_n);
	}
	BoolMat m(false);
	int r_re, c_re;
	char coloreA;//colore avversario
	if(color=='W') coloreA='B';
	else coloreA='W';
	//per ogni pezzo dell'avversario chiamo la funzione mosse disponibili e sommo tutte queste matrici in m
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(s->get_pezzo(i,j)!=nullptr){
				if(s->get_pezzo(i,j)->get_ID().at(0)=='R' && s->get_pezzo(i,j)->get_colore()==color){//salvo la posizione del mio re 
					r_re=i;
					c_re=j;
				}
				if(s->get_pezzo(i,j)->get_colore()==coloreA){
					BoolMat m1;
					m1.set_data(s->get_pezzo(i,j)->mosse_disponibili(coloreA,i,j,s->get_tabellone()));
					m+=m1;
				}
			}
		}
	}
	if(m.get(r_re,c_re)==true && no_m==false){//se l'avversario può mangiare il mio re e posso fare la mossa al contrario
		if(cp==false){
			cout<<"Questa mossa ti metterebbe sotto scacco, inserisci un'altra mossa..."<<endl;
		}
		s->mossa(r_n,c_n,r,c);//mossa all'indietro
		s->set_pezzo(p_new,r_n,c_n);//rimetto il pezzo in posizione originaria
		return true;
	}
	else if(cp==true && no_m==false){//se sto controllando la parità, il re non è sotto scacco e non sto controllando per lo scacco matto
		s->mossa(r_n,c_n,r,c);
		s->set_pezzo(p_new,r_n,c_n);	
		return false;
	}
	else if(cp==false){//se la mossa è effettivamente disponibile (cioè il re non è sotto scacco e cp è false)
		if(no_m==false){
			cout<<"Mossa eseguita correttamente!"<<endl;
		}
		return false;
	}
}

int get_col(char c){ //converte la colonna in un numero
	switch(c){
		case 'a':
			return 0;
			break;
		case 'b':
			return 1;
			break;
		case 'c':
			return 2;
			break;
		case 'd':
			return 3;
			break;
		case 'e':
			return 4;
			break;
		case 'f':
			return 5;
			break;
		case 'g':
			return 6;
			break;
		case 'h':
			return 7;
			break;
		default:
			return -1;
	}
}

void input(int* r, int* c, int* r_new, int* c_new, Scacchiera* s, char color){ //gestisce l'input del pezzo da muovere e della mossa inserita; controlla se gli input sono validi
	string mossa_inserita;
	string pezzo_da_muovere;
	bool flag;
	int i=0;
	//controllo che righe e colonne inserite siano nel range [0,7], controlla anche se il pezzo da muovere è dello stesso colore di chi gioca
	do{
		flag=false;
		do{
			if(i!=0) cout<<"Input non valido!"<<endl;
			cout<<endl<<"--> Quale pezzo vuoi muovere?  ";
			cin>>pezzo_da_muovere;    //Inserire la posizione del pezzo che voglio muovere
			if(pezzo_da_muovere.length()!=2){
				flag=true;
				i++;
				break;
			}
			*r=pezzo_da_muovere.at(1)-'0';
			*r-=1;
			*c=get_col(pezzo_da_muovere.at(0));
			i++;
		}while((*r<0 || *r>=N) || (*c<0 || *c>=N));
		if(flag==false){
			if(s->get_pezzo(*r,*c)==nullptr){
				flag=true;
				cout<<"In questa posizione non e' presente nessun pezzo!"<<endl;
			}else if(s->get_pezzo(*r,*c)->get_colore()!=color){
				flag=true;
				cout<<"Non puoi muovere questo pezzo!"<<endl;
			}
		}	
	}while(flag);
	i=0;
	do{
		flag=false;
		do{
			if(i!=0) cout<<"Input non valido!"<<endl;
			cout<<"--> Inserisci la mossa...  ";
			cin>>mossa_inserita;
			if(mossa_inserita.length()!=2){
				flag=true;
				i++;
				break;
			}
			*r_new=mossa_inserita.at(1)-'0';
			*r_new-=1;
			*c_new=get_col(mossa_inserita.at(0));
			i++;
		}while((*r_new<0 || *r_new>=N) || (*c_new<0 || *c_new>=N));	
	}while(flag);
	system("cls");
}

bool turno_gioco(char color, string player, Scacchiera* s, bool* flag){//restituisce true se è scacco matto e la partita finisce, false altrimenti
	bool fineP=0; //finchè è uguale   //Fine Partita
	BoolMat punta(nullptr);
	int r,c,r_new,c_new;
	input(&r,&c,&r_new,&c_new,s,color);
	punta.set_data(s->get_pezzo(r,c)->mosse_disponibili(s->get_pezzo(r,c)->get_colore(),r,c,s->get_tabellone())); //assegno a punta l'indirizzo del primo elemento della matrice con le mosse disponibili
//	cout<<punta;     stamapva le mosse disponibili del pezzo in posizione r,c
	if(punta.get(r_new,c_new)==1){//se la mossa è disponibile
		*flag=scacco(s,color,r,c,r_new,c_new,false,false); //richiamo scacco che esegue la mossa e controlla se quella mossa mette sotto scacco
	}else{
		system("cls");
		cout<<"Mossa non disponibile"<<endl;
		*flag=true;
	}
	if(*flag!=true){//se la mossa è effettivamente disponibile
		fineP=cont_part(s,color);//controllo lo scacco matto
		if(fineP==true){//se è scacco matto la partita termina
			//cout<<"*** SCACCO MATTO, la partita e' terminata ***"<<endl;
			*flag=true;
			return fineP;
		}
	}
	return false;
}

bool gioco_computer(char color, Scacchiera* s, bool* flag){ //il computer gioca in modo casuale; color: colore giocatore
	BoolMat pezzi_propri(false);//matrice con 1 se c'è un pezzo del tuo colore, 0 altrimenti
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(s->get_pezzo(i,j)!=nullptr){
				if(s->get_pezzo(i,j)->get_colore()==color){
					pezzi_propri.set(true,i,j);
				}
			}
		}
	}
	srand(time(NULL));
	int r,c;//riga e colonna casuali tra le celle true della matrice dei pezzi propri
	int r_new,c_new;//riga e colonna casuali tra le mosse dipsonibili del pezzo
	bool fineP=0;//finchè è uguale a 0; FINE partita
	do{
		pezzi_propri.rand_position(r,c);
		BoolMat mosse_disp(false);//matrice delle mosse disponibili
		mosse_disp.set_data(s->get_pezzo(r,c)->mosse_disponibili(color,r,c,s->get_tabellone()));//matrice con le mosse disponibili del pezzo in posizione casuale
	//	cout<<mosse_disp;
		mosse_disp.rand_position(r_new,c_new);
	}while(r_new==-1);//entro nel ciclo e genero un pezzo casuale, se questo pezzo non ha mosse disponibili all'iterazione successiva genero un altro pezzo
	*flag=scacco(s,color,r,c,r_new,c_new,false,false);
	if(*flag!=true){
		fineP=cont_part(s,color);
		if(fineP==true){
			*flag=true;
			return fineP;
		}
	}
	return false;
}

void new_partita(string player1, string player2){//funzione che inizia una nuova partita e gestisce i turni con il controllo dell'andamento della partita
	bool matto=0;//false se non è scacco matto, true altrimenti;
	bool flag=0;//false se la mossa è disponibile (con il controllo dello scacco), true altrimenti;
	Scacchiera s;
	bool parita=0;     //1 se ci sono solo re, 0 se questo non è vero
	int i=0;  //variabile contatore
	while(matto==0 || flag==0){
		if(parita==1){
			cout<<"La partita e' finita in parita'"<<endl;
			break;
		}
		parita=controllo_parita(&s,true,'W');  //si mette 'W' perchè quando controllo il re non mi interessa il colore,è casuale
		if(i%2==0){   //quando è pari gioca il bianco, quando è dispari gioca il nero
			cout<<"------------------------------------------"<<endl;
			cout<<"Turno "<<player1<<" WHITE"<<endl;
			s.print();
			s.print_file();
			if(!player1.compare("computer")){
				matto=gioco_computer('W',&s,&flag);
			}else{
				matto=turno_gioco('W',player1,&s,&flag);
			}
		}else{
			cout<<"------------------------------------------"<<endl;
			cout<<"Turno "<<player2<<" BLACK"<<endl;
			s.print();
			s.print_file();
			if(!player2.compare("computer")){
				matto=gioco_computer('B',&s,&flag);
			}else{
				matto=turno_gioco('B',player2,&s,&flag);
			}	
		}
		if(flag==0){
			if(!player1.compare("computer") && !player2.compare("computer")){
				cout<<"Premere INVIO per passare al prossimo turno....";
				cin.ignore();//cancella il buffer dell'input togliendo tutti i caratteri inseriti in precendenza
				cin.get();//prende in input un carattere
				system("cls");
			}
		 	i++;//se la mossa è effettivamente disponibile incremento il contatore e gioca l'avversario
		} 
	}
}
//controlla se sono rimasti solo i due re e se l'avversario non ha più mosse disponibili e non è scacco, in caso la partita finisce in parità
bool controllo_parita(Scacchiera* s,bool cr,char color){//cr vero se controllo il re,la partita è finita(cont_part)  
	int col_r; //colonna del nostro re
	int rig_r;//riga del nostro re
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(s->get_pezzo(i,j)!=nullptr){
				if(s->get_pezzo(i,j)->get_ID().at(0)!='R'){
					if(cr==true){//se trova un pezzo diverso dal re restituisce true
						return false;
					}
				}
				else if(cr==false){ //se non controllo i re
					if(s->get_pezzo(i,j)->get_ID().at(0)=='R' && s->get_pezzo(i,j)->get_colore()==color){
						return scacco(s,color,i,j,i,j,false,true);//cp false, no_m true
					}
				}
			}
		}
	}
	if(cr==true){
		return true;      //ritorna vero se sono rimasti solo re
	}
	else{
		return false;
	}
}
