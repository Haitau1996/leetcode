/*
思路 1： 前缀和 + 暴力枚举 （O(n^4))
超出时间限制：14 / 45 个通过测试用例
*/
#include<vector>
#include<limits>
#include<initializer_list>

using namespace std;
class BruteForceSolution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int j = 1; j < n; ++j){
            matrix[0][j] += matrix[0][j-1];
        }
        for(int i = 1; i < m; ++i){
            matrix[i][0] += matrix[i-1][0];
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + matrix[i][j];
            }
        }
        int max_sum = numeric_limits<int>::min();
        vector<int> result{};
        for(int a = 0; a < m; ++a){
            for(int b = 0; b < n; ++b){
                for(int c = a; c < m; ++c){
                    for(int d = b; d < n;++d){
                        int A = matrix[c][d];
                        int B = (a == 0 ? 0 : matrix[a-1][d]);
                        int C = (b == 0 ? 0 : matrix[c][b-1]);
                        int D = ((a ==0 || b ==0)? 0 : matrix[a-1][b-1]);
                        if(A+D-B-C > max_sum){
                            max_sum = A+D-B-C;
                            result = vector({a,b,c,d});
                        }
                    }
                }
            }
        }
        return result;
    }
};
/*----------------------------------------------------------------
根据提示写出来了， 我们固定住上下边界，就可以在 O(n) 的时间中计算最大子数组和
而上下边界的选取就是 O(m^2) 的时间复杂度，因此就把它降了一阶
*/
class OptSolution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int j = 1; j < n; ++j){
            matrix[0][j] += matrix[0][j-1];
        }
        for(int i = 1; i < m; ++i){
            matrix[i][0] += matrix[i-1][0];
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + matrix[i][j];
            }
        }
        int max_sum = numeric_limits<int>::min();
        vector<int> result{};
        for(int a = 0; a < m; ++a){
            for(int c = a; c < m; ++c){
                int b = 0;
                int d = 0;
                while(d < n){
                    int A = matrix[c][d];
                    int B = (a == 0 ? 0 : matrix[a-1][d]);
                    int C = (b == 0 ? 0 : matrix[c][b-1]);
                    int D = ((a ==0 || b ==0)? 0 : matrix[a-1][b-1]);
                    int current_aera = A+D-B-C;
                    if( current_aera > max_sum){
                        max_sum = current_aera;
                        result = vector({a,b,c,d});
                    }
                    if(current_aera > 0){ ++d;}
                    else{
                        b = d+1;
                        d = b;
                    }
                }
            }
        }
        return result;
    }
};