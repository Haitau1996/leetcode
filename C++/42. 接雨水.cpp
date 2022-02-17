/*
某个节点能够接下的雨水就是 min（左边最高，右边最高）- 节点值
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        vector<int> leftmax(sz,0);
        vector<int> rightmax(sz,0);
        leftmax[0] = height[0];
        int current_max = leftmax[0];
        for(int i = 1; i < height.size(); ++i){
            if(height[i] > current_max){
                current_max = height[i];
            }
            leftmax[i] = current_max;
        }
        rightmax[height.size()-1] = height[height.size()-1];
        current_max = rightmax[height.size()-1];
        for(int i = height.size()-1; i >=0; --i){
            if(height[i] > current_max){
                current_max = height[i];
            }
            rightmax[i] = current_max;
        }
        int sum = 0;
        for(int i = 0; i < height.size(); ++i){
            sum += std::min(leftmax[i],rightmax[i]) - height[i];
        }
        return sum;
        
    }  
};