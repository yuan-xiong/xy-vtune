#include <iostream>
#include <signal.h>

#if 0
	// https://blog.csdn.net/Mr_zhangsq/article/details/110852363
	#define xylog(fmt, args...) printf("%s[%4d]: %s "#fmt"\n",__FILE__,__LINE__,__func__,##args);
#else
	// https://blog.csdn.net/sunny04/article/details/47144863
	// font:30~39, background:40~49
	#define DBG_FG_BLACK	"\033[30m"
	#define DBG_FG_RED		"\033[31m"
	#define DBG_FG_GREEN	"\033[32m"
	#define DBG_FG_YELLOW	"\033[33m"
	#define DBG_FG_BLUE		"\033[34m"
	#define DBG_FG_VIOLET	"\033[35m"
	#define DBG_FG_VIRDIAN	"\033[36m"
	#define DBG_FG_WHITE	"\033[37m"
	#define DBG_BG_BLACK	"\033[40m"
	#define DBG_BG_RED		"\033[41m"
	#define DBG_BG_GREEN	"\033[42m"
	#define DBG_BG_YELLOW	"\033[43m"
	#define DBG_BG_BLUE		"\033[44m"
	#define DBG_BG_VIOLET	"\033[45m"
	#define DBG_BG_VIRDIAN	"\033[46m"
	#define DBG_BG_WHITE	"\033[47m"
	#define DBG_END			"\033[0m"

	#define xylog(fmt, args...)	\
		printf("%s%s[%-5d]: %s " #fmt "%s\n", DBG_BG_BLUE, __FILE__,__LINE__,__func__,##args, DBG_END);
#endif

// https://blog.csdn.net/kehyuanyu/article/details/25830723
//#define RET_IP(depth) __builtin_return_address(depth)
void print_stack(std::string func, int depth) {
	printf("%s[%4d]: %s(%2d):\t%p\n", __FILE__, __LINE__, func.c_str(), 0, __builtin_return_address(0));
	printf("%s[%4d]: %s(%2d):\t%p\n", __FILE__, __LINE__, func.c_str(), 1, __builtin_return_address(1));
	printf("%s[%4d]: %s(%2d):\t%p\n", __FILE__, __LINE__, func.c_str(), 2, __builtin_return_address(2));

	for(int i=0; i<depth; ++i) {
		// failed
		//printf("%s[%4d]: %s(%2d):\t%p\n", __FILE__, __LINE__, __func__, i, RET_IP(i));
	}
}

void sigfunc(int signo) {
	printf("%s[%4d]: %s signo:%d\n", __FILE__, __LINE__, __func__, signo);
	print_stack(__func__, 4);
	exit(-1);
}

void test_d() {
	print_stack(__func__, 3);
}

void test_c() {
	print_stack(__func__, 2);

	test_d();
}

void test_b() {
	print_stack(__func__, 1);

	test_c();
}

void test_a() {
	print_stack(__func__, 1);

	test_b();
}

int main() {
	xylog();
	print_stack(__func__, 1);

	signal(SIGINT, sigfunc);

	test_a();
	return 0;
}
