// 学习一个 C++ 标准库中生成随机数的方法
#include <random>
#include <vector>
using namespace std;
class Solution {
private:
    double r;
    double x;
    double y;

public:
    Solution(double radius, double x_center, double y_center)
        : r(radius)
        , x(x_center)
        , y(y_center)
    {
    }

    vector<double> randPoint()
    {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<> distr(0.0, 1.0);
        double rs = distr(eng);
        double theta = distr(eng) * 2 * acos(-1.0);
        rs = sqrt(rs);
        double rx = x + rs * cos(theta) * r;
        double ry = y + rs * sin(theta) * r;
        return vector<double> { rx, ry };
    }
};
