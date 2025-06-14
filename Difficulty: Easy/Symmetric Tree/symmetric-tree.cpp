/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if(!root) return true;
        return f(root->left, root->right);
    }
    bool f(Node *node1, Node *node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        if(node1->data != node2->data) return false;
        return f(node1->left, node2->right) || f(node1->right, node2->left);
    }
};