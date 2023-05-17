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
    int pairSum(ListNode* head) {
        ListNode *curr = head;
        vector<int> v;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        int l = 0, r = v.size()-1, ans = 0;
        while(l < r){
            ans = max(ans, v[l]+v[r]);
            l++;
            r--;
        }
        return ans;
    }
};