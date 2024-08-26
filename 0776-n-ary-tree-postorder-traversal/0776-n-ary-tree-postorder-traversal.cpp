/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        f(root, ans);
        return ans;
    }
    void f(Node *currNode, vector<int> &ans){
        if(!currNode) return;
        for(Node *child : currNode->children) f(child, ans);
        ans.push_back(currNode->val);
    }
};