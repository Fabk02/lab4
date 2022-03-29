#include "linearRegression.hpp"

Regression_data Regression::getRegressionData() const {
    Regression_data export_data{};
    export_data.sum_x_ = sum_x_;
    export_data.sum_y_ = sum_y_;
    export_data.sum_xy_ = sum_xy_;
    export_data.sum_x2_ = sum_x2_;
    return export_data;
}

double Regression::fitA() const {
    return (((sum_y_*sum_x2_) - (sum_x_*sum_xy_))/denominator_);
}

double Regression::fitB() const {
    return (((size_*sum_xy_) - (sum_x_*sum_y_))/denominator_);
}

Regression_result Regression::fit() const {
    Regression_result export_result{};
    export_result.A = fitA();
    export_result.B = fitB();
    return export_result;
}
