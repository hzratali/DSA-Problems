class Solution {
    public int buyChoco(int[] prices, int money) {
        int f = Integer.MAX_VALUE, s = Integer.MAX_VALUE;
        for(int x : prices){
            if(x < f){
                s = f;
                f = x;
            }
            else s = Math.min(s, x);
        }
        return s+f<=money ? money-f-s : money;
    }
}