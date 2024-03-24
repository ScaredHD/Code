#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// TODO: Method 2

class Solution {
  public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        if (copies.count(head) == 0) {
            auto* p = new Node{head->val};
            copies[head] = p;  // Important: assign before recursion
            p->next = copyRandomList(head->next);
            p->random = copyRandomList(head->random);
        }
        return copies[head];
    }

  private:
    // From node to be copyed to node copyed
    std::unordered_map<Node*, Node*> copies;
};