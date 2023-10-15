#include <cmath>
#include <iostream>
module student_1bib21062.Lab2.Variant22.Task3;
double RBPO::Lab2::Variant22::Task3::FunctionA(int i) {
    double result = pow(-1, i) * (i + 1) / (i * i * i + 2);
    return result;
}