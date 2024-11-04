class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1;
        for(int i=1; i<word.size(); i++){
            if(word[i] == word[i-1]){
                cnt++;
                if(cnt == 10){
                    comp += "9" + string(1, word[i-1]);
                    cnt = 1;
                }
            }
            else{
                comp += to_string(cnt) + word[i-1];
                cnt = 1;
            }
        }
        comp += to_string(cnt)+word[word.size()-1];
        return comp;
    }
};