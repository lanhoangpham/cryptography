#include"myLibrary.h"

int main() {
	//giá trị a và b trong phương trình đồng dư
	int a = 17, b1 = 20;

	//bản tin muốn mã hóa
	char message[] = "Toi la Pham Hoang Lan xin chao cac ban"; // "abcdefghijklmnopqrstuvwxyz";

	//chuoi ky tu duoc ma hoa ra ban ma ascii
	int *b = arrayAsciiOfString(message, sizeof(message));

	//ma hoa
	cout << "Chuoi duoc ma hoa: ";
	char *c = cryptography(b, sizeof(message), a, b1);

	//hien thi xau ky tu
	for (int i = 0; i < sizeof(message) - 1; i++) {
		cout << c[i];
	}
	cout << endl;

	//giaiMaXau
	cout << "Chuoi sau giai ma: ";
	char *d = decryptography(c, sizeof(message), a, b1);

	//hien thi xau
	for (int i = 0; i < sizeof(message) - 1; i++) {
		cout << d[i];
	}

	return 0;
}