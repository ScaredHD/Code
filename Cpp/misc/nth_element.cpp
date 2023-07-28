#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using std::vector;

int partition(vector<int>& v, int first, int last) {
    int i = first;
    for (int j = first; j < last; ++j)
        if (v[j] < v[last]) std::swap(v[j], v[i++]);
    std::swap(v[last], v[i]);
    return i;
}

int partition(vector<int>& v, int first, int last, int pivotIdx) {
    std::swap(v[pivotIdx], v[last]);
    return partition(v, first, last);
}

int median5(vector<int>& v, int first, int last) {
    auto i = first;
    while (i <= last) {
        auto j = i;
        while (j > first && v[j] < v[j - 1]) {
            std::swap(v[j], v[j - 1]);
            --j;
        }
        ++i;
    }
    return first + (last - first) / 2;
}

int select(vector<int>& v, int first, int last, int k);

int medianOfMedians(vector<int>& v, int first, int last) {
    if (last - first < 5) return median5(v, first, last);
    for (int i = first; i <= last; i += 5) {
        auto left = i;
        auto right = std::min(i + 4, last);
        auto mIdx = median5(v, left, right);
        std::swap(v[mIdx], v[first + (i - first) / 5]);
    }
    auto len = last - first + 1;
    auto medianCnt = len / 5 + (len % 5 ? 1 : 0);
    auto mid = (medianCnt + 1) / 2;
    return select(v, first, first + medianCnt - 1, mid);
}

int select(vector<int>& v, int first, int last, int k) {
    if (first == last) return first;
    auto idx = medianOfMedians(v, first, last);
    idx = partition(v, first, last, idx);
    auto i = idx - first + 1;
    if (i == k)
        return idx;
    else if (i < k)
        return select(v, idx + 1, last, k - i);
    else
        return select(v, first, idx - 1, k);
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 100);
    std::uniform_int_distribution<int> indexGen(1, 100);
    vector v(100, 0);
    for (int i = 0; i < 100; ++i) {
        for (auto& i : v) i = dis(gen);
        auto v2 = v;
        auto k = indexGen(gen);
        auto kthElementIdx = select(v, 0, 99, k);
        std::nth_element(v2.begin(), v2.begin() + k - 1, v2.end());
        std::cout << 
            (v[kthElementIdx] == v2[k - 1] ? "true" : "false") 
                << "\n";
    }
    return 0;
}