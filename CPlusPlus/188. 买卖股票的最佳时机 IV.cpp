#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() ==0 || k == 0) return 0;
        size_t n = prices.size();
        vector<int> buys(k, -prices[0]);
        vector<int> sells(k, 0);
        for(size_t i = 1; i < n; ++i){
            buys[0] = max(buys[0], -prices[i]);
            sells[0] = max(sells[0], buys[0]+prices[i]);
            for(int j = 1; j < k; ++j){
                buys[j] = max(buys[j], sells[j-1] - prices[i]);
                sells[j] = max(sells[j], buys[j] + prices[i]);
            }
        }
        return *max_element(sells.begin(), sells.end());
    }
};
