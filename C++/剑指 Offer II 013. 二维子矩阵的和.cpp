/*
* 题目理解起来相对困难， 单次查询是 O(dx * dy), 但是可能会查询 N 次， 总的时间是  O(N * dx * dy), 如果我们做了缓存， 那么查询 N 次的时间复杂度 是 O(N + x * y)   
* 为了方便， 缓存的结构比 matrix 在 x, y 的维度都多 1， 因此注意越界检查
*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        else{
            buffer = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
            for(int i = 0; i < buffer.size()-1;++i){
                int row_sum = 0;
                for(int j = 0; j < buffer[0].size()-1; ++j){
                    row_sum += matrix[i][j];
                    buffer[i+1][j+1] = buffer[i][j+1] + row_sum;
                }
            }

        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return buffer[row2 + 1][col2 + 1] + buffer[row1][col1] 
               - buffer[row2+1][col1] - buffer[row1][col2+1];
    }
private:
    vector<vector<int>> buffer;
};