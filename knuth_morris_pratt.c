#include <stdlib.h>
#include <stdio.h>
#include "knuth_morris_pratt.h"


char* my_strstr(char* haystack, const char* needle) {

	int lenght = 0;
	while (*(needle + lenght) != '\0') {
		lenght++;
	}

	int* arr_pi = malloc(sizeof(int) * lenght);

	search_arr_pi(needle, arr_pi, lenght);

	int lenght_image = 0;
	while (*(haystack + lenght_image) != '\0') {
		lenght_image++;
	}

	if (lenght > lenght_image) {
		free(arr_pi);
		return NULL;
	}

	int i = 0, j = 0;
	int is_ok = 1;

	while (is_ok == 1) {
		if (haystack[i] == needle[j]) {
			i++;
			j++;
			if (j == lenght) {
				is_ok = 0;
				free(arr_pi);
				return haystack + i - j;
			}
		}
		else {
			if (j > 0) {
				j = arr_pi[j - 1];
			} 
			else {
				i++;
				if (i == lenght_image) {
					is_ok = 0;
					free(arr_pi);
					return NULL;
				}
			}
		}
	}
}

void search_arr_pi(const char* needle, int* arr_pi, int lenght) {
	*arr_pi = 0;

	int i = 1, j = 0;

	while (i != lenght) {
		if (needle[i] != needle[j]) {
			if (j == 0) {
				*(arr_pi + i) = 0;
				i++;
			}
			else {
				j = *(arr_pi + j - 1);
			}
		}
		else {
			*(arr_pi + i) = j + 1;
			i++;
			j++;
		}
	}
}