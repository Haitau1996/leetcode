/*
执行用时：136 ms, 在所有 C++ 提交中击败了66.83% 的用户
内存消耗：86.8 MB, 在所有 C++ 提交中击败了50.21% 的用户
* 这道题最重要的思路是， 我们可以压入一个元素的下标而非元素本身
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        for(int i = 0; i <temperatures.size(); ++i){
            while(!to_modefy.empty() && temperatures[i] > temperatures[to_modefy.top()]){
                result[to_modefy.top()] = i - to_modefy.top();
                to_modefy.pop();
            }
            to_modefy.push(i);
        }
        return result;
    }
private:
    stack<int> to_modefy{};
};