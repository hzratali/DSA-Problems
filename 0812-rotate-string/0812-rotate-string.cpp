class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i=0; i<s.size(); i++){
            rotate(s.begin(), s.begin()+1, s.end());
            if(s == goal) return true;
        }
        return false;
    }
};