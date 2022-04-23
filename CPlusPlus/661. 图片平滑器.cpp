// 先使用前缀和缓存， 在 img[i][j] 存放从 [0][0] 到 [i][j] 的和， 然后矩形的面积就可以写成
// 前缀和 - 上面部分 - 左边部分 + 左上角被减去两次的部分

#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        for(int i = 0; i < m; ++i){
            int curr_sum = 0;
            for(int j = 0; j < n; j++){
                curr_sum += img[i][j];
                img[i][j] = (i== 0? 0 : img[i-1][j]) + curr_sum;
            }
        }
        vector<vector<int>> res(m, vector<int>(n,0));
        for(int i = 0; i < m; ++i){
            for(int j= 0; j < n; ++j){
                int m_start = max(i-1,0);
                int n_start = max(j-1,0);
                int m_end = min(i+1, m-1);
                int n_end = min(j+1, n-1);
                int ALL = img[m_end][n_end];
                int UP = (m_start == 0 ? 0 : img[m_start-1][n_end]);
                int LEFT = (n_start == 0? 0 : img[m_end][n_start-1]);
                int ADD = (( m_start == 0 || n_start == 0)? 0 : img[m_start-1][n_start-1]);
                res[i][j] = (ALL+ADD - UP - LEFT)/((m_end-m_start+1)*(n_end-n_start+1));
            }
        }
        return res;
    }
};
