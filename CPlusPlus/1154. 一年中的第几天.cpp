class Solution {
public:
    int dayOfYear(string date) {
        string temp;
        istringstream in(date);
        vector<int> date_int{};
        while(getline(in, temp, '-')){
            date_int.push_back(stoi(temp));
        }
        vector<int> buffer{31,28,31,30,
                           31,30,31,31,
                           30,31,30,31};
        int year = date_int[0];
        int month = date_int[1];
        int day = date_int[2];
        if(year %400 == 0 || (year %4 == 0 && year%100 != 0)){
            buffer[1]++;
        }
        return day + accumulate(buffer.begin(), buffer.begin()+month-1,0);
    }
};
