class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowOfZeros;
        set<int> culOfZeros;

        for(int i{}; i< matrix.size(); ++i){
            for(int j{}; j<matrix[0].size(); ++j){
                if (matrix[i][j] == 0){
                    rowOfZeros.insert(i);
                    culOfZeros.insert(j);
                }
            }
        }
        for(auto i: rowOfZeros){
            for(int j{};j < matrix[0].size(); ++j)
                matrix[i][j] = 0;
        }
        for(auto j : culOfZeros){
            for(int i{}; i< matrix.size();++i)
                matrix[i][j] =0;
        }
    }
};