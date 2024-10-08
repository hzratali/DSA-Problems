class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int unbalanced = 0;
        for(char c : s){
            if(c == '[') st.push(c);
            else{
                if(!st.empty()) st.pop();
                else unbalanced++;
            }
        }
        return (unbalanced+1) / 2;
    }
};