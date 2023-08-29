class Solution {
public:
    int bestClosingTime(string customers) {
        int currPenalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = currPenalty, earliestHour = 0;
        for(int i=0; i<customers.size(); i++){
            char c = customers[i];
            if(c == 'Y') currPenalty--;
            else currPenalty++;
            if(currPenalty < minPenalty){
                minPenalty = currPenalty;
                earliestHour = i+1;
            }
        }
        return earliestHour;
    }
};