#include <iostream>
#include <utility>      // std::pair
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int key;
    Node(int k, Node* sx = nullptr, Node* dx = nullptr)
    : key{k}, left{sx}, right{dx} {}
};

typedef Node* PNode;
// T(n) = Theta(n)
// caso base t=null T(n) = d = theta(1)
// caso ricrosivo t!=null T(n) = T(k) + T(n-k-1) + d
// k = nodi sottoalber sx
// n-k-1 = nodi sottoalbero dx
int fun (PNode t){
    if(t){
        int sottoSx = fun(t->left);
        int sottoDx = fun(t->right);
        if (sottoSx>sottoDx){
            cout<<t->key<<endl;
        }
        return sottoSx+sottoDx+1;
    }
    return 0;
}
void fun2 (PNode t, int& sotto){
    if(t){
        int sottoSx = fun(t->left);
        int sottoDx = fun(t->right);
        if (sottoSx>sottoDx){
            cout<<t->key<<endl;
        }
        sotto += sottoSx+sottoDx+1;
    }
}

void foo3(PNode t){
    int sotto = 0;
    fun2(t, sotto);
}

int main(){
    PNode root = new Node(30);
    root->left = new Node(25);
    root->left->left = new Node(21);
    root->right = new Node(40);
    root->right->left = new Node(35);
    root->right->right = new Node(45);

    fun(root);
    foo3(root);
}