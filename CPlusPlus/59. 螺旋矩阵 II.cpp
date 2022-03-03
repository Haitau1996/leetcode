class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        result = vector<vector<int>>(n,vector<int>(n,0));
        print_core(0,n-1);
        return result;
    }
private:
    int current{1};
    vector<vector<int>> result;
    void print_row(int start, int end){
        for(int i = start; i <= end; ++i){
            result[start][i] = current;
            ++current;
        }
    }
    void print_col(int no, int start, int end){
        for(int i = start; i <= end; ++i){
            result[i][no] = current;
            ++current;
        }
    }
    void rev_print_row(int no,int start, int end){
        for(int i = end; i>= start; --i){
            result[no][i] = current;
            ++current;
        }
    }
    void rev_print_col(int no, int start, int end){
        for(int i = end; i >= start; --i){
            result[i][no] = current;
            ++current;
        }
    }
    void print_core(int start, int end){
        if(start > end) return;
        print_row(start,end);
        if(end > start) {
            print_col(end, start+1, end);
            rev_print_row(end, start, end-1);
        }
        if(end > start+1) rev_print_col(start, start+1, end-1);
        print_core(start+1, end-1);
    }
};