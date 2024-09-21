class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexiNumbers;
        // Start generating numbers from 1 to 9
        for(int i=1; i<=9; i++) genLexiNums(i, n, lexiNumbers);
        return lexiNumbers;
    }
    void genLexiNums(int currNum, int limit, vector<int> &ans){
        if(currNum > limit) return;
        ans.push_back(currNum);
        for(int nxtDigit=0; nxtDigit<=9; nxtDigit++){
            int nxtNum = currNum*10 + nxtDigit;
            //If the next num is within the limit, continue recursion
            if(nxtNum <= limit) genLexiNums(nxtNum, limit, ans);
            else break;
        }
    }
};