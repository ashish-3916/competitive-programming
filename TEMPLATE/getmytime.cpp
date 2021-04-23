TRIGGER ->  getmytime

#include<sys/time.h>
long getTimeinMicroSeconds()
{
	struct timeval start;
	gettimeofday(&start,NULL);
	return start.tv_sec*1000000 + start.tv_usec;
}
int main()
{
	long starttime,endtime;

	starttime= getTimeinMicroSeconds();
	// code
	endtime=getTimeinMicroSeconds();
	cout<< endtime - starttime << endl;
}
