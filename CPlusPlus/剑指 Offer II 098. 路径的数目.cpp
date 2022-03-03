class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> buffer(n,1);
        for(int i = 1; i <m ; ++i){
            for(int j = 1; j < n; ++j){
                buffer[j] += buffer[j-1];
            }
        }
        return buffer.back();
    }
};