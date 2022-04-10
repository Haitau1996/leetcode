#include<vector>

using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        vector<int> result;
        while(sum < m + n - 1){
            if(sum%2 == 1){
                int i = max(0, sum-n+1);
                int j = sum - i;
                while(i >=0 && j >=0 && i < m && j < n){
                    result.push_back(mat[i][j]);
                    ++i;
                    --j;
                }
            }
            else{
                int j = max(0, sum-m+1);
                int i = sum - j;
                while(i >= 0 && j>=0 && i < m && j < n){
                    result.push_back(mat[i][j]);
                    ++j;
                    --i;
                }
            }
            ++sum;
        }
        return result;
    }
};
