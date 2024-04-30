#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> //без этой библиотеки ругается на exit

int main()
{
	int fd1[2], fd2[2];
	pid_t result;
	size_t size;
	char string1[] = "Hello, child!", string2[] = "Hello, parent!";
	char resstring1[13], resstring2[14];
//попытка создания pipe
	if (pipe(fd1)<0)
	{
		printf("Не получилось создать pipe()\n");
		exit(-1);
	}
	if (pipe(fd2)<0)
        {
                printf("Не получилось создать pipe()\n");
                exit(-1);
        }

	result = fork();
	if(result<0)
	{
		printf("Ошибка выполнения fork()\n");
	}
	else if (result>0)
	{
		if (close(fd1[0])<0)
		{
			printf("Ошибка при закрыти pipe для чтения\n");
			exit(-1);
		}
		if (close(fd2[1])<0)
                {
                        printf("Ошибка при закрыти pipe на запись\n");
                        exit(-1);
                }
		size = write(fd1[1], string1, 13);
		if(size != 13) //если записалось меньшее кол-во байт - сообщается об ошибке
		{
			printf("Не получается записать строку\n");
			exit(-1);
		}
		printf("Процесс-родитель записал информацию в pipe\n");
		size = read(fd2[0], resstring2, 14);
		if(size!=14)
                {
                        printf("Не получается прочесть строку\n");
                        exit(-1);
                }
                printf("Информация от дочернего процесса: %s\n", resstring2);
                if (close(fd1[1])<0)
                {
                        printf("не получилось закрыть исходящий поток\n");
                        exit(-1);
                }
                if (close(fd2[0])<0)
                {
                        printf("Не получилось закрыть входящий поток\n");
                        exit(-1);
                }

	}
	else
	{
		if (close(fd1[1])<0)
                {
                        printf("не получилось закрыть исходящий поток\n");
                        exit(-1);
                }
		if (close(fd2[0])<0)
                {
                        printf("не получилось закрыть dходящий поток\n");
                        exit(-1);
                }

		size = read(fd1[0], resstring1, 13);
		if(size!=13)
		{
			printf("Не получается прочесть строку\n");
			exit(-1);
		}
		printf("%s\n", resstring1);
		size = write(fd2[1], string2, 14);
                if(size != 14) //если записалось меньшее кол-во байт - сообщается об ошибке
                {
                        printf("Не получается записать строку\n");
                        exit(-1);
                }
		printf("Процесс-ребенок записал информацию в pipe\n");
		if (close(fd1[0])<0)
                {
                        printf("Не получилось закрыть входящий поток\n");
                        exit(-1);
                }

		if (close(fd2[1])<0)
		{
			printf("Не получилось закрыть исходящий поток\n");
			exit(-1);
		}
	}
	return 0;
}

