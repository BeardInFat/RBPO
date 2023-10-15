#include <cmath>
#include <iostream>

export module student_1bib21062.Lab2.Variant22.Task1;

namespace RBPO {
	namespace Lab2 {
		namespace Variant22 {
			namespace Task1 {
				
				export void Function1() {
					double x;
					std::cout << "Enter x >> ";
					std::cin >> x;
					double result = (4 - x * x) / 2;
					std::cout << "Result equals " << result << std::endl;
				}

				export void Function2() {
					double x;
					std::cout << "Enter x >> ";
					std::cin >> x;
					double result = 0;
					x > 3 ? result = 1.2*x*x - 3*x -9 : result = 12 / (2 *x*x + 1);
					std::cout << "Result equals " << result << std::endl;
				}

				export double FunctionA(int i) {
					double result = pow(-1, i) * (i + 1) / (i*i*i + 2);
					return result;
				}

				export void Function3() {
					std::cout << "Enter the number of iterations(n) >> ";
					int n;
					std::cin >> n;
					double sum = 0.0;
					for (int i = 0; i <= n; i++) {
						sum += FunctionA(i);
					}
					std::cout << "Result of f3(" << n << ") equals " << sum << std::endl;
				}

				export void Function4() {
					std::cout << "Enter the accuracy of the ending iteration >> ";
					double E;
					std::cin >> E;
					double sum = 0.0;
					double prevSum = 0.0;
					double nextSum = 0.0;
					int k = 0;
					for (int i = 0;; i++)
					{
						prevSum = nextSum;
						nextSum = FunctionA(i);
						sum += FunctionA(i);
						k = i;
						if (abs(nextSum - prevSum) <= E)
						{
							break;
						}
					}
					std::cout << "Result of f4() equals " << sum << std::endl << "Number of the last member k = " << k << std::endl;
				}
			}
		}
	}
}