// 2025/03/01 Saturday 15:41:35
// [简单] LCR.056. 两数之和 IV - 输入二叉搜索树

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool findTarget(TreeNode* root, int k)
  {
    auto* curRoot = root;
    return dfs(root, curRoot, k);
  }

  bool dfs(TreeNode* const root, TreeNode* curRoot, int k)
  {
    if (!curRoot) {
      return false;
    }

    auto* res = findValue(root, k - curRoot->val);
    if (res && res != curRoot) {
      return true;
    }
    if (curRoot->left && dfs(root, curRoot->left, k)) {
      return true;
    }
    if (curRoot->right && dfs(root, curRoot->right, k)) {
      return true;
    }
    return false;
  }

  TreeNode* findValue(TreeNode* root, int val)
  {
    if (!root) {
      return nullptr;
    }
    if (root->val == val) {
      return root;
    }
    if (root->left) {
      if (auto* resLeft = findValue(root->left, val)) {
        return resLeft;
      }
    }
    if (root->right) {
      if (auto* resRight = findValue(root->right, val)) {
        return resRight;
      }
    }
    return nullptr;
  }
};