/*
在原地上修改， 节省内存
执行用时：100 ms, 在所有 C++ 提交中击败了73.99% 的用户
内存消耗：91 MB, 在所有 C++ 提交中击败了86.21% 的用户
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int biggest = prices.back();
        int result{};
        for(int i = prices.size() -1; i >=0 ; --i){
            if(prices[i] > biggest) {
                biggest = prices[i];
                prices[i] = 0;
            }
            else{
                prices[i] = biggest - prices[i];
            }
        }
        for(int i = 0 ; i < prices.size(); ++i){
            if(prices[i] > result) result = prices[i];
        }
        return result;
    }
};