//подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//главная функция программы
int main()
//объявление переменных
{
	uid_t userid;
	gid_t groupid;
//системный вызов getuid()
	userid = getuid();
//системный вызов getgid()
	groupid = getgid();
	printf("Ид. пользователя: %d\n", userid);
	printf("Ид. группы пользователя: %d\n", groupid);
//возврат значения 0 из главной функции
	return 0;
}

