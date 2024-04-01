//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> in;
        inorder(root, in);
        return mergeSort(0, in.size() - 1, in);
    }
    int mergeSort(int l, int r, vector<int>&in){
        int cnt = 0;
        if(l < r){
            int m = (l+r)/2;
            cnt += mergeSort(l, m, in);
            cnt += mergeSort(m+1, r, in);
            cnt += merge(l, m, r, in);
        }
        return cnt;
    }
    int merge(int l, int m, int r, vector<int>&v){
        int i=l, j=m+1, k=0, n=r-l+1, cnt=0;
        vector<int> temp(n);
        while(i <= m and j <= r){
            if(v[i] <= v[j]) temp[k++] = v[i++];
            else{
                cnt += m - i + 1;
                temp[k++] = v[j++];
            }
        }
        while(i <= m) temp[k++] = v[i++];
        while(j <= r) temp[k++] = v[j++];
        for(i=l, k=0; k<n; k++, i++) v[i] = temp[k];
        return cnt;
    }
    void inorder(Node *root, vector<int>&in){
        if(root){
            inorder(root->left, in);
            in.push_back(root->data);
            inorder(root->right, in);
        }
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends