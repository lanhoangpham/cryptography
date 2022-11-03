#include "RunKeyCipher.h"

int main() {
	char key[] = "cipher";

	char message[] = "Cryptography";

	int *int_key = arrayAsciiOfString(key, sizeof(key));

	char *c = runKeyCipher(message, key);
	
	cout << stringLength(key);
	for (int i = 0; i < stringLength(c); i++) {
		cout << c[i];
	}
}