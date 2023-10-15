#include <iostream>
import student_1bib21062.Lab2.Variant22.Task1;
import student_1bib21062.Lab2.Variant22.Task2;
import student_1bib21062.Lab2.Variant22.Task3;
import student_1bib21062.Lab2.Variant22.Task4;
import student_1bib21062.Lab2.Variant22.Task5;

int main()
{
    int repeat;
    do {
        int option;
        ;
        std::cout << "Choose option 1-5: ";
        std::cin >> option;
        switch (option) {
        case 1: {

            std::cout << "Functions from Task1 were chosen: \n";
            RBPO::Lab2::Variant22::Task1::Function1();
            RBPO::Lab2::Variant22::Task1::Function2();
            int i;
            double result;
            std::cout << "Enter i: ";
            std::cin >> i;
            result = RBPO::Lab2::Variant22::Task1::FunctionA(i);
            std::cout << "Result of a(i) = " << result << std::endl;
            RBPO::Lab2::Variant22::Task1::Function3();
            RBPO::Lab2::Variant22::Task1::Function4();
            break;
        }
        case 2: {

            std::cout << "Functions from Task2 were chosen: \n";
            RBPO::Lab2::Variant22::Task2::Function1();
            RBPO::Lab2::Variant22::Task2::Function2();
            RBPO::Lab2::Variant22::Task2::Function3();
            RBPO::Lab2::Variant22::Task2::Function4();
            break;
        }
        case 3: {

            std::cout << "Functions from Task3 were chosen: \n";
            RBPO::Lab2::Variant22::Task3::Function1();
            RBPO::Lab2::Variant22::Task3::Function2();
            RBPO::Lab2::Variant22::Task3::Function3();
            RBPO::Lab2::Variant22::Task3::Function4();
            break;
        }
        case 4: {

            std::cout << "Functions from Task4 were chosen: \n";
            RBPO::Lab2::Variant22::Task4::Function1();
            RBPO::Lab2::Variant22::Task4::Function2();
            RBPO::Lab2::Variant22::Task4::Function3();
            RBPO::Lab2::Variant22::Task4::Function4();
            break;
        }
        case 5: {

            std::cout << "Functions from Task5 were chosen: \n";
            RBPO::Lab2::Variant22::Task5::Function1();
            RBPO::Lab2::Variant22::Task5::Function2();
            RBPO::Lab2::Variant22::Task5::Function3();
            RBPO::Lab2::Variant22::Task5::Function4();
            break;
        }
        default:
            std::cout << "Choose another option!\n";
        }
        std::cout << "To continue type '1': ";
        std::cin >> repeat;
    } while (repeat == 1);

    return 0;
}