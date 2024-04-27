//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(head==NULL || head->next==NULL) return head;
        Node *mid = getMid(head);
        Node *l1 = sortDoubly(head);
        Node *l2 = sortDoubly(mid);
        return merge(l1, l2);
    }
    struct Node* getMid(Node* head){
        Node *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *mid = slow->next;
        slow->next = NULL;
        mid->prev = NULL;
        return mid;
    }
    struct Node* merge(Node *l1, Node *l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        Node *dummyHead = new Node(-1);
        Node *tail = dummyHead;
        while(l1 != NULL && l2 != NULL){
            if(l1->data < l2->data){
                l1->prev = tail;
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                l2->prev = tail;
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1 != NULL){
            l1->prev= tail;
            tail->next = l1;
        }
        if(l2 != NULL){
            l2->prev = tail;
            tail->next = l2;
        }
        Node *head = dummyHead->next;
        head->prev = NULL;
        return head;
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends