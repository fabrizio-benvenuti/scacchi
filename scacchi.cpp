#include "Scacchiera.h"
#include "Globals.h"

int main(int argc, char** argv) {
	int modalita_gioco;
	string player1;
	string player2;
	//menu di scelta
	cout<<"Seleziona la modalita' di gioco"<<endl;
	cout<<"1: 1 Giocatore vs Computer"<<endl;
	cout<<"2: 2 Giocatori"<<endl;
	cout<<"3: Computer vs Computer"<<endl;
	cin>>modalita_gioco;
	switch(modalita_gioco){
		case 1://giocatore vs computer
			do{
				cout<<endl<<"Inserisci il nome del giocatore (diverso da 'coumputer')"<<endl;
				cin>>player1;
			}while(player1=="computer");
			new_partita(player1, "computer");
			break;
		case 2://giocatore vs giocatore
			do{
				cout<<endl<<"Inserisci il nome del giocatore 1 (diverso da 'coumputer')"<<endl;
				cin>>player1;
			}while(player1=="computer");
			do{
				cout<<endl<<"Inserisci il nome del giocatore 2 (diverso da 'coumputer')"<<endl;
				cin>>player2;
			}while(player2=="computer");
			new_partita(player1, player2);
			break;
		case 3://computer vs computer
			new_partita("computer", "computer");
			break;
		default: 
			cout<<"error"<<endl;	
	}
	return 0;
}
