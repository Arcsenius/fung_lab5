#pragma once
#include <iostream>
#include <bitset>


class binary_int
{
private:
    int value;
    static int bitwise_add(int a, int b);
    static int bitwise_subtract(int a, int b);
public:
    binary_int(int v = 0);
    void print(std::ostream& os = std::cout) const;
    friend std::ostream& operator<<(std::ostream& , const binary_int& );
    binary_int operator-() const;
    binary_int& operator++();
    binary_int operator++(int);
    binary_int& operator--();
    binary_int operator--(int);
    binary_int& operator+=(const binary_int& other);
    binary_int operator+(const binary_int& other) const ;
    binary_int& operator-=(const binary_int& other);
    binary_int operator-(const binary_int& other) const;
    binary_int& operator*=(const binary_int& other);
    binary_int operator*(const binary_int& other) const;
    binary_int& operator>>=(const int shift);
    binary_int operator<<=(const int shift);
    binary_int operator>>(const int shift)  const;
    binary_int operator<<(int shift)  const;
    std::pair<binary_int, binary_int> split() const;
};