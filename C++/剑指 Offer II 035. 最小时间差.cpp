class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() > 1440) return 0;
        vector<bool> flags = vector<bool>(1440,false);
        for(const auto& elem : timePoints){
            int time_in_integer = phase_time(elem);
            if(flags[time_in_integer]) return 0;
            else flags[time_in_integer] = true;
        }
        return check_time_vec(flags);
    }
private:
    int phase_time(string time){
        istringstream time_stream(time);
        vector<string> vecs;
        while(time_stream.good()){
            string temp;
            getline(time_stream,temp,':');
            vecs.push_back(temp);
        }
        return stoi(vecs[0]) * 60 + stoi(vecs[1]);
    }
    int check_time_vec(vector<bool>& input){
        int min_diff = input.size() - 1;
        int prev = -1;
        int first = input.size() - 1;
        int last = -1;
        for(int i =0; i< input.size(); ++i){
            if(input[i]){
                if(prev != -1){
                    min_diff = min(i-prev,min_diff);
                }
                prev = i;
                first = min(i,first);
                last = max(i,last);
            }
        }
        return  min(int(first+input.size()-last), min_diff);
    }
};