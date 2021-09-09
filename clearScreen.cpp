#include <stdio.h>
#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
const char* os = "Windows";
#else
#ifdef __linux
const char* os = "Linux";
#else
const char* os = "Unknown";
#endif
#endif

void clearScreen() {
	if (os == "Windows") {
		system("cls");
	}
	else if (os == "Linux") {
		system("clear");
	}
}
