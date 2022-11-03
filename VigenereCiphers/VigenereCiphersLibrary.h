#pragma once
#include <iostream>


using namespace std;

int *arrayAsciiOfString(char* a, int sizeOfChar);

char *cryptographyVigenreCiphers(char *message, char *key, int sizeOfMessage, int sizeOfKey);

char *decryptographyVigenreCiphers(char *message, char *key, int sizeOfMessage, int sizeOfKey);