#include <stdio.h>
#include "knuth_morris_pratt.h"


int main(void) {

	char arr[] = "лилилось лилиласьъхзщшгпрдлорпывалмодывжтосфвылдствыа воытаьдвсыгвматыф тывло стьыфв тмыфвь омфывтш осфы лвмтфыгвьсждыфв оаьтывф гоыва мнгфшсжфщьосйузщшьвыф вдл ьымрыщвашгосфвгнпафтьвсылвптырдаывослфыов рафывьсафдыоаослфвбьслоа";
	char arr_image[] = "нпафтьв";

	int lenght = 0;
	while (arr_image[lenght] != '\0') {
		lenght++;
	}

	char* result = my_strstr(arr, arr_image);

	if (result == NULL) {
		printf("Подстрока не найдена\n");
		return 1;
	}
	else {
		printf("Подстрока найдена\n");
	}

	for (int i = 0; i < lenght; i++) {
		printf("%c", result[i]);
	}
	return 0;
}