/* ### 解题思路
用一个指针 current 指向当前的房子， 两个指针low, high 指向相邻的两个供暖器：
case 1 : 房子离第一个供暖器近， 取当下值和半径的比较更新， ++current
case 2 : 房子离第二个供暖器近， 这时候不知道是否有更近的供暖器， ++low, ++high

需要考虑两个特殊情况：
1. high 已经超过数组范围， 距离就是 numeric_limits<int>::max
2. 两个供暖器距离一致， 这时候可能的情况是两个供暖器位置相同， 并且都不是最小值， 因此需要 ++low, ++high 看有没有更近的

执行用时：44 ms, 在所有 C++ 提交中击败了89.52% 的用户
内存消耗：24.6 MB, 在所有 C++ 提交中击败了81.39% 的用户
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(), heaters.end());
        int current = 0;
        int low = 0;
        int high = low+1;
        int m = houses.size();
        int n = heaters.size();
        int radius = 0;
        while(current < m){
            int distance1 = abs(houses[current]- heaters[low]);
            int distance2 = high < n ? abs(houses[current] - heaters[high]) : numeric_limits<int>::max();
            if(distance1 < distance2){
                ++current;
                if(distance1 > radius) radius = distance1;
            }else{
                ++low;
                ++high;
            }
        }
        return radius;
    }
};