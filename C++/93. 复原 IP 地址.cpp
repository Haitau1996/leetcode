/*
使用一个 vector of string 维护已经选好的 ip 部分， 使用两个指针维护正在做选择的部分
1. case 1, 选择当下: 如果 [low, high] 之间的部分符合要求， 将它压入 selected, 然后 low = high + 1, high = high + 1 递归求解，求解之后记得还原 selected
2. case 2, 忽略当下： high = high + 1
3. 递归的终止条件(base case)需要特别注意
    1. case 1: 符合要求， 即 low = s.size 并且 selected 中刚好有四个字符串，将它写入结果
    2. case 2: selected 已经有四个， 还没到底， 没必要继续下去
    3. case 3: low/high 已经挪到底还不符合要求
    4. case 4: low,high 之间不止一个数字且以 0 开头， 不符合要求
    5. case 5: low, high 之间已经有超过三个数字了， 肯定不符合要求
4. 如果 s长度小于 4 或者大于 12， 那没有求解的必要了
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() >= 4 && s.size()<=12) dfs(s,0,0);
        return result;
    }
private:
    vector<string> selected{};
    vector<string> result{};
    void dfs(string& s, int low, int high){
        if(low == s.size() && selected.size() == 4){
            result.push_back(format_address(selected));
            return;
        }
        if(selected.size() >= 4) return;
        if(low >= s.size() || high >= s.size()) return;
        if(s[low] == '0' && low!=high) return;
        if(high-low > 3) return;
        // selected current
        auto current_str = s.substr(low,high-low+1);
        int current = stoi(current_str);
        if(current<256 && selected.size() < 4){
            selected.push_back(current_str);
            dfs(s,high+1,high+1);
            selected.pop_back();
        }
        // ignore current
        dfs(s,low, high+1);
    }
    string format_address(vector<string>& buffer){
        string result(buffer[0]);
        for(int i = 1; i < buffer.size(); ++i){
            result += ".";
            result += buffer[i];
        }
        return result;
    }
};