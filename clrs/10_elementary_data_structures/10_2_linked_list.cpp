template <typename T>
struct Node {
    T key;
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