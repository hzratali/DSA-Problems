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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size(), sum = 0;
            for(int i=0; i<n; i++){
                TreeNode *node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelSum.push_back(sum);
        }
        q.push(root);
        int levelIndex = 1;
        root->val = 0;
        while(!q.empty()){
            int levelSize = q.size(), siblingSum = 0;
            for(int i=0; i<levelSize; i++){
                TreeNode *node = q.front(); q.pop();
                siblingSum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if(node->left){
                    node->left->val = levelSum[levelIndex] - siblingSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = levelSum[levelIndex] - siblingSum;
                    q.push(node->right);
                }
            }
            levelIndex++;
        }
        return root;
    }
};