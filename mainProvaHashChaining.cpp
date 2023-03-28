#include "dizionario.hpp"

#include <iostream>
using namespace std;

int main(){
	/*eseguite le op richieste per la tab hash a concatenamento.*/
	Dizionario diz;

	cout<< "inserimento " <<endl;
	diz.inserisci(97, 1);
	// diz.inserisci(14, 7);
	diz.inserisci(22, 2);
	diz.inserisci(6, 3);
	diz.inserisci(52, 4);
	diz.stampa();

	cout<<endl;
	cout<< "cancellazione " <<endl;
	diz.cancella( diz.cerca(6) );
	diz.stampa();
	cout<<endl;

	// cout<< "cancellazione " <<endl;
	// diz.cancella( diz.cerca(6) );
	// diz.stampa();
	// cout<<endl;

	cout<< "ricerca " <<endl;
	PElem i = diz.cerca(52) ; 
    cout<<"[key: "<< diz.leggiChiave(i) <<", val: "<<diz.leggiInfo(i) <<"]" <<endl;

	cout<<endl;
	cout<< "inserimento " <<endl;
	diz.inserisci(84, 5);
	diz.stampa();
}
