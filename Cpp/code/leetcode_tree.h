// leetcode binary tree tools

#ifndef _LEETCODE_TREE
#define _LEETCODE_TREE
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::string treeNodeToString(TreeNode* root) {
    if (root == nullptr) { return "[]"; }

    std::string output = "";
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += std::to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void trimLeftTrailingSpaces(std::string& input) {
    input.erase(input.begin(),
                std::find_if(input.begin(), input.end(),
                             [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(std::string& input) {
    input.erase(std::find_if(input.rbegin(), input.rend(),
                             [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}

TreeNode* stringToTreeNode(std::string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) { return nullptr; }

    std::string item;
    std::stringstream ss;
    ss.str(input);

    std::getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) { break; }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) { break; }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, std::string prefix = "",
                     bool isLeft = true) {
    if (node == nullptr) {
        std::cout << "Empty tree";
        return;
    }

    if (node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "),
                        false);
    }

    std::cout << prefix + (isLeft ? "└── " : "┌── ") + std::to_string(node->val)
                     + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

#endif