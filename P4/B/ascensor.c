#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void escribir (int num) {
	
	
	int fd1 = open("/dev/leds", O_WRONLY);
	
	switch(num) {
	case 0:
		write(fd1, "\n", 4);
		sleep(1);
		break;
	case 1:
		write(fd1, "3", 1);
		sleep(1);
		break;
	case 2:
		write(fd1, "2", 1);
		sleep(1);
		break;
	case 3:
		write(fd1, "23", 2);
		sleep(1);
		break;
	case 4:
		write(fd1, "1", 1);
		sleep(1);
		break;
	case 5:
		write(fd1, "13", 2);
		sleep(1);
		break;
	case 6:
		write(fd1, "12", 2);
		sleep(1);
		break;
	case 7:
		write(fd1, "123", 3);
		sleep(1);
		break;
	//defalut:
		//write(fd1, "0", 1);
		//break;
		
	}
	
	close(fd1);
}
int main(int argc, char *argv[]) {
	
	int act = 0, op = 0, i;
	
	//int fd1;
	//fd1 = open("/dev/leds", O_WRONLY);
	//write(fd1, "0", 1);
	
	printf("Estás en la planta 0 dónde quieres ir (MAX 7): ");
	scanf("%19d", &op);
	
	while (op != -1) {
		
		
		if (op > 7 || op == act ) {
			printf("Acción no disponible");
		} else if (op > act) {
			for (i = act; i <= op; i++) {
				printf("iieeeeeeeii: %d \n", i);
				escribir(i);
				act = op;
			 }
		} else {
			for (i = act; i >= op; i--) {
				printf("iiiiiiiiiiiiii: %d \n", i);
				escribir(i);
				act = op;
			}
		}
		
			
		
		printf("Estás en la planta %d dónde quieres ir (MAX 7): ", act);
		scanf("%19d", &op);
		
	}
	
	return 0;
}
