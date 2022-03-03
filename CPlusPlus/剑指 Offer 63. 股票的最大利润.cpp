/*
执行用时：4 ms, 在所有 C++ 提交中击败了89.87% 的用户
内存消耗：12.7 MB, 在所有 C++ 提交中击败了9.59% 的用户
* 需要考虑输入的数组为空的情况
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<int> buffer(prices.size(),0);
        buffer[prices.size()-1] = prices[prices.size()-1];
        for(int i = prices.size()-2; i >= 0; --i){
            buffer[i] = (buffer[i+1] > prices[i]) ? buffer[i+1] : prices[i];
        }
        for(int i = 0; i < prices.size(); ++i){
            buffer[i] -= prices[i];
        }
        return *max_element(buffer.begin(), buffer.end());
    }
};