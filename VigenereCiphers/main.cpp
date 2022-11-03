#include "VigenereCiphersLibrary.h"


/*
Ý tưởng:
	- Sử dụng 1 loại mã Caesar khác nhau dựa trên các ký tự của một từ khóa
	- Dễ hiểu và dễ thực hiện
Các bước thực hiện:
	- Biến đổi chữ cái A, B,..., Z thành các ký tự 0, 1, 2...25
	- Khóa là một chuỗi các ký tự có độ dài m
	- Thông điệp được chia sẻ thành các khối có độ dài m . Mỗi lần má hóa sẽ thực hiện biến đổi đồng thời m ký tự
Mô tả hệ mã:
	Cho m là 1 số nguyên dương. Ta định nghĩa P = C = K. với khóa k = (k1, k2, ..km) được xác định:
		ek( x1, x2, x3,...,xm) = ( x1 + k1, x2 + k2, x3 + k3, ..., xm + km)
		và dk(y1, y1, ..ym ) = (y1 - k1, y2 - k2,... ym - km)
	Khi cho m lớn thì việc thám mã sẽ khó khăn.
Các ký tự áp dụng: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/

int main() {

	char key[] = "cipher";

	//bản tin muốn mã hóa
	char message[] = /*"XinChaoHuong";//*/ "Cryptography";

	
	char* c = cryptographyVigenreCiphers(message, key, sizeof(message), sizeof(key) - 1);
	
	//mã hóa xâu bằng mã Vigenere
	cout << "Chuoi sau ma hoa: ";
	for (int i = 0; i < sizeof(message) - 1 ; i++) {
		cout << c[i];
	}
	cout << endl;
	
	//giải mã hóa xâu bằng mã Vigenere
	cout << "Chuoi sau giai ma: ";
	char *d = decryptographyVigenreCiphers(c, key, sizeof(message), sizeof(key) - 1);
	for (int i = 0; i < sizeof(message) -1 ; i++) {
		cout << d[i];
	}
	cout << endl;
	system("pause");
	return 0;

}
