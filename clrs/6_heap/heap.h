#include <array>
#include <cstddef>

template <typename T = int, size_t maxSize = 1000>
class MaxHeap {
  public:
    MaxHeap() = default;

    template <typename Iter>
    void load(Iter beg, Iter end);

    void load(std::initializer_list<T> il) { load(il.begin(), il.end()); }

    void maxHeapify(size_t i);
    void buildMaxHeap();

    bool isMaxHeap() const { return isMaxHeap(1); }

  private:
    static size_t parent(size_t i) { return i / 2; }
    static size_t left(size_t i) { return 2 * i; }
    static size_t right(size_t i) { return 2 * i + 1; }

    bool isMaxHeap(size_t i) const;

    // arr[0] left unused
    // arr[1..heapSize] : current heap data
    size_t heapSize{};
    std::array<T, maxSize> arr{};
};

template <typename T, size_t maxSize>
template <typename Iter>
void MaxHeap<T, maxSize>::load(Iter beg, Iter end) {
    heapSize = static_cast<size_t>(end - beg);
    size_t i = 1;
    Iter it = beg;
    while (it != end) arr[i++] = *it++;
}

// T(n) <= T(2n/3) + Theta(1)
// T(n) = O(log n) = O(h)
template <typename T, size_t maxSize>
void MaxHeap<T, maxSize>::maxHeapify(size_t i) {
    auto largest = i;
    auto l = left(i);
    auto r = right(i);
    if (l <= heapSize && arr[l] > arr[largest]) largest = l;
    if (r <= heapSize && arr[r] > arr[largest]) largest = r;

    if (largest == i) return;

    std::swap(arr[i], arr[largest]);
    maxHeapify(largest);
}

// T(n) = Sum[Theta(n) * O(h_i), {i, 1, heapSize / 2}]
// T(n) = O(n)
template <typename T, size_t maxSize>
void MaxHeap<T, maxSize>::buildMaxHeap() {
    for (auto i = heapSize / 2; i > 0; --i) {
        maxHeapify(i);
    }
}
template <typename T, size_t maxSize>
bool MaxHeap<T, maxSize>::isMaxHeap(size_t i) const {
    if (i > heapSize) return true;
    return arr[i] >= arr[left(i)] && arr[i] >= arr[right(i)] && isMaxHeap(left(i)) &&
           isMaxHeap(right(i));
}
