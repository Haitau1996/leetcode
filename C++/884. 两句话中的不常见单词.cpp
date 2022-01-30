class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream stream(s1+" "+s2);
        unordered_map<string, int> hashTable;
        string temp;
        vector<string> result;
        while(!stream.eof()){
            stream>>temp;
            auto iter = hashTable.find(temp);
            if(iter == hashTable.end()){
                hashTable.insert(std::make_pair(temp,1));
            }
            else{
                iter->second = iter->second + 1;
            }
        }
        for(const auto& elem : hashTable){
            if(elem.second == 1){
                result.push_back(elem.first);
            }
        }
        return result;
    }
};