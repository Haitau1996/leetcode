/*
执行用时：12 ms, 在所有 C++ 提交中击败了97.33% 的用户
内存消耗：17.3 MB, 在所有 C++ 提交中击败了82.43% 的用户
这个题目写的时候需要注意下面几点：
* 使用递归的方式， 将整个 string 考虑成第一个 char + 剩下的 string, 然后逐步递归
* 第一个元素每次都要和后面的换， 但是需要注意一种情况就是有字母重复的情况， 可以去做剪肢
* 只有扫描到 string 尾部的时候才 push， 每次 扫描到尾部的 string 都是换过之后的，递归结束之后要换回来
*/
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        helper(res, s, 0);
        return res;
    }
private:
    void helper(vector<string>& res, string& s, int pos){
        if(pos == s.size())
            res.push_back(s);
        for(size_t i = pos; i < s.size(); ++i){
            bool checked = false;
            for(size_t j = pos;j< i; ++j){
                if(s[i]== s[j]) checked = true;
            }
            if(!checked){
                swap(s[pos],s[i]);
                helper(res,s,pos+1);
                swap(s[pos],s[i]);
            }    
        }
    }

};