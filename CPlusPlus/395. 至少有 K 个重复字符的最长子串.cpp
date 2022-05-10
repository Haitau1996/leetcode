/*
 * 我们使用一个辅助函数 check_in_range 检查 low, high 之间所有字母是否出现次数大于 k， 将字母小于 k 的位置标记为 false, 然后递归检查每两个 false 之间的range。
最终将得到一个 bool 类型的数组， 只需要检查数组中最长的连续 true.
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int size = s.size();
        vector<bool> status(size, true);
        check_in_range(status,s,0,size-1,k);
        int res = 0;
        int low = 0;
        int high = 0;
        while(low < size){
            while(high < s.size() && status[high]){
                ++high;
            }
            if(high - low > res) res = high-low;
            low = high + 1;
            high = low;
        }
        return res;
    }
private:
    void check_in_range(vector<bool>& status, string& s, int low, int high, int k){
        if(low > high || (low == high && !status[low])) return;
        int temp_low = low;
        vector<int> count(26,0);
        for(int i = low; i <= high; ++i){
            count[s[i]-'a']++;
        }
        for(int i = low; i <= high; ++i){
            if(count[s[i]-'a']< k){
                status[i] = false;
            }
        }
        int cursor = low;
        while(cursor <= high){
            if(status[cursor]) ++cursor;
            else{
                check_in_range(status,s,low, cursor-1,k);
                low = cursor+1;
                cursor = low;
            }
        }
        if(low > temp_low) check_in_range(status,s,low, cursor-1,k);
    }
};
