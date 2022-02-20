class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result = 0;
        if(matrix.size() == 0 || matrix[0].size() == 0) return result;
        vector<int> buffer(matrix[0].size(),0);
        for(const auto& elem :matrix){
            for(int i = 0; i < elem.size(); ++i){
                if(elem[i] == '0') buffer[i] = 0;
                else buffer[i]++;
            }
            result = max(result,largestRectangleArea(buffer));
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> max_stack{};
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
};