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
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> currLevelNodes;
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();q.pop();
                currLevelNodes.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2 == 1){
                int l = 0, r = currLevelNodes.size()-1;
                while(l < r){
                    int tmp = currLevelNodes[l]->val;
                    currLevelNodes[l]->val = currLevelNodes[r]->val;
                    currLevelNodes[r]->val = tmp;
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};