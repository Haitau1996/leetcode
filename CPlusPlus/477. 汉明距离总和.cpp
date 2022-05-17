// 做法 1： 将任意两个数之间的 xor 求出来， 然后暴力求解，超出时间限制 O(n^2 * 30)
// 优化做法： 统计每个位出现的次数，如果出现了 i 次， 总共有 n 个数，结果要加上 i*(n-i) O(n*30)
class BetterSolution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> cnt(30,0);
        for(const auto& elem : nums){
            for(int i = 0; i < 30; ++i){
                if(elem &(1<<i)) cnt[i]++;
            }
        }
        int res{};
        int n = nums.size();
        for(const auto&elem : cnt){
            res += elem * (n-elem);
        }
        return res;
    }
};
