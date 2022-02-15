/*
* 最符合直觉的做法是分治
1. 先找到最小值和其下标mid_index， 将[beg, end)分成三个部分,取其中的最大值
    1. 左边[beg, min_index)
    2. 最小值 * (end - beg)
    3. 右边[min_index, end)
2. 因为可能出现所有值相等的情况， 因此找区间最小值时候使用一个随机数作为初始值
todo: 使用单调栈实现
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return divide(heights,0,heights.size());
    }
private:
    int divide(vector<int>& heights, int beg, int end){
        if(beg >= end) return 0;
        if(end == beg + 1) return heights[beg];
        int rd = rand()%(end - beg) + beg;
        int min = heights[rd];
        int min_index = rd;
        for(int i = beg; i < end; ++i){
            if(heights[i] < min){
                min = heights[i];
                min_index = i;
            }
        }
        int middle = min * (end - beg);
        int left = divide(heights, beg,min_index);
        int right = divide(heights,min_index+1,end);
        return max({left,middle,right});
    }
};