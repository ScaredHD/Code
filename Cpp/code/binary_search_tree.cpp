#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool find(TreeNode* root, int target) {
    if (root->val == target) return true;
    if (target < root->val && root->left) { return find(root->left, target); }
    if (target > root->val && root->right) { return find(root->right, target); }
    return false;
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) { return root = new TreeNode(val); }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* remove(TreeNode* root, int val) {
    if (root == nullptr)
        return nullptr;
    else if (val < root->val) {
        root->left = remove(root->left, val);
        return root;
    } else if (val > root->val) {
        root->right = remove(root->right, val);
        return root;
    }

    if (root->left == nullptr) {
        TreeNode* p = root->right;
        delete root;
        return p;
    }

    if (root->left->right == nullptr) {
        TreeNode* p = root->left;
        p->right = root->right;
        delete root;
        return p;
    }

    TreeNode* p;
    for (p = root->left; p->right->right; p = p->right) {}
    TreeNode* r = p->right;
    p->right = r->left;
    r->left = root->left;
    r->right = root->right;
    delete root;
    return r;
}

int main() {

}