/*
执行用时：1592 ms, 在所有 C++ 提交中击败了8.68% 的用户
内存消耗：22.1 MB, 在所有 C++ 提交中击败了17.81% 的用户
*/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
private:
    bool helper(vector<int>& preorder, int low, int high);

};
bool Solution::helper(vector<int>& preorder, int low, int high){
    if(low >= high)
        return true;
    int index = low;
    int root = preorder[low];
    while(index  < high){
        if(preorder[index+1]< root)
            ++index;
        else break;
    }
    int index2 = index;
    while(index2 < high){
        if(preorder[index2 +1] < root)
            return false;
        else  ++index2;
    }
    return helper(preorder,low+1, index) && helper(preorder,index + 1,high);
}