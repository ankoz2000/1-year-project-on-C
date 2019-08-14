#ifndef _MYINF_H_
#define _MYINF_H_
#include <iostream>
#include <time.h>
using namespace std;
struct my_s{
	int id;
	char marka[20];
	char nomer[12];
	char name[30];
	char mobnomer[16];
	time_t datin;//char datin[20];
	time_t datout;//char datout[20];
	//int money;
};

typedef my_s info;
ostream& operator<<(std::ostream& os, const info& val);
istream& operator>>(std::istream& is, info& val);

#endif
