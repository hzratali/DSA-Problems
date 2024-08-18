class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumbers;
        uglyNumbers.insert(1);
        long curr = 1;
        for(int i=0; i<n; i++){
            curr = *uglyNumbers.begin();  // get the smallest number from the set
            uglyNumbers.erase(uglyNumbers.begin()); // Remove it from the set
            //Insert the next potential ugly numbers
            uglyNumbers.insert(curr*2);
            uglyNumbers.insert(curr*3);
            uglyNumbers.insert(curr*5);
        }
        return static_cast<int>(curr);   // return the nth ugly number
    }
};