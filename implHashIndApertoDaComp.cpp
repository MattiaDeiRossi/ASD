#include "dizionario.hpp"
#include <vector>
#include <iostream>

constexpr int hashsize = 8;
constexpr int hashaux = 5;

using namespace std;

struct Elem{
    int key;
    int info;
    ...
};

/* DEL e' un elemento fittizio che rappresenta un elemento cancellato */
struct Dizionario::Impl{
  vector<PElem> content;
  int numchiavi;
  PElem DEL;
};

int funHash(int val, int i){
  return (val%hashsize + i*(1+2*(val%hashaux)))%hashsize;
}

/*post: costruisce un dizionario vuoto */
Dizionario::Dizionario(){
  ...
}    

/*post: rimuove il dizionario */
Dizionario::~Dizionario(){
  ...
}    

/*pre: k non e' presente nel dizionario*/
/*post: associa il valore val alla chiave k nel dizionario*/
void Dizionario::inserisci(int k, int val){
  ...
}   


/*pre: l'elemento x e' contenuto nel dizionario*/
/*post: rimuove l'elemento x dal dizionario */
void Dizionario::cancella(PElem x){
  ...
 }    

/*post: restituisce un elemento con chiave k se esiste, nullptr altrimenti */
PElem Dizionario::cerca(int k){
  ...
 }   

/*post: restituisce il numero di chiavi nel dizionario*/
int Dizionario::numChiavi(){
  ...
 }    


/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce la chiave di x*/
int Dizionario::leggiChiave(PElem x){
  ...
}

/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce il valore di x*/
int Dizionario::leggiInfo(PElem x){
    ...
}

/*post: stampa il contenuto del dizionario */
void Dizionario::stampa(){
  ...
}    



