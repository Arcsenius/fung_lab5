#include "../include/binary_int.hpp"



int binary_int::bitwise_add(int a, int b) {
    while (b) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}


int binary_int::bitwise_subtract(int a, int b){
    return bitwise_add(a, ~b + 1);
}


binary_int::binary_int(int v) : value(v) {};


binary_int binary_int::operator-() const {
    return binary_int(bitwise_add(0, value));
}


binary_int& binary_int::operator++() {
    value = bitwise_add(value, 1);
    return *this;
}


binary_int binary_int::operator++(int) {
    binary_int temp = *this;
    ++(*this);
    return temp;
}


binary_int& binary_int::operator--() {
    value = bitwise_subtract(value, 1);
    return *this;
}


binary_int binary_int::operator--(int) {
    binary_int temp = *this;
    --(*this);
    return temp;
}


binary_int& binary_int::operator+=(const binary_int& other) {
    value = bitwise_add(value, other.value);
    return *this;
}


binary_int binary_int::operator+(const binary_int& other) const {
    return binary_int(bitwise_add(value, other.value));
}


binary_int& binary_int::operator-=(const binary_int& other) {
    value = bitwise_subtract(value, other.value);
    return *this;
}


binary_int binary_int::operator-(const binary_int& other) const {
    return binary_int(bitwise_subtract(value, other.value));
}

binary_int& binary_int::operator*=(const binary_int& other) {
    int a = value;
    int b = other.value;

    //знак результата
    bool is_negative = (a < 0) ^ (b < 0); // true если только одно из чисел отрицательное

    // Берем модули чисел
    a = a < 0 ? bitwise_add(~a, 1) : a; // модуль для a
    b = b < 0 ? bitwise_add(~b, 1) : b; // модуль для b

    value = 0;

    //побитово
    while (b != 0) {
        if (b & 1) {
            value = bitwise_add(value, a);
        }
        a <<= 1;
        b >>= 1;
    }

    if (is_negative) {
        value = bitwise_add(~value, 1); // Делаем результат отрицательным
    }

    return *this;
}

binary_int binary_int::operator*(const binary_int& other) const {
    binary_int result = *this;
    result *= other;
    return result;
}


binary_int& binary_int::operator>>=(const int shift) {
    value >>= shift;
    return *this;
}


binary_int binary_int::operator<<=(const int shift) {
    value <<= shift;
    return *this;
}


binary_int binary_int::operator>>(const int shift)  const {
    return binary_int(value >> shift);
}


binary_int binary_int::operator<<(int shift)  const {
    return binary_int(value << shift);
}


std::pair<binary_int, binary_int> binary_int::split() const {
    int high = value & 0xFFFF0000;
    int low = value & 0x0000FFFF;
    return {binary_int(high), binary_int(low)};
}

std::ostream& operator<<(std::ostream& os, const binary_int& bi) {
    os << std::bitset<32>(bi.value);
    return os;
}


void binary_int::print(std::ostream& os) const {
    os << "Binary representation: " << *this << std::endl;
}