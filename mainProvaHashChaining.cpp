#include "dizionario.hpp"

int main(){

	Dizionario diz;

	diz.inserisci(10, 1);
	diz.inserisci(66, 2);
	diz.inserisci(71, 3);
	diz.inserisci(157, 4);

	diz.cancella( diz.cerca(10) );

	PElem i = diz.cerca(157) ; 

	diz.inserisci(31, 5);
}
