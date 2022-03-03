/*
注意两个判断条件
* left > 0 时候才能继续 helper
* right > left 时候才合格
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string current{};
        helper(n,n,current);
        return result;
    }
private:
    vector<string> result{};
    void helper(int left, int right, string current){
        if(left == 0 && right == 0){
            result.push_back(current);
            return;
        }
        if(left > 0) helper(left-1,right,current+"(");
        if(right > left)helper(left,right-1,current + ")");
    }
};