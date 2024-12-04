class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Ind = 0, len1 = str1.size(), len2 = str2.size();
        for(int str1Ind=0; str1Ind<len1 && str2Ind<len2; str1Ind++){
            if(str1[str1Ind] == str2[str2Ind] || (str1[str1Ind]+1 == str2[str2Ind]) || (str1[str1Ind]-25 == str2[str2Ind])){
                str2Ind++;
            }
        }
        return str2Ind == len2;
    }
};