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
    vector<int> values;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        sort(values.begin(), values.end());
        int ans = INT_MAX;
        for(int i=1; i<values.size(); i++){
            ans = min(ans, values[i] - values[i-1]);
        }
        return ans;
    }
    void dfs(TreeNode *node){
        if(node == NULL) return;
        values.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};