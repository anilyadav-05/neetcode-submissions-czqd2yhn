class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy = prices[0];

        for( int i : prices){
            if (buy >= i){
                buy = i;
            }else{
                ans+= (i-buy);
                buy = i;
            }


        }
        return ans;
    }
};