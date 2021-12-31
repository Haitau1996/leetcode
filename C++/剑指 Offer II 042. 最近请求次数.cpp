class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        buffer.push_back(t);
        while(buffer.front() + WINDOW < t){
            buffer.pop_front();
        }
        return buffer.size();
    }
private:
    std::deque<int> buffer;
    const int WINDOW{3000};
};