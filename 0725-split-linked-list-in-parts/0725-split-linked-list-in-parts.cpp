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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *curr = head;
        while(curr){
            curr = curr->next;
            n++;
        }
        int width = n/k, rem = n%k;
        vector<ListNode*> ans;
        curr = head;
        for(int i=0; i<k; i++){
            ListNode *root = new ListNode(0);
            ListNode *temp = root;
            for(int j=0; j<width+(i<rem ? 1 : 0); j++){
                temp->next = new ListNode(curr->val);
                temp = temp->next;
                if(curr) curr = curr->next;
            }
            ans.push_back(root->next);
        }
        return ans;
    }
};