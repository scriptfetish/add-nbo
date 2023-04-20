#include <arpa/inet.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void printer() {
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample : add-nbo a.bin c.bin\n");
}

uint32_t read_int(char *fileName) {
        FILE *fp = fopen(fileName, "rb");
        if (fp == nullptr) {
                fprintf(stderr, "fopen returns null %s\n", strerror(errno));
                exit(EXIT_FAILURE);
        }
        uint32_t n;
        size_t readLen = fread(&n, 1, sizeof(n), fp);
        if (readLen != sizeof(n)) {
                fprintf(stderr, "fread return %lu\n", readLen);
                exit(EXIT_FAILURE);
        }
        n = ntohl(n);
        fclose(fp);
        return n;
}

uint32_t hap(uint32_t n1, uint32_t n2) {
    return n1 + n2;
}

int main(int argc, char *argv[]) {
        if (argc != 3) {
                printer();
                exit(EXIT_FAILURE);
        }
        uint32_t n1 = read_int(argv[1]);
        uint32_t n2 = read_int(argv[2]);
        uint32_t n3 = hap(n1, n2);
        printf("%d(0x%x) + %d(0x%x) = %d(0x5dc)\n", n1, n1, n2, n2, n3);
}
