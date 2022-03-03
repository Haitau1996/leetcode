/*
典型的递归求解， 思路如下， 我们使用 beg, end 标志字符串的一个子串， 然后使用 selected 存放已经选择的数字

1. 如果 [beg,end] 之间的数字可以放入数组中， 那么就将它放入， 然后将 [beg, end] 设置为 [beg+1, end+1],递归求解
    1. 递归返回 true 的话整体结果为 true
    2. 递归返回 false 需要将数字 pop 出来
2. 无法放入的话， 那么就将 end+1
3. base case: beg 和 end 到头了， 有两种情况
    1. beg-1, end-1 刚放入数组中， 这时候返回 true
    2. 单单 end 到头了， 返回 false

这道理的测试有很多边界的 case 需要特别注意的：
1. num.len < 35, 最极端的情况下是 1 + 17 + 17, 因此使用一个 int 是放不下的
2. 数字可能以先导 0 开始， 如 1023, 不做判断的话 1 + 02 = 3 也会返回 true
*/
class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> selected{};
        return dfs(num, 0, 0,selected);
    }
private:
    
    bool dfs(string& s, int start, int end, vector<long long>& selected){
        if(end == s.size() && start == s.size()){
            if(selected.size() > 2) return true;
            else return false;
        }
        else if(end == s.size() || end - start >= 19) return false;
        if(end > start && s[start] == '0') return false;
        // case 1 : push current
        long long current = stoll(s.substr(start,end-start+1));
        if(selected.size() < 2 || (selected[selected.size()-1] + selected[selected.size()-2] == current)){
            selected.push_back(current);
            if(dfs(s,end+1,end+1,selected)) return true;
            else{
                selected.pop_back();
                return dfs(s, start, end+1,selected);
            }
        }
        return dfs(s, start, end+1,selected);
    }
};