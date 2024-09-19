class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if(expression.size() == 0) return ans;
        if(expression.size() == 1){
            ans.push_back(stoi(expression));
            return ans;
        }
        if(expression.size()==2 && isdigit(expression[0])){
            ans.push_back(stoi(expression));
            return ans;
        }
        for(int i=0; i<expression.size(); i++){
            char currChar = expression[i];
            if(isdigit(currChar)) continue;
            vector<int> leftAns = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightAns = diffWaysToCompute(expression.substr(i+1));
            for(int leftValue :leftAns){
                for(int rightValue : rightAns){
                    int computeAns = 0;
                    switch(currChar){
                        case '+':
                            computeAns = leftValue+rightValue;
                            break;
                        case '-':
                            computeAns = leftValue - rightValue;
                            break;
                        case '*':
                            computeAns = leftValue * rightValue;
                            break;
                    }
                    ans.push_back(computeAns);
                }
            }
        }
        return ans;
    }
};