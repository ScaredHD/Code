#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Mono {
    double coeff;   // coeffecient of monomial
    size_t exp;     // exponent of monomial
    Mono* next = nullptr;   // ptr to next monomial
};

class Poly {
public:
    Poly() = default;

    Mono* prev(Mono* p);
    void add(double coeff_, size_t exp_);   // add a monomial to the polynomial
    void add(Mono* p);
    void remove(size_t exp);    // remove monomial(term) of which exponent == exp
    void remove(Mono* p);
    void rearr();   // rearrange the order of monomial, from higher degree to lower
    friend std::ostream& operator<<(std::ostream& os, Poly p);

    Mono* head = new Mono();    // head ptr

private:
    Mono* tail = head;  // tail ptr
};

void Poly::rearr()
{
    cout << "calling rearr()" << endl;
}

inline
void Poly::add(double coeff_, size_t exp_)
{
    tail->coeff = coeff_;
    tail->exp = exp_;
    tail->next = new Mono();
    tail = tail->next;
    rearr();
}

inline
void Poly::add(Mono* p)
{
    tail->coeff = p->coeff;
    tail->exp = p->exp;
    tail->next = new Mono();
    tail = tail->next;
    rearr();
}

inline
void Poly::remove(size_t exp)
{
    if (head->exp == exp)
    {
        Mono* headd = head;
        head = head->next;
        delete headd;
        return;
    }

    for (Mono* p = head; p != tail; p = p->next)
    {
        
        if (p->next->exp == exp)
        {
            Mono* pd = p -> next;
            p->next = p->next->next;
            delete pd;
            return;
        }
    }
}

inline
void Poly::remove(Mono* ptr)
{
    if (ptr == head)
    {
        Mono* headd = head;
        head = head->next;
        delete headd;
        return;
    }

    for (Mono* p = head; p != tail; p = p->next)
    {
        
        if (p->next == ptr)
        {
            Mono* pd = p -> next;
            p->next = p->next->next;
            delete pd;
            return;
        }
    }
}


Poly operator+(Poly lhs, Poly rhs);
std::ostream& operator<<(std::ostream& os, Poly p);

int main()
{
    Poly p;
    p.add(3, 5);
    p.add(2, 4);
    p.add(5, 1);
    p.remove(4);
    cout << p << endl;

    Poly p2;
    p2.add(1, 5);
    p2.add(2, 2);
    p2.add(5, 1);
    cout << p2 << endl;

    cout << p + p2;

    system("pause");
    return 0;
}

Poly operator+(Poly lhs, Poly rhs)
{
    Poly ret;

    while (lhs.head->next && rhs.head->next) // both pointer of lhs and rhs are not nullptr
    {
        if (lhs.head->exp > rhs.head->exp)
        {
            ret.add(lhs.head);
            lhs.remove(lhs.head);
        }
        else if (lhs.head->exp < rhs.head->exp)
        {
            ret.add(rhs.head);
            rhs.remove(rhs.head);
        }
        else
        {
            ret.add(lhs.head->coeff + rhs.head->coeff, lhs.head->exp);
            lhs.remove(lhs.head);
            rhs.remove(rhs.head);
        }
    }

    while (!(lhs.head->next) && rhs.head->next)
    {
        ret.add(rhs.head);
        ret.remove(rhs.head);
    }

    while (lhs.head->next && !(rhs.head->next))
    {
        ret.add(lhs.head);
        ret.remove(lhs.head);
    }

    return ret;
}

std::ostream& operator<<(std::ostream& os, Poly p)
{
    for (Mono* ptr = p.head; ptr != p.tail; ptr = ptr->next)
    {
        if (ptr->exp == 1)
        {
            os << ptr->coeff << "x" << " "; 
        }
        else if (ptr -> exp == 0)
        {
            os << ptr->coeff << " ";
        }
        else
        {
        os << ptr->coeff << "x" << ptr->exp << " "; 
        }
    }
    return os;
}