/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n <= 2) return n;
    let step1 = 2, step2 = 1, ans = 0;
    for(let i=2; i<n; i++){
        ans = step1 + step2;
        step2 = step1;
        step1 = ans;
    }
    return ans;
};