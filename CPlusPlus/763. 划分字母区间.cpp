/*
我们使用一个哈希表记录每个字母最后一次出现的位置， 然后从前到后扫描数组， 变量说明
1. 保持变量 start 表示当前处理的部分起始位置
2. 使用变量 current 表示当前正在处理的光标位置
3. 使用变量 end 表示已经处理的字符最后出现的位置，

从前到后扫描， 有三种情况， 三种情况下都记得及时更新 current
1. s[current] 最后出现的位置后于 end, 更新end
2. s[current] 最后出现的位置刚好是 end, 并且 current 等于 end, 说明当前区间已经处理结束，我们需要做2.5件事情
    1. 向结果压入 end-start+1
    2. 更新 start 的值为 end+1
    3. 如果新的 start 还在 s 长度范围内， 更新 end 的值
3. 其他情况
执行用时：4 ms, 在所有 C++ 提交中击败了64.25% 的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了99.52% 的用户
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_one(26,-1);
        for(int i = s.size()-1; i >= 0; i--){
            if(last_one[s[i]-'a'] == -1) last_one[s[i]-'a'] = i;
        }
        vector<int> result{};
        int start = 0;
        int current = 0;
        int end = last_one[s[start]-'a'];
        while(current < s.size()){
            int new_end = last_one[s[current]-'a'];
            if(new_end > end){
                end = new_end;
            }else if(new_end == end && current == end){
                result.push_back(end-start+1);
                start = current+1;
                if(start<s.size()) end = last_one[s[start]-'a'];
            }
            current = current+1;
        }
        return result;
    }
};