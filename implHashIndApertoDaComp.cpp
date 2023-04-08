#include "dizionario.hpp"
#include <vector>
#include <iostream>

// n = numero di chiavi inserite nella tabella
// m = numero di entry disponibili
// α = n/m

constexpr int hashsize = 8;
constexpr int hashaux = 5;

using namespace std;

struct Elem{
    int key;
    int info;
    Elem(int k, int val) : key(k), info(val){}
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

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*post: costruisce un dizionario vuoto */
Dizionario::Dizionario(){
  pimpl = new Impl;
  pimpl->content.resize(hashsize);
  pimpl->numchiavi = 0;
}    

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ(n)
/*post: rimuove il dizionario */
Dizionario::~Dizionario(){
  for (auto it : pimpl->content)
  {
    if (it)
      cancella(it);
  }

  delete pimpl;
}    

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ( 1/(1-α) )
/*pre: k non e' presente nel dizionario*/
/*post: associa il valore val alla chiave k nel dizionario*/
void Dizionario::inserisci(int k, int val){
  int i=0, j=0;
  do{
    j = funHash(k, i);
    i++;
    if(pimpl->content.at(j) == nullptr){
      pimpl->content.at(j) = new Elem(k,val);
      pimpl->numchiavi++;
      return;
    }
  }
  while(i < hashsize);
}   

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ( 1/(1-α) )
/*pre: l'elemento x e' contenuto nel dizionario*/
/*post: rimuove l'elemento x dal dizionario */
void Dizionario::cancella(PElem x){
  int i=0, j=0;
  do{
    j = funHash(x->key, i);
    i++; 
    if(pimpl->content.at(j) == x){
      delete pimpl->content.at(j);
      pimpl->content.at(j) = nullptr;
      return;
    }
  }while(i < hashsize );
}    

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ( 1/(1-α) )
/*post: restituisce un elemento con chiave k se esiste, nullptr altrimenti */
PElem Dizionario::cerca(int k){
  int i=0, j=0;
  do{
    j = funHash(k, i);
    i++; 
    if(pimpl->content.at(j) != nullptr){
      if(pimpl->content.at(j)->key == k)
        return pimpl->content.at(j);
    }
  }while(i < hashsize );

  return nullptr;
 }   

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*post: restituisce il numero di chiavi nel dizionario*/
int Dizionario::numChiavi(){
  return pimpl->numchiavi;
 }    

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce la chiave di x*/
int Dizionario::leggiChiave(PElem x){
  return x->key;
}

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce il valore di x*/
int Dizionario::leggiInfo(PElem x){
  return x->info;
}

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ(n)
/*post: stampa il contenuto del dizionario */
void Dizionario::stampa(){
  for (const auto& it : pimpl->content)
  {
    if(it)
      cout << "key: " << it->key << ", info: " << it->info << endl;
  }
}    



