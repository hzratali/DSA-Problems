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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);
        return root;
    }
    void dfs(TreeNode *lChild, TreeNode *rChild, int level){
        if(lChild==NULL || rChild==NULL) return;
        if(level%2 == 0){
            int tmp = lChild->val;
            lChild->val = rChild->val;
            rChild->val = tmp;
        }
        dfs(lChild->left, rChild->right, level+1);
        dfs(lChild->right, rChild->left, level+1);
    }
};