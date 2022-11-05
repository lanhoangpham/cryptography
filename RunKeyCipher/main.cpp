#include "RunKeyCipher.h"

int main() {
    //xâu từ khóa
	char key[] = "cipher";
    //xâu message
	char message[] = "XinChaoQuynhHuong";
	//in ra màn hình chuỗi trước khi mã hóa
	cout << "Chuoi truoc ma hoa: " ;
	for ( int i = 0; i <stringLength(message); i++) cout << message[i];
    //xâu lưu trữ ký tự sau mã hóa
	char *c = cryptographyRunKeyCipher(message, key);
 	//in ra màn hình kết quả message sau mã hóa theo hệ mật run key cipher
 	cout << "Chuoi sau ma hoa: " ;
	for (int i = 0; i < stringLength(message) + 1; i++)  cout << c[i];
	cout << endl;
	//xâu lưu trữ ký tự sau giải mã hóa theo hệ mật run key cipher
	char *d = decryptographyRunKeyCipher(c, key);
	//in ra màn hình kết quả
	cout << "Chuoi sau giai ma: ";
	for ( int i = 0; i < stringLength(message); i++){
	    cout << d[i];
	}
	return 0;
}