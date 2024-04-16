//подключение библиотек
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int result;
	//запуск программы cat с аргументом otchet_16_04.txt
	result = execle("/bin/cat", "/bin/cat", "otchet_16_04.txt", 0, envp);
	//printf выполняется только в случае ошибк вызова execle()
	printf("Ошибка при выполнении ситемного вызова execle()\n");
	exit(-1);
	return 0;    //никогда не выполняется
}

