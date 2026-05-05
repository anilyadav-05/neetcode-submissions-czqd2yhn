class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];

        for(int i =1; i<prices.size(); i++){
           int x = prices[i] - buy ; 
            if (x <0){
                buy = prices[i];
            } else{ 
                profit = max(profit, x);
            }   

               }

        return profit;
    }
};
