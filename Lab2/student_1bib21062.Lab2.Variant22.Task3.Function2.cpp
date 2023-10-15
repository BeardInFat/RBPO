#include <cmath>
#include <iostream>
module student_1bib21062.Lab2.Variant22.Task3;
void RBPO::Lab2::Variant22::Task3::Function2() {
    double x;
    std::cout << "Enter x >> ";
    std::cin >> x;
    double result = 0;
    if (x > 3)
        result = 1.2 * x * x - 3 * x - 9;
    else
        result = 12 / (2 * x * x + 1);
    std::cout << "Result equals " << result << std::endl;
}