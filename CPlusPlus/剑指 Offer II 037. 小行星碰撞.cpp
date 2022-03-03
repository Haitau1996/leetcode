/*
执行用时：8 ms, 在所有 C++ 提交中击败了94.92% 的用户
内存消耗：17 MB, 在所有 C++ 提交中击败了75.05% 的用户
* 需要注意的是， while 语句中的关系应该是 and 而不是 or
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> buffer{};
        for(auto& elem : asteroids){
            if(buffer.empty() || elem > 0 ||buffer.back() < 0){
                buffer.push_back(elem);
            }
            else {
                while((!buffer.empty()) && (buffer.back() > 0) && (buffer.back() < (-elem))){
                    buffer.pop_back();
                }
                if(buffer.empty() || buffer.back() < 0){
                    buffer.push_back(elem);
                }
                else if(buffer.back() == (-elem)) buffer.pop_back();
            }
        }
        return buffer;
    }
};