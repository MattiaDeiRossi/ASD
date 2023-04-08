#include "../implHashIndApertoDaComp.cpp"
#include <iostream>

int main()
{
    Dizionario diz;
    
	std::cout<< "inserimento " <<std::endl;
    diz.inserisci(10, 1);
    diz.inserisci(66, 2);
    diz.inserisci(71, 3);
    diz.inserisci(157, 4);
    diz.stampa();

	std::cout<<std::endl;
	std::cout<< "cancellazione " <<std::endl;
    diz.cancella( diz.cerca(10));
    diz.stampa();
	
    std::cout<<std::endl;
	std::cout<< "ricerca " <<std::endl;
    auto i = diz.cerca(157);
    std::cout<<"[key: "<< diz.leggiChiave(i) <<", info: "<<diz.leggiInfo(i) <<"]" <<std::endl;
    
    std::cout<<std::endl;
	std::cout<< "inserimento " <<std::endl;
    diz.inserisci(31, 5);
    diz.stampa();
}
