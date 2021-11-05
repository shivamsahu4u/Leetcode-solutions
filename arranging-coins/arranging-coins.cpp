class Solution {
public:
    int arrangeCoins(int n) {
        
        //using maths formula
        return  (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};