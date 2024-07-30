class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), mnDel = 0;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                mnDel++;
            }
            else st.push(s[i]);
        }
        return mnDel;
    }
};