//File name : TestProblemII.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a,b,c;
pthread_mutex_t lock;

void* thread1(void* arg)
{
	a=10;
}

void* thread2(void* arg)
{
    pthread_mutex_lock(&lock);
	if(a!=10)
    {
		b=9;
    }
	else
	{
	    b=10;
    }
    pthread_mutex_unlock(&lock);

    pthread_mutex_lock(&lock);
    if(a==10)
    {
        c=1/(b-9);
    }
    pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t t[2];
	pthread_mutex_init(&lock, NULL);

	//pthread_create( &t[0], NULL, &thread1, NULL);
	//pthread_create( &t[1], NULL, &thread2, NULL);

    //pthread_join(t[0], NULL);
    //pthread_join(t[1], NULL);
    pthread_mutex_destroy(&lock);
	return 0;
}
void test_thread2_case_1()
{
	a = 10;
	a = 0;
	thread2();
}
void test_thread2_case_2()
{
	a = 0;
	a = 0;
	thread2();
}
void test_thread2_case_3()
{
	a = 0;
	a = 10;
	thread2();
}
void test_thread2_case_4()
{
	a = 10;
	a = 10;
	thread2();
}
void test_thread2_case_5()
{
	a = 0;
	//ON_DEMAND_SHARED_VARIABLE_CHANGE,26,a,10
	thread2();
}
void test_thread1_case_1()
{
	thread1();
}

