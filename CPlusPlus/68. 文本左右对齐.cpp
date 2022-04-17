class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        size_t low = 0;
        size_t high = 0;
        auto sz = words.size();
        vector<string> res{};
        while(high < sz){
            int currSize = 0;
            string temp{};
            while(high < sz && (currSize + words[high].size() + (low == high? 0 : 1)) <= maxWidth){
                currSize+= (words[high].size()+ (low == high? 0 : 1));
                ++high;
            }
            --high;
            if(high != sz-1){
                if(low == high){
                    temp += words[low];
                    string spaces(maxWidth-currSize,' ');
                    temp += spaces;
                }else{
                    int wordCounts = high - low + 1;
                    int gapCount = high - low;
                    int avg_space = (maxWidth-currSize)/gapCount + 1;
                    int bigger_gap = (maxWidth-currSize)% gapCount;
                    temp += words[low];
                    for(int i=1; i<= bigger_gap; ++i){
                        string spaces(avg_space+1, ' ');
                        temp+= spaces;
                        temp+= words[low+i];
                    }
                    for(int i = bigger_gap+1; low + i <= high; ++i){
                        string spaces(avg_space, ' ');
                        temp+= spaces;
                        temp+= words[low+i];
                    }
                }
            }else{
                temp+= words[low];
                for(int i = low+1; i <= high; ++i){
                    temp+= " ";
                    temp+= words[i];    
                }
                string spaces(maxWidth-currSize,' ');
                temp += spaces;
            }
            res.push_back(temp);
            low = high+1;
            high = low;
        }
        return res;
    }
};
