/*
在回溯求解过程中， 我们一定要记得** dfs 完了后要将之前 push_back 的元素弹出来**，例如我们用 AAAA 构造了第一个解 aaaa, 如果不pop_back, 那么第二个解就会变成 aaaaA.
1. 递归的基础 case: 光标移动到 s 队尾的后一个元素， 压入当前字符串， 然后返回
2. recursive case: 当前的光标指向一个数字， 压入到 selected, 然后光标后移动
3. recursive case2: 当前的光标指向一个字母， 那么分别用压入 toupper 和 tolower， 光标右移
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了20.71% 的用户
*/
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s,0);
        return result;
    }
private:
    vector<string> result;
    string selected{};
    void dfs(string& s, int cursor){
        if(cursor == s.size()) {
            result.push_back(selected);
            return;
        }
        else if(isalpha(s[cursor])){
            // case 1: smaller case
            char low = tolower(s[cursor]);
            selected.push_back(low);
            dfs(s,cursor+1);
            selected.pop_back();
            char high = toupper(s[cursor]);
            selected.push_back(high);
            dfs(s,cursor+1);
            selected.pop_back();
        }else{
            selected.push_back(s[cursor]);
            dfs(s,cursor+1);
            selected.pop_back();
        }
    }
};