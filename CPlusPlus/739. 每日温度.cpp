class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> max_index{};
        for(int i = 0; i < temperatures.size(); ++i){
            while(!max_index.empty() && temperatures[i] > temperatures[max_index.top()]){
                int prev = max_index.top();
                result[prev] = i - prev;
                max_index.pop();
            }
            max_index.push(i);
        }
        return result;
    }
};