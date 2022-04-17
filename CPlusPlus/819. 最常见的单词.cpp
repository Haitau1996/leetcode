class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(auto & elem : paragraph){
            if(isalpha(elem)) elem = tolower(elem);
            else elem = ' ';
        }
        for(auto & elem:banned){
            for(auto& c : elem)
            {
                c = tolower(c);
            }
        }
        unordered_set<string> banset(banned.begin(), banned.end());
        unordered_map<string, int> count;
        istringstream ss(paragraph);
        string temp;
        string res;
        int res_count = 0;
        while(getline(ss, temp, ' ')){
            if(temp.size() == 0) continue;
            if(banset.find(temp) == banset.end()){
                ++count[temp];
                if(count[temp] > res_count){
                    res_count = count[temp];
                    res = temp;
                }
            }
        }
        return res;
    }
};
