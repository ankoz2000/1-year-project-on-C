#include "myInf.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <stdio.h>
    //struct tm{
   //    int     tm_sec;         /* секунды */
    //    int     tm_min;         /* минуты */
     //   int     tm_hour;        /* часы */
    //    int     tm_mday;        /* день мес€ца */
    //    int     tm_mon;         /* мес€ц */
   //     int     tm_year;        /* год */
  //      };
    tm tmin, tmout;
    time_t in, out;
    time_t tm_datin = in;
    time_t tm_datout = out;

ostream& operator<<(std::ostream& os, const info& val){

    int bill = (((out-in)/60.0/60.0)+0.5)*50;
    cout << "___________________________________________________________" << endl;
	return os << "| " << setw(3) <<
	val.id << "| "<< setw(3) << std::left <<
	val.marka << " | " <<
	val.nomer << " | " <<
	val.name  << " | " <<
	val.mobnomer  << " | " <<
	ctime(&tm_datin) << " | " <<
	ctime(&tm_datout) << " | bill:" <<
	bill << " |\n___________________________________________________________" << endl;
}

istream& operator>>(std::istream& is, info& val){
	cout << "id ";
	is >> val.id;
	cout << "marka ";
	is >> val.marka;
	cout << "nomer ";
	is >> val.nomer;
	cout << "name ";
	is >> val.name;
	cout << "mobnomer ";
	is >> val.mobnomer;

	///Parking in:
	cout << "Date of parking in (year.month.day.hour.minute)" << endl;
	cout << "year: ";
	is >> tmin.tm_year;
	tmin.tm_year-=tmin.tm_year-1900;
	cout << "month: ";
	is >> tmin.tm_mon;
	tmin.tm_mon-=1;
	cout << "day: ";
	is >> tmin.tm_mday;
	cout << "hour: ";
	is >> tmin.tm_hour;
	cout << "minute: ";
	is >> tmin.tm_min;
	tm_datin = mktime(&tmin);

	///Parking out:
	cout << "Date of parking out (year.month.day.hour.minute)" << endl;
    cout << "year: ";
	is >> tmout.tm_year;
	tmout.tm_year-=tmout.tm_year-1900;
	cout << "month: ";
	is >> tmout.tm_mon;
	tmout.tm_mon-=1;
	cout << "day: ";
	is >> tmout.tm_mday;
	cout << "hour: ";
	is >> tmout.tm_hour;
	cout << "minute: ";
	is >> tmout.tm_min;
	tm_datout = mktime(&tmout);
	return is;
}
