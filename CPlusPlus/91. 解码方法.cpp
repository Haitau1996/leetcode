/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了59.95% 的用户
* 需要考虑的情况挺多的， 沉下心来慢慢分析
* **一定要记得区分 `=` 和 `==`**
*/
class Solution {
public:
    int numDecodings(string s) {
        dpbuffer = vector<int>(s.size(),0);
        if(s[0] == '0') return 0;
        else{
            dpbuffer[0] = 1;
            dp(s, 1);
            return dpbuffer.back();
        }
    }
private:
    vector<int> dpbuffer;
    void dp(string&s, int index){
        if(index == s.size()) return;
        else{
            if(s[index] == '0' && (s[index-1] =='0'||s[index-1]>'2')){
                return;
            }
            else if(s[index] == '0' && s[index-1] <= '2'){
                if(index == 1) dpbuffer[index] = 1;
                else dpbuffer[index] = dpbuffer[index-2];
            }else if(s[index-1]=='0'){
                dpbuffer[index] = dpbuffer[index-1];
            }else if(stoi(s.substr(index-1,2))<=26){
                if(index == 1) dpbuffer[index] = 2;
                else dpbuffer[index] = dpbuffer[index-1] + dpbuffer[index-2];
            }else{
                dpbuffer[index] = dpbuffer[index-1];
            }
            dp(s,index+1);
        }
    }
};