#include <cstddef>
#include <vector>

template <typename T>
struct Node {
    T val;
    Node* prev;
    Node* next;
};

template <typename T>
Node<T>* listSearch(Node<T>* head, T val) {
    auto p = head;
    while (p && p->key != val) {
        p = p->next;
    }
    return p;
}

template <typename T>
void listInsert(Node<T>* p, Node<T>* x) {
    x->next = p->next;
    x->prev = p;
    if (p->next) x->next->prev = x;
    p->next = x;
}

template <typename T>
void listDelete(Node<T>* head, Node<T>* x) {
    if (x->prev)
        x->prev->next = x->next;
    else
        head = x->next;

    if (x->next) x->next->prev = x->prev;
}

template <typename Key, typename Value, size_t N = 1000>
class HashMap {
  public:
    HashMap(size_t size) : table(size, nullptr) {}

    void insert(Value x) { listInsert(table[hash(x)], new Node<Value>(x)); }

    Node<Value>* search(Value x) const { return listSearch(table[hash(x)], x); }

    void remove(Node<Value>* x) { listDelete(table[hash(x->val)], x); }

  private:
    size_t hash(Key k) const;

    std::vector<Node<Value>*> table;
};