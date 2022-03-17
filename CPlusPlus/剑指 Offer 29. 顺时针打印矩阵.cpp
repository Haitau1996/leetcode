/*
一定要注意 size 为 0 的情况
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start_m = 0; 
        int start_n = 0;
        if(matrix.size() != 0 && matrix[0].size() != 0){
            int end_m = matrix.size()-1;
            int end_n = matrix[0].size()-1;
            while(start_m <= end_m && start_n <=end_n){
                print_row(matrix,start_m, start_n, end_n);
                print_col(matrix,start_m+1, end_m, end_n);
                if(end_m > start_m) revprint_row(matrix,end_m, end_n-1, start_m);
                if(end_n > start_n) revprint_col(matrix,end_m-1, start_m+1, start_n);
                ++start_m;
                ++start_n;
                --end_m;
                --end_n;
            }
        }
        return result;
    }
private:
    vector<int> result{};
    void print_row(const vector<vector<int>>& matrix,const int NUM, int start_n, int end_n){
        for(int i = start_n; i <= end_n; ++i){
            result.push_back(matrix[NUM][i]);
        }
    }
    void print_col(const vector<vector<int>>& matrix, int start, int end, const int NUM){
        for(int i = start; i <= end; ++i){
            result.push_back(matrix[i][NUM]);
        }
    }
    void revprint_row(const vector<vector<int>>& matrix, const int NUM, int revstart, int revend){
        for(int i = revstart; i >= revend; --i){
            result.push_back(matrix[NUM][i]);
        }
    }
    void revprint_col(const vector<vector<int>>& matrix, int revstart, int revend, const int NUM){
        for(int i = revstart; i >= revend; --i){
            result.push_back(matrix[i][NUM]);
        }
    }
};