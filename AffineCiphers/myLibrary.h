#pragma once
#include<iostream>

using namespace std;

//hàm tìm ước chung lớn nhất của 2 số
int gcd(int a, int n);

/*
Hàm tìm nghịch đảo modulo với phương trình đồng dư: ay % n = b ( áp dụng Thuật toán Euclid mở rộng)
Các tham số truyền vào: r = n ; r1 = a; y1 = 1; y = 0
Tồn tại nghịch đảo khi thỏa mãn GCD(a,n) = 1
*/
int decryption(int r, int r1, int y1, int y);

//Hàm chuyển đổi từ ký tự sang kiểu dữ liệu tương ứng với ký tự trong bảng mã ascii
int *arrayAsciiOfString(char* a, int sizeOfChar);

//mã hóa chuổi ký tự theo mã affine
char *cryptography(int *arrAscii, int sizeOfChar, int a, int b);


//giải mã ký tự theo mã affine
char *decryptography(char *arrChar, int sizeOfChar, int a, int b);

