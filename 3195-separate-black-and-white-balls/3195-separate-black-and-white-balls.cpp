class Solution {
public:
    long long minimumSteps(string s) {
        int whitePos = 0;
        long long swaps = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                // Calculate the number of swaps needed to move it to the leftmost available position
                swaps += i - whitePos;
                // Move the next available position for a white ball one step to the right
                whitePos++;
            }
        }
        return swaps;
    }
};