#include <cmath>
#include <iostream>
module student_1bib21062.Lab2.Variant22.Task4:Function4;

import :FunctionA;

void RBPO::Lab2::Variant22::Task4::Function4() {
    std::cout << "Enter the accuracy of the ending iteration >> ";
    double E;
    std::cin >> E;
    double sum = 0.0;
    double prevSum = 0.0;
    double nextSum = 0.0;
    int k = 0;
    int i = 0;
    while (true)
    {
        prevSum = nextSum;
        nextSum = FunctionA(i);
        sum += FunctionA(i);
        k = i;
        if (abs(nextSum - prevSum) <= E)
        {
            break;
        }
        i++;
    }
    std::cout << "Result of f4() equals " << sum << std::endl << "Number of the last member k = " << k << std::endl;
}