#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include<stdexcept>
#include<vector>

struct Point {
    double X;
    double Y;
};

struct Regression_result
{
    double A;
    double B;
};

struct Regression_data
{
    double sum_x_;
    double sum_xy_;
    double sum_x2_;
    double sum_y_;   
};

class Regression {
    private:
        double sum_x_{};
        double sum_xy_{};
        double sum_x2_{};
        double sum_y_{};
        long unsigned int size_{};
        double denominator_{};
    public:
        Regression(std::vector<Point> const& pool) : size_{pool.size()}
        {
            if (size_ < 2) {
                throw std::runtime_error{"Not enough points to run a fit"};
            }

            for (long unsigned int i = 0; i != size_; ++i){
                Point const& v = pool[i];
                sum_x_ += v.X;
                sum_y_ += v.Y;
                sum_x2_ += v.X * v.X;
                sum_xy_ += v.X * v.Y;
            }

            denominator_ = ((size_*sum_x2_)-(sum_x_*sum_x_));

            if (denominator_ == 0){
                throw std::runtime_error{"Fit vertical line"};
            }


        }

        Regression_data getRegressionData() const;

        double fitA() const;

        double fitB() const;

        Regression_result fit() const;

};

#endif