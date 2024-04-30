//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node *head1 = reverse(trimZero(num1));
        Node *head2 = reverse(trimZero(num2));
        if(head1==NULL && head2==NULL) return new Node(0);
        Node *head = new Node(-1);
        Node *tail = head;
        int carry = 0;
        while(head1!=NULL || head2!=NULL || carry != 0){
            int x = head1==NULL ? 0 : head1->data;
            int y = head2==NULL ? 0 : head2->data;
            int num = x+y+carry;
            carry = num/10;
            tail->next = new Node(num%10);
            tail = tail->next;
            if(head1!=NULL) head1 = head1->next;
            if(head2!=NULL) head2 = head2->next;
        }
        return reverse(head->next);
    }
    static Node* trimZero(Node *head){
        Node *cur = head;
        while(cur != NULL && cur->data == 0){
            cur = cur->next;
        }
        return cur;
    }
    struct Node* reverse(struct Node *head){
        Node *nxt = head, *prev = NULL;
        while(head){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends