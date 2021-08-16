#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct SegTree {
    vector<int> v;
    vector<int> tree;
    vector<int> mark;
    void init(const vector<int>& v_) {
        v = v_;
        tree = vector<int>(4 * v.size(), 0);
        mark = tree;
    }
    void build(int i, int j, int nodeIdx);
    int sum(int i, int j, int ci, int cj, int nodeIdx);
    void update(int i, int j, int d, int ci, int cj, int nodeIdx);
    void pushdown(int i, int j, int nodeIdx);
    int left(const int& idx) { return 2 * idx + 1; }
    int right(const int& idx) { return 2 * idx + 2; }
};

void SegTree::build(int i, int j, int nodeIdx) {
    if (i == j) {
        tree[nodeIdx] = v[i];
        return;
    }
    auto mid = i + (j - i) / 2;
    build(i, mid, left(nodeIdx));
    build(mid + 1, j, right(nodeIdx));
    tree[nodeIdx] = tree[left(nodeIdx)] + tree[right(nodeIdx)];
}

void SegTree::update(int i, int j, int d, int ci, int cj, int nodeIdx) {
    if (ci > j || cj < i) return;
    if (ci >= i && cj <= j) {
        tree[nodeIdx] += (cj - ci + 1) * d;
        mark[nodeIdx] += d;
    } else {
        pushdown(ci, cj, nodeIdx);
        auto mid = ci + (cj - ci) / 2;
        update(i, j, d, ci, mid, left(nodeIdx));
        update(i, j, d, mid + 1, cj, right(nodeIdx));
        tree[nodeIdx] = tree[left(nodeIdx)] + tree[right(nodeIdx)];
    }
}

int SegTree::sum(int i, int j, int ci, int cj, int nodeIdx) {
    if (ci > j || cj < i) return 0;
    if (ci >= i && cj <= j) {
        return tree[nodeIdx];
    } else {
        pushdown(ci, cj, nodeIdx);
        auto mid = ci + (cj - ci) / 2;
        return sum(i, j, ci, mid, left(nodeIdx))
             + sum(i, j, mid + 1, cj, right(nodeIdx));
    }
}

void SegTree::pushdown(int i, int j, int nodeIdx) {
    auto mid = i + (j - i) / 2;
    mark[left(nodeIdx)] += mark[nodeIdx];
    mark[right(nodeIdx)] += mark[nodeIdx];
    tree[left(nodeIdx)] += (mid - i + 1) * mark[nodeIdx];
    tree[right(nodeIdx)] += (j - mid) * mark[nodeIdx];
    mark[nodeIdx] = 0;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    SegTree st;
    st.init(v);
    auto len = v.size();
    st.build(0, len - 1, 0);
    cout << "QUERY:\n";
    for (int i = 0; i < len; ++i)
        for (int j = i; j < len; ++j)
            cout << "sum[" << i << ", " << j << "] = " << st.sum(i, j, 0, len - 1, 0) << "\n";
    cout <<  "UPDATE:\n";
    st.update(2, 3, 2, 0, len - 1, 0);
    // 1 2 5 6 5
    return 0;
}