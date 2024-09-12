class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        for(string &word : words){
            bool isConsis = true;
            for(int i=0;i<word.size();i++){
                char curr = word[i];
                bool isCharAllowed = false;
                for(int j=0; j<allowed.size(); j++){
                    if(allowed[j] == curr){
                        isCharAllowed = true;
                        break;
                    }
                }
                if(!isCharAllowed){
                    isConsis = false;
                    break;
                }
            }
            if(isConsis) cnt++;
        }
        return cnt;
    }
};