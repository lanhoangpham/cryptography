#include "RunKeyCipher.h"

/*
*   brief:              Hàm nối hai xâu ký tự
*   param chuoi1:       Xâu thứ nhất
*   param chuoi2:       Xâu thứ hai
*   return:             Xâu ký tự sau khi nối
*/

char *noiChuoi(char *chuoi1, char *chuoi2) {
    //độ dài xâu mới
	int length = stringLength(chuoi2) + stringLength(chuoi1);
    //cấp phát bộ nhớ lưu trữ xâu mới
	char *newString = new char[length + 1];
    //duyệt 2 xâu
	for (int i = 0; i < length; i++) {
        //nối 2 xâu
		if (i < stringLength(chuoi1)) newString[i] = chuoi1[i];
		else newString[i] = chuoi2[i - stringLength(chuoi1)];
	}
	newString[length + 1] = '\0';
    //trả về con trỏ trỏ tới địa chỉ đầu của xâu 
	return newString;
}

/*
*   brief:              Hàm tìm độ dài xâu
*   param arr:          Xâu cần đếm độ dài
*   return:             độ dài xâu
*/
int stringLength(char *arr) {
	int i = 0;
	while (arr[i] != '\0') {
		i++;
	}
	return i;
}

//chuyển xâu ký tự thành mảng số nguyên theo bảng mã ascii
/*
*   brief:              Hàm chuyển xâu ký tự thành mảng số nguyên theo bảng mã ascii
*   param a:            Xâu cần chuyển đổi
*   param sizeOfChar:   độ dài xâu
*   return:             Mảng số nguyên sau chuyển đổi
*/
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
}

/*
*   brief:              Hàm mã hóa xâu theo hệ mật Vigenre
*   param message:      xâu cần mã hóa
*   param key:          Khóa 
*   length:             Vị trí ký tự cần mã hóa tiếp theo trong xâu
*   return:             xâu đã mã hóa
*/

char *cryptographyVigenreCiphers(char *message, char *key, int length) {
    //độ dài của message
	int sizeOfMessage = stringLength(message);
	//độ dài khóa
	int sizeOfKey = stringLength(key);
	//cấp phát bộ nhớ cho chuỗi mới chứa đoạn message sau mã hóa
	char *messageAfterCryption = new char[sizeOfKey + 1];
	//chuyển đổi chuỗi key sang kiểu int theo bảng mã ascii
	int *int_key = arrayAsciiOfString(key, sizeOfKey + 1);
	//chuyển đổi chuỗi message sang kiểu int theo bảng mã ascii
	int *int_message = arrayAsciiOfString(message, sizeOfMessage + 1);
	//số lượng ký tự chuẩn bị được mã hóa
	int temp1 = sizeOfMessage - length > sizeOfKey ?  sizeOfKey  : sizeOfMessage - length;
	//mã hóa theo mã Vigenere
	for (int i = length; i < length + temp1 ; i++) {
        //chỉ số của ký tự làm khóa 
        int key_index = i%sizeOfKey;
        //mã hóa ký tự
		int temp = int_message[i] + (int_key[key_index] - 65);
		//cout << int_key[key_index] << "\t" << key << " " << endl;
        //kiểm tra nếu ký tự vượt quá bảng ký tự mã hóa
		temp = temp >= 90 ? temp - 25 : temp;
        //lưu ký tự dưới dạng char
		messageAfterCryption[i%sizeOfKey] = (char)(temp);
	}
	cout << endl;
	//gán ký tự kết thức xâu
    messageAfterCryption[sizeOfKey + 1] = '\0';
	//trả về chuỗi sau mã hóa
	return messageAfterCryption;

}

/*
*   brief:              Hàm mã hóa xâu theo hệ mât Run key cipher
*   param message:      xâu cần mã hóa
*   param key:          Khóa 
*   return:             xâu đã mã hóa
*/
char *cryptographyRunKeyCipher(char *message, char *key) {
    //đọ dài của key
    int keyLength = stringLength(key);
    //độ dài của message
	int messageLength = stringLength(message);
    //cấp phát bộ nhớ cho xâu mới chứa message sau mã hóa
	char* messageAfterCryption = new char[messageLength + 1];
	//cấp phát bộ nhớ lưu trữ khóa sau mỗi lần thay khóa
	char *c = new char[keyLength + 1];
	//mã hóa xâu
	int i = 0;
	while(i <= messageLength + 1){
	    // lần mã hóa đầu tiên sẽ dùng từ khóa ban đầu, từ những lần mã hóa tiếp theo sử dụng các ký tự tiếp theo trong message
	    for ( int j = 0; j < keyLength; j++) i == 0 ? c[j] = key[j]: c[j] ==  message[i + j];
        //sử dụng các ký tự tiếp theo của message làm khóa tiếp theo
		key = cryptographyVigenreCiphers(message, c , i);
        //Nối chuỗi đã mã hóa trước đó với chuỗi vừa được mã hóa
		messageAfterCryption = noiChuoi( messageAfterCryption, key);
        //Đánh số phần tử tiếp theo trong message sẽ được mã hóa
		i = keyLength + i ;
	}
    //trả về giá trị của message sau mã hóa
	return messageAfterCryption;


}

