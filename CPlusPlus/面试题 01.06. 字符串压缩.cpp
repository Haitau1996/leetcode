/*
执行用时：8 ms, 在所有 C++ 提交中击败了77.64% 的用户
内存消耗：7.3 MB, 在所有 C++ 提交中击败了16.21% 的用户
* C++ 可以直接使用 std::to_string
*/
#include <string>

using namespace std;
class Solution {
public:
    string compressString(string S) {
        string result{};
        int count = 1;
        char temp = S[0];
        for(int i = 1; i < S.size(); ++i){
            if(S[i] == temp) {
                ++count;
            }
            else{
                result.push_back(temp);
                result += to_string(count);
                count = 1;
                temp = S[i];
            }
        }
        result.push_back(temp);
        result += to_string(count);
        return result.size() < S.size() ? result: S;

    }
};
