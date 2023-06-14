/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MAX;
    TreeNode *preNode;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* node){
        if(node == NULL) return;
        dfs(node->left);
        if(preNode != NULL) ans = min(ans, node->val - preNode->val);
        preNode = node;
        dfs(node->right);
    }
};