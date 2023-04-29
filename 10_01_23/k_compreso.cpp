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

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? GREEN"├──" : RED"└──"  );
        std::cout << node->key << std::endl;
        std::cout << RESET;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}
void printBT(const Node* node)
{
    std::cout << GREEN"left: ├──     ";
    std::cout << RED"right: └──"<<std::endl;
    std::cout << RESET<<std::endl;
    printBT("", node, false);    
}

// T(n) = theta(n)
std::pair<bool, int> aux(PNode u, int k){
    if(!u){
        return {true, 0};
    }
    
    auto l = aux(u->left, k);
    auto r = aux(u->right, k);

    int sum = l.second + r.second + u->key;
    bool flag = sum <= k && sum >= -k && l.first && r.first;
    
    return {flag, sum};

}


// T(n) = O(n)
int fun(PNode tree, bool &flag, int k) {
    if (tree && flag) {
        int leftRes = fun(tree -> left, flag, k);
        int rightRes = fun(tree -> right, flag, k);

        int sum = leftRes + rightRes + tree->key;
        flag = flag && (sum >= -k && sum <= k); 
        //std::cout << "sum = "<<sum<<endl;
        return sum;
    }
    else return 0;
}


// T(n) = theta(n)
bool auxd (PNode t, int k, int &sum){
    if(!t){
        return true;
    }
    int leftAcc = 0;
    int rightAcc = 0;
    bool leftRes = auxd(t->left, k, leftAcc);
    bool rightRes = auxd(t->right, k, rightAcc);
    sum += t->key + leftAcc + rightAcc;
    if(sum > k || sum < -k || !leftRes || !rightRes){
        return false;
    }

    return true;
}


bool kCompresoBJ(PNode t, int k){
    bool flag = true; 
    fun(t,flag,k);
    return flag; 
}

bool kCompresoDifre (PNode t, int k){
    int sum = 0;
    return auxd(t,k,sum);
}

bool kCompreso (PNode t, int k){
    auto [res, somma] = aux(t,k);
    return res;
}

pair<int, bool> funPair() {
    return {true, 0};
}

int main(){
    PNode root = new Node(30);
    root->left = new Node(20);
    root->left->left = new Node(12);
    root->left->left->right = new Node(3);
    root->right = new Node(12);
    root->right->right = new Node(9);
    root->right->right->left = new Node(1);
    root->right->right->right = new Node(4);
    root->right->right->right->left = new Node(5);

    printBT(root);
    std::cout<<std::endl;

    std::cout << kCompreso(root, 40) << std::endl;
    std::cout << kCompreso(root, 200) << std::endl;

    std::cout<<std::endl;

    std::cout << kCompresoBJ(root, 40) << std::endl;
    std::cout << kCompresoBJ(root, 200) << std::endl;

    std::cout<<std::endl;   

    std::cout << kCompresoDifre(root, 40) << std::endl;
    std::cout << kCompresoDifre(root, 200) << std::endl;
}