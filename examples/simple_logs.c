#include <ezlog.h>

int main(void)
{
	EZLOGD("This is Debug\n");
	EZLOGI("This is Info\n");
	EZLOGW("This is Warning\n");
	EZLOGE("This is Error\n");

	return 0;
}
