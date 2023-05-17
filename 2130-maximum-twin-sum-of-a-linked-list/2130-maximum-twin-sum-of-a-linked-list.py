# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        curr = head
        v = []
        while(curr != None):
            v.append(curr.val)
            curr = curr.next
        l, r, ans = 0, len(v)-1, 0
        while(l < r):
            ans = max(ans, v[l]+v[r])
            l+=1
            r-=1
        return ans