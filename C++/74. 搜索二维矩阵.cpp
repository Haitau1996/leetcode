/*
执行用时：4 ms, 在所有 C++ 提交中击败了76.49% 的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了52.16% 的用户
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0] || target> matrix[matrix.size()-1][matrix[0].size()-1]) return false;
        auto line = getLine(matrix, 0, matrix.size()-1, target);
        return inLine(matrix[line],0, matrix[line].size()-1, target);
    }
private:
    int getLine(vector<vector<int>>& matrix, int low, int high, int target){
        if(low >= high) return low;
        int mid = (low + high)/2;
        int mid_beg = matrix[mid][0];
        int mid_end = matrix[mid][matrix[mid].size()-1];
        if(target < mid_beg) return getLine(matrix, low, mid-1, target);
        else if(target > mid_end) return getLine(matrix, mid+1, high, target);
        return mid;
    }
    bool inLine(vector<int>& line, int low, int high, int target){
        if(target < line[low] || target > line[high]) return false;
        if(low >= high){
            if(line[low] == target) return true;
            else return false;
        }
        int mid = (low + high)/2;
        if(line[mid] > target) return inLine(line, low, mid-1,target);
        else if(line[mid] < target) return inLine(line, mid+1, high, target);
        else return true;
    }
};