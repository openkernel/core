#include <sys/time.h>
#include <stdio.h>
#include <time.h>

int main(int ac, char * av[])
{
	time_t now;
	time(&now);
	printf("time() NOW_IN_SEC:%ld\n", now);

	struct timeval tod;
	gettimeofday(&tod, NULL);
	unsigned long tod_in_us = (tod.tv_sec * 1000000) + tod.tv_usec;
	printf("gettimeofday() TOD_IN_US:%ld\n", tod_in_us);

	struct timespec cod ;
	clock_gettime(CLOCK_MONOTONIC, &cod);
	unsigned long cod_in_us = (cod.tv_sec * 1000000.0 + (cod.tv_nsec / 1000.0));
	printf("COD_IN_US:%ld\n", cod_in_us);
	struct timespec time_ns;
	time_ns.tv_sec =1;
	time_ns.tv_nsec =0;
	nanosleep(&time_ns, NULL);
	clock_gettime(CLOCK_MONOTONIC, &cod);
	unsigned long cod_in_us_2 = (cod.tv_sec * 1000000.0 + (cod.tv_nsec / 1000.0));
	printf("COD_IN_US:%ld\n", cod_in_us_2);
	printf("COD_DIFF_IN_US:%ld\n", cod_in_us_2-cod_in_us);

	clock_gettime(CLOCK_MONOTONIC, &cod);
	double d_cod_in_us = (cod.tv_sec * 1000000.0 + (cod.tv_nsec / 1000.0));
	printf("COD_IN_US:%f\n", d_cod_in_us);
	time_ns.tv_sec =1;
	time_ns.tv_nsec =0;
	nanosleep(&time_ns, NULL);
	clock_gettime(CLOCK_MONOTONIC, &cod);
	double d_cod_in_us_2 = (cod.tv_sec * 1000000.0 + (cod.tv_nsec / 1000.0));
	printf("COD_IN_US:%f\n", d_cod_in_us_2);
	printf("COD_DIFF_IN_US:%f\n", d_cod_in_us_2 - d_cod_in_us);
}
