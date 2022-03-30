#include<vector>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_counts = 0;
        int max_times = 0;
        vector<int> count(26,0);
        for(const auto& elem :tasks){
            count[elem-'A']++;
            if(count[elem-'A'] > max_counts){
                max_counts = count[elem-'A'];
                max_times = 1;
            }else if(count[elem-'A'] == max_counts){
                max_times = max_times + 1;
            }
        }
        if((max_counts-1)*(n+1) + max_times < static_cast<int>(tasks.size()))
            return tasks.size();
        else return (max_counts-1)*(n+1) + max_times;
        
    }
};
