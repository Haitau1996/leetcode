/*
* 需要特别注意,push_back 之后要 return 
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {        
        helper(1,k,n);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> selected{};
    void helper(int index, int k, int n){
        if(k >(selected.size() + (n-index+1))) return;
        if(selected.size() == k){
            result.push_back(selected);
            return;
        }
        selected.push_back(index);
        helper(index+1,k,n);
        selected.pop_back();
        helper(index+1, k, n);        
    }
};