#include <iostream>
#include <vector>
using std::cin; 
using std::cout;
using std::endl;

template <typename T>
class Node {
public:
    Node() = default;
    ~Node();
    Node(T data, Node<T>* left = nullptr, Node<T>* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    Node<T>* left = nullptr;
    T data;
    Node<T>* right = nullptr;
};

template <typename T>
Node<T>::~Node()
{
    delete left;
    delete right;

}

template <typename T>
class BinTree {
public:
    bool isEmpty() const { return (root == nullptr) ? true : false; }

    bool addL(T data, Node<T>* p = nullptr);
    bool addR(T data, Node<T>* p = nullptr);
    bool delL(Node<T>* p);
    bool delR(Node<T>* p);

    void printNode(Node<T>* p) const;
    void prePrint(Node<T>* root) const;

    Node<T>* root = nullptr;
private:
};


int main()
{
    BinTree<int> bt;

    cout << bt.addL(5) << endl;
    cout << bt.addR(42, bt.root) << endl;
    cout << bt.addL(10, bt.root) << endl;
    cout << bt.addL(20, bt.root->left) << endl;
    cout << bt.addR(30, bt.root->left) << endl;

    bt.prePrint(bt.root);

    return 0;
}

template <typename T>
bool BinTree<T>::addL(T data, Node<T>* p)
{
    // if p == nullptr, add root
    if (p == nullptr)
    {
        root = new Node<T>(data);
        return true;
    }
    else if (p->left)
    {
        return false;
    }
    else
    {
        p->left = new Node<T>(data);
        return true;
    }
}

template <typename T>
bool BinTree<T>::addR(T data, Node<T>* p)
{
    if (p == nullptr)
    {
        root = new Node<T>(data);
        return true;
    }
    else if (p->right)
    {
        return false;
    }
    else
    {
        p->right = new Node<T>(data);
        return true;
    }
}

template <typename T>
bool BinTree<T>::delL(Node<T>* p)
{
    if (!p || isEmpty()) { return false; }

    delL(p->left);
    delR(p->left);
    delete p->left;
    p->left = nullptr;
    return true;
}

template <typename T>
bool BinTree<T>::delR(Node<T>* p)
{
    if (!p || isEmpty()) { return false; }

    delL(p->right);
    delR(p->right);
    delete p->right;
    p->right = nullptr;
    return true;
}

template <typename T>
void BinTree<T>::printNode(Node<T>* p) const
{
    cout << p->left << "\t" << p->data << "\t" << p->right << endl;
}

template <typename T>
void BinTree<T>::prePrint(Node<T>* root) const
{
    // print root
    printNode(root);


    // print left sub-tree
    if (root->left)
    {
        Node<T>* r = root->left;
        prePrint(r);
    }

    // print right sub-tree
    if (root->right)
    {
        Node<T>* r = root->right;
        prePrint(r);
    }
}





