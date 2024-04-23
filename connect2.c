#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //библиотека для управления файлами
#include <fcntl.h>
int main()
{
	int fd;
	size_t size;
//инициализируем массив символов чтобы туда записать информацию из файла
	char string[17];
//открываем файл на чтение
	if((fd = open("file1.txt", O_RDONLY))<0)
	{
		printf("Ошибка при открытии файла на чтение\n");
		exit(-1);
	}
//чтение информации с файла
	size = read(fd, string, 17);
//проверка количества прочитанных байт
	if (size != 17)
	{
		printf("Не удалось прочитать всю строку из файла\n");
		exit(-1);
	}
	printf("%s\n", string); //вывод содержимого файла
//закрытие файла
        if (close(fd)<0)
        {
                printf("Не удалось закрыть файл\n");
                exit(-1);
        }

	return 0;
}
