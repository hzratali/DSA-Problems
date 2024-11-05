class Solution {
public:
    int minChanges(string s) {
        char currChar = s[0];
        int consecutiveCount = 0, mnChangesRequired = 0;
        // Iterate through each character in the string
        for(int i=0; i<s.size(); i++){
            // If current character matches the previous sequence
            if(s[i] == currChar){
                consecutiveCount++;
                continue;
            }
            // If we have even count of characters, start new sequence
            if(consecutiveCount%2 == 0) consecutiveCount = 1;
            // If odd count, we need to change current character
            // to match previous sequence
            else{
                consecutiveCount = 0;
                mnChangesRequired++;
            }
            // Update current character for next iteration
            currChar = s[i];
        }
        return mnChangesRequired;
    }
};