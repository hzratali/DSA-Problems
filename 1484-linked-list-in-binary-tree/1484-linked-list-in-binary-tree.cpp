/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        bool ans = dfs(root, head);
        ans |= isSubPath(head, root->left);
        ans |= isSubPath(head, root->right);
        return ans;
    }
    bool dfs(TreeNode *node, ListNode *head){
        if(!head) return true;
        if(!node) return false;
        bool ans = false;
        if(node->val == head->val){
            ans |= dfs(node->left, head->next);
            ans |= dfs(node->right, head->next);
        }
        return ans;
    }
};