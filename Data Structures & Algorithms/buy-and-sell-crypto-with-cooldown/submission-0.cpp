class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int reset = 0;
        
        for (int price : prices) {

            int preHold = hold;
            int preSold = sold;
            int preReset = reset;
            
            hold = max(preHold, preReset - price);
            
            sold = preHold + price;
            
            reset = max(preReset, preSold);
        }
        
        return max(sold, reset);
    }
};