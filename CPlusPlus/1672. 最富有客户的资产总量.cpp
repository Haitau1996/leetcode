#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for(size_t i =0 ; i < accounts.size(); ++i){
            int temp = accumulate(accounts[i].begin(), accounts[i].end(),0);
            if( temp > result)
                result = temp; 
        }
        return result;
    }
};
