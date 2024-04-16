//подключение библиотек
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int result1;
	pid_t procid, parentid; //идентификаторы процессов
	pid_t result; //результат системного вызова fork()
	int a = 0; //переменная для проверки работы процесса родителя и процесса ребенка
	result = fork();
	if (result < 0){
		printf("Ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result == 0){
		a = a + 1;
		procid = getpid(); //получение идентификатора текущего поцесса
		parentid = getppid(); //получение идентификатора родительского процесса
		printf("Ид. процесса: %d, ид. родителя %d, значение переменной a: %d\n", procid, parentid, a);
		//запускаем в дочернем процессе программу cat
		result1 = execle("/bin/cat", "/bin/cat", "otchet_16_04.txt", 0, envp);
        	printf("Ошибка при выполнении ситемного вызова execle()\n");
        	exit(-1);
	}
	else {
		a = a + 555;
		procid = getpid(); //получение идентификатора текущего поцесса
        	parentid = getppid(); //получение идентификатора родительского процесса
        	printf("Ид. процесса: %d, ид. родителя %d, значение переменной a: %d\n", procid, parentid, a);
	}
	return 0;    //никогда не выполняется
}

