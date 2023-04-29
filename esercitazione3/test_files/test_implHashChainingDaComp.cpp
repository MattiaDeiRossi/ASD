#include "../implHashChainingDaComp.cpp"
#include <iostream>
using namespace std;

int main(){

	Dizionario diz;

	cout<< "inserimento " <<endl;
	diz.inserisci(10, 1);
	diz.inserisci(66, 2);
	diz.inserisci(71, 3);
	diz.inserisci(157, 4);
	diz.stampa();

	cout<<endl;
	cout<< "cancellazione " <<endl;
	diz.cancella( diz.cerca(10) );
	diz.stampa();
	cout<<endl;

	cout<< "cancellazione " <<endl;
	diz.cancella( diz.cerca(66) );
	diz.stampa();
	cout<<endl;

	cout<< "ricerca " <<endl;
	PElem i = diz.cerca(157) ; 
    cout<<"[key: "<< diz.leggiChiave(i) <<", info: "<<diz.leggiInfo(i) <<"]" <<endl;

	cout<<endl;
	cout<< "inserimento " <<endl;
	diz.inserisci(31, 5);
	diz.stampa();
}
