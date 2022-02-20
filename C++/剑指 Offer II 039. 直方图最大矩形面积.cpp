/*
* 最符合直觉的做法是分治
1. 先找到最小值和其下标mid_index， 将[beg, end)分成三个部分,取其中的最大值
    1. 左边[beg, min_index)
    2. 最小值 * (end - beg)
    3. 右边[min_index, end)
2. 因为可能出现所有值相等的情况， 因此找区间最小值时候使用一个随机数作为初始值
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
// 单调栈实现
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_aera{};
        max_stack.push(-1);
        for(int i = 0; i < heights.size(); ){
            if(max_stack.top() == -1 || heights[i] >= heights[max_stack.top()]){
                max_stack.push(i);
                ++i;
            }
            else{
                int top = max_stack.top();
                max_stack.pop();
                int aera{};
                int width = i - max_stack.top() -1;
                aera = heights[top] * width;
                if(aera > max_aera) max_aera = aera;
            }
        }
        while(max_stack.top()!= -1){
            int top = max_stack.top();
            max_stack.pop();
            int aera{};
            int width = heights.size() - max_stack.top() -1; 
            aera = heights[top] * width;
            if(aera > max_aera) max_aera = aera;    
        }
        return max_aera;
    }
private:
    stack<int> max_stack{};
};