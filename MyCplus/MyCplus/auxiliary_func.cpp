#include <stdint.h>
#include <iostream>
#include <string>
#include "auxiliary_func.h"

int numk[10] = { 23,21,5,45,32,89,12,78,60,34 };
void Array_Sorted(int *num) {
	int temp_max = 0;
	std::cout << "numk_size:" << sizeof(numk) / sizeof(int) << std::endl;

	for (int i = 0; i < sizeof(numk) / sizeof(int) - 1; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (numk[j] > numk[i]) {
				temp_max = numk[j];
				numk[j] = numk[i];
				numk[i] = temp_max;
			}
		}

	}
	for (int i = 0; i < 10; i++) {
		std::cout << "numk:" << numk[i] << std::endl;
	}
}

