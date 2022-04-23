/*
 * (BFSolution)暴力做法： 121 out of 121 test case passed
 * 超出时间限制
 * (Solution) 做出改进： 中心开花判断是否回文
 * 设置回文串的中心为 left,和 right(两者可以相等)， 然后中心开花直到 left 为 负则可以断言 0 - (left+right+1) 是回文的， 
如果不是回文， left 小于 right 则减小 left, 否则减小 right.然后我们只需要设置 left 和 right 初始值为 字符串中间， 找到回文即确定最长的回文前缀。
todo: 使用 KMP 实现
 */
class BFSolution {
public:
    string shortestPalindrome(string s) {
        int max_len = 0;
        int low = 0;
        for(int high = 0; high< s.size(); ++high){
            if(isPalin(s, low,high))
                max_len = high - low + 1;
        }
        string temp = s.substr(max_len);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
private:
    bool isPalin(const string& s, int low, int high){
        while(low < high){
            if(s[low] != s[high]) return false;
            ++low;
            --high;
        }
        return true;
    }
};
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() == 0) return s;
        int midLeft = (s.size() + 1)/2;
        int midRight = (s.size()&0x1 ? midLeft :midLeft +1);
        while(!isPalin(s, midLeft, midRight)){
            if(midLeft == midRight) --midLeft;
            else --midRight;
        }
        int max_len = midLeft + midRight + 1;        
        string temp = s.substr(max_len);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
private:
    bool isPalin(const string& s, int left, int right){
        while(left >= 0){
            if(s[left] != s[right]) return false;
            --left;
            ++right;
        }
        return true;
    }
};
