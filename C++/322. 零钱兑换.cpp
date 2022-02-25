class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> buffer(amount+1,numeric_limits<int>::max());
        buffer[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(const auto& elem :coins){
                if(i - elem >=0){
                    buffer[i] = min(buffer[i], buffer[i-elem]+1);
                }
            }
        }
        return buffer.back()>=numeric_limits<int>::max()? -1 : buffer.back();
    }
};