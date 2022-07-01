/*
 * 双指针处理， [low, high) 为当下的处理区间， 扫描 high， 并且记录 s[high] 上一次休闲的位置
    * 如果s[high] 上一次出现的位置在 low 之后， 右移动 high 不会增加不同字符的个数
    * 否则增加
 * 字符个数大于 2 的时候， 移动 low, 如果 s[low] 上一次出现的位置恰好为 low, 说明字符个数可以减1
 */
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        size_t n = s.size();
        int lastpos[128];
        memset(lastpos, -1, sizeof(lastpos));
        int char_cnt = 0;
        int low = 0;
        int high = 0;
        int res = 0;
        while(high < n){
            while(high < n && char_cnt <= 2){
                auto pos = lastpos[s[high]];
                if(pos >= low){
                    lastpos[s[high]] = high;
                    ++high;
                }else{
                    ++char_cnt;
                    lastpos[s[high]] = high;
                    ++high;
                }
                if(char_cnt <= 2) res = max(res, high-low);
            }
            if(lastpos[s[low]] == low){
                --char_cnt;
            }
            ++low;
        }
        return res;
    }
};