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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        dfs(root, mp);
        int mxFreq = 0;
        for(auto x : mp) mxFreq = max(mxFreq, x.second);
        vector<int> ans;
        for(auto x : mp){
            if(x.second == mxFreq) ans.push_back(x.first);
        }
        return ans;
    }
    void dfs(TreeNode *node, unordered_map<int, int> &mp){
        if(node == NULL) return;
        mp[node->val]++;
        dfs(node->left, mp);
        dfs(node->right, mp);
    }
};