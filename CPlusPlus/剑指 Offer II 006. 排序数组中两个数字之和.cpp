/*
执行用时：4 ms, 在所有 C++ 提交中击败了86.58% 的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了72.31% 的用户
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int beg =0; 
        int end = numbers.size()-1;
        while(beg != end){
            if(numbers[beg] + numbers[end] == target) break;
            else if(numbers[beg] + numbers[end] > target) --end;
            else ++beg;
        }
        vector<int> res{beg,end};
        return res;
    }
};