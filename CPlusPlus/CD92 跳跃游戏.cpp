#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
void core(vector<int>& input)
{
    auto riter = input.rbegin();
    auto rbeg = input.rbegin();
    *riter = 0;
    ++riter;
    auto rlast = input.rend();
    while (riter != rlast) {
        if (distance(rbeg, riter) < *riter) {
            *riter = 1;
            ++riter;
        } else {
            *riter = *min_element(riter - (*riter), riter) + 1;
            ++riter;
        }
    }
    std::cout << input[0];
}
int main()
{
    int arr_size;
    cin >> arr_size;
    vector<int> input_arr;
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(input_arr));
    core(input_arr);
    return 0;
}
