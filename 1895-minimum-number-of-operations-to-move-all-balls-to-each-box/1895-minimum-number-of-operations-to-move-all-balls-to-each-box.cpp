class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;
        //Single pass: calculate moves from both left and right
        for(int i=0; i<boxes.size(); i++){
            //Left pass
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i]-'0';
            movesToLeft += ballsToLeft;
            //Right pass
            int j = boxes.size()-1-i;
            ans[j] += movesToRight;
            ballsToRight += boxes[j]-'0';
            movesToRight += ballsToRight;
        }
        return ans;
    }
};