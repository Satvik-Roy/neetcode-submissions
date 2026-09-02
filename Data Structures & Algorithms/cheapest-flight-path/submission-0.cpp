class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        
        for (int i = 0; i < k + 1; i++) {
            vector<int> tmpPrices = prices;
            
            for (auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                
                if (prices[from] != INT_MAX) {
                    if (prices[from] + price < tmpPrices[to]) {
                        tmpPrices[to] = prices[from] + price;
                    }
                }
            }
            
            prices = tmpPrices;
        }
        
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};