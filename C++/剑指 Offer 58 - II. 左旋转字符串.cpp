/*
执行用时：4 ms, 在所有 C++ 提交中击败了71.53% 的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了67.67% 的用户
* 和之前的旋转矩阵有点像， 想要直接旋转有点困难， 就以某个锚定物，两边先各转一次， 然后全局再转一次
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        swap_char(s,0,n-1);
        swap_char(s,n,s.size()-1);
        swap_char(s,0,s.size()-1);
        return s;
    }
private:
    void swap_char(string& s, int low, int high){
        while(low < high){
            auto temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            ++low;
            --high;
        }
    }
};