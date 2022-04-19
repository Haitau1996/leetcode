// 贪心算法， 能种就种，最后看n是否小于等于 0
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto sz = flowerbed.size();
        for(size_t i = 0; i < sz; ++i){
            if(flowerbed[i] == 0){
                if((i == 0 || flowerbed[i-1] == 0) && (i == sz-1 || flowerbed[i+1] == 0)){
                    --n;
                    flowerbed[i] = 1;
                }
            }
            if(n <= 0) return true;
        }
        return false;
    }
};
