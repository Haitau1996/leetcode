class TwoSum {
public:
    TwoSum() {

    }
    
    void add(int number) {
        if(buffer.size() == 0 || buffer.back() < number)
            buffer.push_back(number);
        else {
            auto iter = buffer.begin();
            while(*iter < number) iter++;
            buffer.insert(iter, number);
        }

    }
    
    bool find(int value) {
        auto low = buffer.begin();
        auto high = buffer.end();
        --high;
        while(low != high){
            if(*low + *high > value) --high;
            else if(*low + *high < value) ++low;
            else return true;
        }
        return false;
    }
private:
    list<int> buffer;
};
