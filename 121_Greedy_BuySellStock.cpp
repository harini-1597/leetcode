int maxProfit(vector<int>& prices) {
        int least_price=INT_MAX, profit_now=0, profit_overall=0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < least_price)
                least_price=prices[i];
            profit_now = prices[i]-least_price;
            if(profit_now > profit_overall)
                profit_overall = profit_now;
        }
        return profit_overall;
    }
