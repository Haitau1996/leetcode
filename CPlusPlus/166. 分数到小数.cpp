class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return to_string(0);
        int count = 0;
        unsigned a,b;
        if(numerator < 0){
            a = ~unsigned(numerator)+1;
            ++count;
        }else{
            a = numerator;
        }
        if(denominator < 0){
            b = ~unsigned(denominator)+1;
            ++count;
        }else{
            b = denominator;
        }
        if(count%2) return "-"+Core(a,b);
        else return Core(a, b);

    }
    string Core(unsigned long numerator, unsigned long denominator){
        unsigned long round = numerator/denominator;
        string res{};
        res+= to_string(round);
        numerator = numerator%denominator;
        if(numerator!=0){
            res.push_back('.');
        }
        unordered_map<int,int> num_to_pos;
        unsigned long pos = 0;
        string decimal{};
        numerator*=10;
        while(numerator!=0 && num_to_pos.find(numerator) == num_to_pos.end()){
            num_to_pos.emplace(numerator, pos); 
            unsigned long res = numerator/denominator;
            decimal.push_back(res+'0');
            numerator = numerator%denominator;
            ++pos;
            numerator*=10;
        }
        if(numerator == 0) return res+decimal;
        else{
            auto insert_pos = num_to_pos[numerator];
            decimal.insert(insert_pos,1,'(');
            decimal.push_back(')');
            return res+decimal;
        }
    }
};
