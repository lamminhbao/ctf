/* Author: bo8 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef struct Info {
    char name[32];
    int age;
} Info;

void read_file(const char *file_path) {
    FILE *pFile;
    long lSize;
    char *buffer;
    size_t result;

    pFile = fopen ( file_path , "rb" );
    if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);

    // allocate memory to contain the whole file:
    buffer = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

    // copy the file into the buffer:
    result = fread (buffer,1,lSize,pFile);
    if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

    /* the whole file is now loaded in the memory buffer. */
    printf("%s", buffer);

    // terminate
    fclose (pFile);
    free (buffer);
    return ;
}

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

char talkable(char *s) {
    int n = strlen(s);
    int i;
    for (i=0; i<n; i++) {
        if (!isprint(s[i]))
            return 0;
    }
    return 1;
}

char auth(Info *info) {
    if (info != NULL) {
        if (talkable(info->name)) 
            printf("- Hello %s \\m/\n", info->name);
        else 
            printf("- Hello baby.\n");

        if (strcmp(info->name, "captain") == 0)
            return 1;
    }
    return 0;
}

void security_check(int age) {
    char *buf;
    Info info;


    if (age >= 3) {
        printf("- Give me your name to pass the entrance\n");
        buf = (char *)malloc(32);
        printf("> ");
        read_str(buf, 32);

        if (strcmp(buf, "captain") == 0) {
            printf("- Permission denied\n");
            return ;
        }
        else {
            strcpy(info.name, buf);
            info.age = age;
            free(buf);
        }
    }

    if (auth(&info)) {
        read_file("/home/security_checker/flag");
    }
    else {
        printf("- Please, go ...\n");
    }
}

void talk(int age) {
    char buf[128];
    char yn[2];

    if (age < 3) {
        printf("Hello baby. Baby can\'t talk.\n");
        return ;
    }

    do {
        printf("> ");
        read_str(buf, 128);
        printf("- Oke, I noted.\n");
        printf("- Anything else? (y/n) ");
        read_str(yn, 2);
    } while (yn[0] == 'y');
}

void menu() {
    printf("1. Talk\n");
    printf("2. Bye\n");
    printf("3. Secutiry check\n");
}

void main() {
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

    int age;
    printf("Your age (3+): ");
    age = read_num();

    while (1) {
        menu();
        switch (read_num()) {
            case 1:
                talk(age);
                break;
            case 2:
                return ;
            default:
                security_check(age);
                return ;
        }
    }
}
