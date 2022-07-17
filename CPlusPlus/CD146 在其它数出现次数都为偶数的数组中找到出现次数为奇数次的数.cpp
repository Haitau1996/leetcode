#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> 
using namespace std;
int core(vector<int>& input){
    int result = 0;
    for(const auto& elem : input){
        result = result ^ elem;
    }
    return 0^result;
}
int main(){
    int size;
    cin >> size;
    vector<int> in;
    std::copy(istream_iterator<int>(std::cin),istream_iterator<int>(), back_inserter(in));
    std::cout << core(in);
    return 0;
}
