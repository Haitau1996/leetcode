/* 
执行用时：16 ms, 在所有 C++ 提交中击败了81.29% 的用户
内存消耗：18.8 MB, 在所有 C++ 提交中击败了42.15% 的用户
* 经典的快慢指针
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto slow = nums.begin();
        auto fast = nums.begin();
        while(fast!=nums.end()){
            *slow = *fast;
            if(*slow == 0){
                fast++;
            }
            else{
                slow++;
                fast++;
            }
        }
        while(slow!=nums.end()){
            *slow++ = 0;
        }
    }
};