/*
*   brief:              Hàm giải mã hóa xâu theo hệ mật Vigenre
*   param message:      xâu cần mã hóa
*   param key:          Khóa 
*   length:             Vị trí ký tự cần mã hóa tiếp theo trong xâu
*   return:             xâu đã mã hóa
*/

char *decryptographyVigenreCiphers(char *message, char *key, int length){
    //độ dài của message
	int sizeOfMessage = stringLength(message);
	//độ dài khóa
	int sizeOfKey = stringLength(key);
	//cấp phát bộ nhớ cho chuỗi mới chứa đoạn message sau mã hóa
	char *messageAfterCryption = new char[sizeOfKey + 1];
	//chuyển đổi chuỗi key sang kiểu int theo bảng mã ascii
	int *int_key = arrayAsciiOfString(key, sizeOfKey + 1);
	//chuyển đổi chuỗi message sang kiểu int theo bảng mã ascii
	int *int_message = arrayAsciiOfString(message, sizeOfMessage + 1);
	//số lượng ký tự chuẩn bị được mã hóa
	int temp1 = sizeOfMessage - length > sizeOfKey ?  sizeOfKey  : sizeOfMessage - length;
	//mã hóa theo mã Vigenere
	for (int i = length; i < length + temp1 ; i++) {
        //chỉ số của ký tự làm khóa 
        int key_index = i%sizeOfKey;
        //mã hóa ký tự
		int temp = int_message[i] - (int_key[key_index] - 65);
        //kiểm tra nếu ký tự vượt quá bảng ký tự mã hóa
		temp = temp < 65 ? 90 - (65 - temp) : temp;
        //lưu ký tự dưới dạng char
		messageAfterCryption[i%sizeOfKey] = (char)(temp);
		//cout << key[key_index] << "   " << int_key[key_index] << '\t' << message[i] << "   " << int_message[i] << '\t' <<messageAfterCryption[i%sizeOfKey] << endl;
	}
	cout << endl;
	//gán ký tự kết thức xâu
    messageAfterCryption[sizeOfKey + 1] = '\0';
	//trả về chuỗi sau mã hóa
	return messageAfterCryption;

}


/*
*   brief:              Hàm giải mã hóa xâu theo hệ mât Run key cipher
*   param message:      xâu cần giải mã hóa
*   param key:          Khóa 
*   return:             xâu đã mã hóa
*/

char *decryptographyRunKeyCipher(char *message, char *key){
    //đọ dài của key
    int keyLength = stringLength(key);
    //độ dài của message
	int messageLength = stringLength(message);
    //cấp phát bộ nhớ cho xâu mới chứa message sau giải mã hóa
	char* messageAfterCryption = new char[messageLength + 1];
	//cấp phát bộ nhớ lưu trữ khóa sau mỗi lần thay khóa
	char *c = new char[keyLength + 1];
	//giải mã hóa xâu
	int i = 0;
	while(i <= messageLength + 1){
	    // lần mã hóa đầu tiên sẽ dùng từ khóa ban đầu, từ những lần mã hóa tiếp theo sử dụng các ký tự tiếp theo trong message
	    for ( int j = 0; j < keyLength; j++)  i == 0 ? c[j] = key[j]: c[j] ==  message[i + j];
        //sử dụng các ký tự đã được mã hóa trước đó làm khóa tiếp theo
		key = decryptographyVigenreCiphers(message, c, i);
        //Nối chuỗi đã mã hóa trước đó với chuỗi vừa được mã hóa
		messageAfterCryption = noiChuoi( messageAfterCryption, key);
        //Đánh số phần tử tiếp theo trong message sẽ được mã hóa
		i = keyLength + i ;
	}
    //trả về giá trị của message sau mã hóa
	return messageAfterCryption;

}






















