class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(start>0 || goal>0){
            //Increment count if the current bit differ
            if((start&1) != (goal&1)) cnt++;
            //shift both number to the right to check the next bits
            start >>= 1;
            goal >>= 1;
        }
        return cnt;
    }
};