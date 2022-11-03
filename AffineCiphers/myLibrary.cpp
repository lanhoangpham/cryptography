#include "myLibrary.h"


/*
Các ký tự trong phạm vi mã hóa : A B C D E F G H I J K L M N O P Q R S TU V W X Y Z


*/

//hàm tìm ước chung lớn nhất của 2 số
int gcd(int a, int n) {
	if (a == 0 || n == 0) return a + n;
	else {
		if (a > n) return gcd(a - n, n);
		else  return gcd(a, n - a);
	}
}

/*
Hàm tìm nghịch đảo modulo với phương trình đồng dư: ay % n = b ( áp dụng Thuật toán Euclid mở rộng)
Các tham số truyền vào: r = n ; r1 = a; y1 = 1; y = 0
Tồn tại nghịch đảo khi thỏa mãn GCD(a,n) = 1
*/
int decryption(int r, int r1, int y1, int y) {
	int r2 = r % r1;
	int q = r / r1;
	if (r2 == 0) return (y1 > 0 ? y1 : y1 + 26);
	else {
		return decryption(r1, r2, y - q * y1, y1);
	}
}

//Hàm chuyển đổi từ ký tự sang kiểu dữ liệu tương ứng với ký tự trong bảng mã ascii
int *arrayAsciiOfString(char* a, int sizeOfChar) {

	int *b = new int[sizeOfChar - 1];

	for (int i = 0; i < sizeOfChar - 1; i++) {

		if ((int)a[i] < 90 || (int)a[i] > 122) 	b[i] = (int)a[i];

		else b[i] = (int)a[i] - 32;
	}

	return b;
	delete[]b;
}

//mã hóa chuổi ký tự theo mã affine
char *cryptography(int *arrAscii, int sizeOfChar, int a, int b) {

	char *arrChar = new char[sizeOfChar];

	for (int i = 0; i < sizeOfChar - 1 ; i++) {

		//if (arrAscii[i] >= 48 && arrAscii[i] <= 57) {

		

		if (arrAscii[i] == 32) arrChar[i] = 32;

		else {
			int temp = (a*(arrAscii[i] - 65) + b) % 26;

			arrChar[i] = (char)((temp + 65));
		}

	}
	return arrChar;
	delete[]arrChar;
}

//giải mã ký tự theo mã affine
char *decryptography(char *arrChar, int sizeOfChar, int a, int b) {
	char *arr = new char[sizeOfChar];
	int revertA = decryption(26, a, 1, 0);

	for (int i = 0; i < sizeOfChar - 1; i++) {

		if (arrChar[i] == 32) arr[i] = 32;
		else {
			int temp = ((revertA)*(((int)arrChar[i] - 65) - b)) / 26;

			temp = (temp < 0 ? temp - 1 : temp);

			temp = (revertA)*(((int)arrChar[i] - 65) - b) - 26 * temp;

			arr[i] = (char)(temp + 65);
		}

	}

	return arr;
	delete[]arr;
}