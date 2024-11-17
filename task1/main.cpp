#include "./include/binary_int.hpp"


int main() {

    binary_int num1(-2);
    binary_int num2(-5);

    // тест сложения
    std::cout << "Addition +" << std::endl;

    num1 = num1 + num2;
    num1.print();


    // тест вычитание
    std::cout << "Subtraction -" << std::endl;

    num1 = num1 - num2;
    num1.print();

    // тест += и -=
    std::cout << "Addition +=" << std::endl;

    num1 += num2;
    num1.print();

    std::cout << "Subtraction -=" << std::endl;
    num1 -= num2;
    num1.print();


    // тест умножение
    std::cout << "Multiplication *" << std::endl;

    num1 = num1 * num2;
    num1.print();


    std::cout << "Multiplication *=" << std::endl;
    binary_int num3(5);

    num3 *= num2;
    num3.print();


    //тест сдвиги
    std::cout << "Logical shift <<=" << std::endl;

    num3 <<= 1;
    num3.print();

    std::cout << "Logical shift >>=" << std::endl;

    num3 >>= 1;
    num3.print();


    std::cout << "Logical shift <<" << std::endl;
    binary_int num4 = num3 << 1;
    num4.print();


    std::cout << "Logical shift >>" << std::endl;
    binary_int num5 = num3 >> 1;
    num5.print();


    std::cout << "Unary minus" << std::endl;

    binary_int num6 = -num5;
    num6.print();


    std::cout << "Split" << std::endl;



    binary_int num7(2147483647); //2**31 - 1
    std::pair<binary_int, binary_int> para = num7.split();
    para.first.print();
    para.second.print();
}