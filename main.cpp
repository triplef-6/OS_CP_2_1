#include <iostream>
#include "apue.h"
#include <fcntl.h>


char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
    int fd; // дискриптор файла file.hole

    // FILE_MODE = (S_IRUSR = пользователь имеет право чтения | S_IWUSR = пользователь имеет право записи | S_IRGRP = группа имеет права чтения | S_IROTH = все прочие имеют права чтения)
    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("ошибка вызова creat");
    }

    if (write(fd, buf1, 10) != 10) {
        err_sys("ошибка записи buf1");
    }
    // текущая позиция = 10(10)

    // SEEK_SET = смещения от начала файла
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("ошибка вызова lseek");
    }
    // текущая позиция = 16384(10) = 40000(8)

    if (write(fd, buf2, 10) != 10) {
        err_sys("ошибка записи buf2");
    }

    exit(0);
}

void err_sys(const char *s, ...) {
    std::cerr << s;
}
