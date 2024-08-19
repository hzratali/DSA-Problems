class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        return 1 + f(1, 1, n); //First step is always copy all operation
    }
    int f(int currLen, int pasteLen, int n){
        if(currLen == n) return 0; // base case: reached n A's, dont need more operations
        if(currLen > n) return 1000; // base case: exceeded n A's not a valid sequence, so return max value
        // copy all + paste
        int op1 = 2 + f(currLen*2, currLen, n);
        // Paste
        int op2 = 1 + f(currLen+pasteLen, pasteLen, n);
        return min(op1, op2);
    }
};