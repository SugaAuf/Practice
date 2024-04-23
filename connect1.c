#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//подключение библиотеки для управления файлами
#include <fcntl.h>
int main()
{
	int fd; //файловый дескриптор
	size_t size; //размер строки в байтах
	char string[]="Group 3.120.2.21";
//открытие файла на запись, если не существует, то он создан с правами доступа 0666
	if((fd = open("file1.txt", O_WRONLY|O_CREAT, 0666))<0)
	{
		printf("Ошибка при открытии файла на запись\n");
		exit(-1);
	}
//чтение из файла в строку
	size = write(fd, string, 17);
	if (size != 17)
	{
		printf("Не удалось записать всю строку в файл\n");
		exit(-1);
	}
//закрытие файла
        if (close(fd)<0)
        {
                printf("Не удалось закрыть файл\n");
                exit(-1);
        }

	return 0;
}
