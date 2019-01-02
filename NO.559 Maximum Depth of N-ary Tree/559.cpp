#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->children.empty()) {
            return 1;
        }
        int max_child_depth = 0;
        for (auto child : root->children) {
            max_child_depth = max(maxDepth(child), max_child_depth);
        }
        return max_child_depth + 1;
    }
};

int main() {
    auto n5 = new Node(5, vector<Node*> {});
    auto n6 = new Node(6, vector<Node*> {});
    auto n3 = new Node(3, vector<Node*> { n5, n6 });
    auto n2 = new Node(2, vector<Node*> {});
    auto n4 = new Node(4, vector<Node*> {});
    auto n1 = new Node(1, vector<Node*> { n3, n2, n4 });

    Solution s;
    cout << s.maxDepth(n1);

    cin.get();
    return 0;
}