// gcc -no-pie -fno-stack-protector pwn2.c -o pwn2
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define INIT_MONEY 1000000
#define MAX_SIZE 1000

void read_str(char *buf, unsigned int size){
    int ret;
    ret = read(0, buf, size);

    if (ret <= 0) {
        puts("read error");
        exit(1);
    }

    buf[ret-1] = '\x00';
}

int read_num() {
    char buf[64];
    read_str(buf, 64);
    return atoi(buf);
}

void play(int money) {
	char buf[MAX_SIZE];
	printf("Let\'s play!\n");
	printf("%p\n", printf);
	read_str(buf, money/1000);
}

void main() {
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

	printf("May ATM - Bank XYZ\n");	
	int money = INIT_MONEY;
	int n1, n2;
	char c[2];
	while (1) {
		printf("Tai khoan con %d vnd\nNhap so tien: ", money);
		n1 = read_num();
		printf("Quyet dinh chac chua?\nNhap so tien muon rut them: ");
		n2 = read_num();
		if (n1 >= 0 && n2 >= 0 && n1 + n2 < money) {
			money = money - (n1 + n2);
			printf("Ban da rut thanh cong %d vnd va %d vnd, tk con %d vnd\n", n1, n2, money);
		}
		else
			printf("So tien trong tai khoan khong du, hoac ban nhap so tien khong hop le\n");
		printf("Tiep tuc giao dich? (y/n) ");
		read_str(c, 2);
		if (c[0] == 'n')
			break;
	}
	play(money);
}
