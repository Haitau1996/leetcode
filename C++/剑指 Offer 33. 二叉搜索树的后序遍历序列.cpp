/*
执行用时：4 ms, 在所有 C++ 提交中击败了48.14% 的用户
内存消耗：6.8 MB, 在所有 C++ 提交中击败了61.44% 的用户
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size()-1);
    }
private:
    bool helper(vector<int>& postorder, int low, int high){
        if(low>= high)
            return true;
        int root = postorder[high];
        int index = 0;
        while(low + index  < high){
            if(postorder[low+index] < root)
                ++index;
            else
                break;
        }
        int index2 = 0;
        while(low + index + index2 < high){
            if(postorder[low + index + index2]<root)
                return false;
            ++index2;
        }
        return helper(postorder,low, low+index-1)&&
               helper(postorder,low+index, high-1);
    }
};