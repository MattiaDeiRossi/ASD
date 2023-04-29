#include "dizionario.hpp"
#include <vector>
#include <iostream>

// n = numero di chiavi inserite nella tabella
// m = numero di entry disponibili
// α = n/m

constexpr int hashsize = 8;

using namespace std;

struct Elem
{
  int key;
  int info;
  PElem head;
  PElem tail;
  Elem(int k, int val) : key(k), info(val), head(nullptr), tail(nullptr) {}
};

struct Dizionario::Impl
{
  vector<PElem> content;
  int numchiavi;
};

int funHash(int val)
{
  return val % hashsize;
}

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*post: costruisce un dizionario vuoto */
Dizionario::Dizionario()
{
  pimpl = new Impl;
  pimpl->content.resize(hashsize);
  pimpl->numchiavi = 0;
}

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ(n)
/*post: rimuove il dizionario*/
Dizionario::~Dizionario()
{
  for (auto it : pimpl->content)
  {
    if (it)
      cancella(it);
  }

  delete pimpl;
}

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ( 1+α )
/*pre: k non e' presente nel dizionario*/
/*post: associa il valore val alla chiave k nel dizionario*/
void Dizionario::inserisci(int k, int val)
{
  int index = funHash(k);
  PElem el = new Elem(k, val);

  PElem& aux = pimpl->content.at(index);
  if (aux){
    PElem temp = aux;
    while (temp->tail != nullptr){
      temp = temp->tail;
    }
    el->head = temp;
    temp->tail = el;
  }
  else{
    aux = el;
  }

  pimpl->numchiavi++;
}

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*pre: l'elemento x e' contenuto nel dizionario*/
/*post: rimuove l'elemento x dal dizionario */
void Dizionario::cancella(PElem x)
{
  int index = funHash(x->key);
  if(x->head == nullptr && x->tail == nullptr) // ho un solo elemento
    pimpl->content.at( index) = nullptr;
  
  // sposta puntatori
  PElem& el = x;
  if(el->tail)
    el->tail->head = x->head;
  if(el->head)
    el->head->tail = x->tail;
  else
    pimpl->content.at(index) = x->tail; // sistema il puntatore del vector

  delete x;
  pimpl->numchiavi--;
}

// caso pessimo T(n) = θ(n)
// caso medio T(n) = θ( 1+α )
/*post: restituisce un elemento con chiave k se esiste, nullptr altrimenti */
PElem Dizionario::cerca(int k)
{
  int index = funHash(k);
  PElem aux = pimpl->content.at(index);


  while (aux != nullptr)
  {
    if (aux->key == k)
      return aux;
    aux = aux->tail;
  }

  return nullptr;
}

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*post: restituisce il numero di chiavi nel dizionario*/
int Dizionario::numChiavi()
{
  return pimpl->numchiavi;
}

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce la chiave di x*/
int Dizionario::leggiChiave(PElem x)
{
  return x->key;
}

// caso pessimo T(n) = θ(1)
// caso medio T(n) = θ(1)
/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce il valore di x*/
int Dizionario::leggiInfo(PElem x)
{
  return x->info;
}

// caso pessimo T(n) = θ(n*n)
// caso medio T(n) = θ(n)
/*post: stampa il contenuto del dizionario */
void Dizionario::stampa()
{
  for (auto it : pimpl->content)
  {
    while (it != nullptr)
    {
      //TODO: rimuovi hash 
      cout << "key: " << it->key << /*", hash: "<< funHash(it->key)<<*/ ", info: " << it->info << endl;
      it = it->tail;
    }
  }
}
