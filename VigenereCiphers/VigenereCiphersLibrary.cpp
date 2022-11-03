#include "VigenereCiphersLibrary.h"


int *arrayAsciiOfString(char* a, int sizeOfChar) {
	//cấp phát bộ nhớ cho chuỗi mới lưu trữ dữ liệu kiểu int sau khi được chuyển đổi
	int *b = new int[sizeOfChar - 1];

	//chuyển đổi chuỗi sang kiểu int theo bảng mã ascii
	for (int i = 0; i < sizeOfChar - 1; i++) {
		//giữ nguyên các ký tự in hoa
		if ((int)a[i] >= 65 && (int)a[i] <= 90) b[i] = (int)a[i];
		//chuyển các ký tự thường thành các ký tự in hoa
		else b[i] = (int)a[i] - 32;
	}
	//trả về chuỗi đã chuyển đổi
	return b;
	//xóa bộ nhớ
	delete[]b;
}

char *cryptographyVigenreCiphers(char *message, char *key, int sizeOfMessage, int sizeOfKey) {

	//cấp phát bộ nhớ cho chuỗi mới chứa đoạn message sau mã hóa
	char *messageAfterCryption = new char[sizeOfMessage + 1];

	//chuyển đổi chuỗi key sang kiểu int theo bảng mã ascii
	int *int_key = arrayAsciiOfString(key, sizeOfKey + 1);

	//chuyển đổi chuỗi message sang kiểu int theo bảng mã ascii
	int *int_message = arrayAsciiOfString(message, sizeOfMessage );

	//mã hóa theo mã Vigenere
	for (int i = 0; i < sizeOfMessage - 1 ; i++) {

		int temp = int_message[i] + (int_key[i % sizeOfKey] - 65);

		temp = temp > 90 ? temp - 25 : temp;

		messageAfterCryption[i] = (char)(temp);	
	}
	cout << endl;

	//trả về chuỗi sau mã hóa
	return messageAfterCryption;
	//xóa bộ nhớ đã cấp phát
	delete[]messageAfterCryption;
	
}

char *decryptographyVigenreCiphers(char *message, char *key, int sizeOfMessage, int sizeOfKey) {
	//cấp phát bộ nhớ cho chuỗi mới chứa đoạn message sau mã hóa
	char *messageAfterDeCryption = new char[sizeOfMessage + 1];

	//chuyển đổi chuỗi key sang kiểu int theo bảng mã ascii
	int *int_key = arrayAsciiOfString(key, sizeOfKey + 1);

	//chuyển đổi chuỗi message sang kiểu int theo bảng mã ascii
	int *int_message = arrayAsciiOfString(message, sizeOfMessage);

	for (int i = 0; i < sizeOfMessage; i++) {

		int temp = int_message[i] - (int_key[i % sizeOfKey] - 65);

		temp = temp < 65 ? 90 - (65 - temp) : temp;

		messageAfterDeCryption[i] = (char)(temp);
	}

	return messageAfterDeCryption;
	delete[]messageAfterDeCryption;
}