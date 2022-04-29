#include <iterator>
#include <vector>

using namespace std;
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec)
        : my_vec(vec)
    {
        iter_row_end = vec.end();
        iter_row = vec.begin();
        if (iter_row != iter_row_end) {
            iter_col = (*iter_row).begin();
            iter_col_end = (*iter_row).end();
        }
        while (iter_col == iter_col_end) {
            if (iter_row != iter_row_end) {
                ++iter_row;
                if (iter_row != iter_row_end) {
                    iter_col = (*iter_row).begin();
                    iter_col_end = (*iter_row).end();
                }
            } else
                break;
        }
    }

    int next()
    {
        int res = *iter_col;
        ++iter_col;
        while (iter_col == iter_col_end) {
            if (iter_row != iter_row_end) {
                ++iter_row;
                if (iter_row != iter_row_end) {
                    iter_col = (*iter_row).begin();
                    iter_col_end = (*iter_row).end();
                }
            } else
                break;
        }
        return res;
    }

    bool hasNext()
    {
        return iter_row != iter_row_end;
    }

private:
    vector<vector<int>>& my_vec;
    vector<vector<int>>::iterator iter_row;
    vector<vector<int>>::iterator iter_row_end;
    vector<int>::iterator iter_col;
    vector<int>::iterator iter_col_end;
};
