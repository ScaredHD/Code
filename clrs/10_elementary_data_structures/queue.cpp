#include <cstddef>
#include <iostream>

template <typename T = int, size_t N = 100>
class Queue {
  public:
    Queue() = default;

    bool empty() const { return size == 0; }

    T peekHead() const { return arr[head]; }
    T peekTail() const { return arr[tail]; }

    void enqueue(T x) {
        if (size == N) std::cerr << "queue overflow\n";
        ++size;
        arr[tail] = x;
        tail = (tail + 1) % N;
    }

    void dequeue() {
        if (size == 0) std::cerr << "queue underflow\n";
        --size;
        head = (head + 1) % N;
    }

    size_t head{};
    size_t tail{};
    size_t size{};

    T arr[N];
};

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Queue<T, N>& q) {
    for (size_t i = q.head; i != q.tail; i = (i + 1) % N) {
        std::cout << q.arr[i] << (i < q.tail - 1 ? "," : "");
    }
    return os;
}

int main() {
    using std::cout;

    Queue q;
    cout << "q: " << q << "\n";
    q.enqueue(1);
    cout << "q: " << q << "\n";
    q.enqueue(3);
    cout << "q: " << q << "\n";
    q.enqueue(5);
    cout << "q: " << q << "\n";
    q.enqueue(42);
    cout << "q: " << q << "\n";
    q.dequeue();
    cout << "q: " << q << "\n";
    q.dequeue();
    cout << "q: " << q << "\n";
    q.dequeue();
    cout << "q: " << q << "\n";
}