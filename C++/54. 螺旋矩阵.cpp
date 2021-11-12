/*
执行用时：
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：
6.5 MB, 在所有 C++ 提交中击败了96.07%的用户
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res{};
        helper(matrix, 0, matrix[0].size()-1, matrix.size()-1,res);
        return res;
    }
    void helper(vector<vector<int>>& matrix, int start, int end_m, int end_n,vector<int>& res);
    void printLine(vector<vector<int>>& matrix, int start, int end_m,vector<int>& res);
    void printRow(vector<vector<int>>& matrix, int start, int end, int rowNum,vector<int>& res);
    void revPrintLine(vector<vector<int>>& matrix, int start, int end, int lineNum,vector<int>& res);
    void revPrintRow(vector<vector<int>>& matrix, int start, int end, int rowNum,vector<int>& res);    
};
void Solution::printLine(vector<vector<int> > &matrix, int start, int end_m,vector<int>& res){
    int temp = start;
    while(temp <= end_m){
        res.push_back(matrix[start][temp]);
        ++temp;
    }
}
void Solution::printRow(vector<vector<int> > &matrix, int start, int end, int rowNum,vector<int>& res){
    while(start <= end){
        res.push_back(matrix[start][rowNum]);
        ++start;
    }
}
void Solution::revPrintLine(vector<vector<int> > &matrix, int start, int end, int lineNum,vector<int>& res){
    while(start >= end){
        res.push_back(matrix[lineNum][start]);
        --start;
    }
}
void Solution::revPrintRow(vector<vector<int> > &matrix, int start, int end, int rowNum,vector<int>& res){
    while(start>=end){
        res.push_back(matrix[start][rowNum]);
        --start;
    }
}
void Solution::helper(vector<vector<int>>& matrix, int start, int end_m, int end_n,vector<int>& res){
    if(start > end_m || start > end_n) return;
    printLine(matrix, start, end_m,res);
    printRow(matrix,start+1, end_n, end_m,res);
    if(end_n > start) revPrintLine(matrix, end_m-1, start,end_n,res);
    if(end_m > start) revPrintRow(matrix,end_n-1, start+1,start,res);
    helper(matrix, start+1, end_m-1, end_n-1,res);
}