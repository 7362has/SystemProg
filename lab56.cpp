#include <iostream>
#include <ctime>
#include <pthread.h>
using namespace std;
pthread_mutex_t in;
pthread_mutex_t out;

struct start
{
int x;
int y;
int n;
};
void *balls(void *arg)
{
        struct start *info;
        info=(start*) arg;
        srand(time(0));
        int vertical_up = 50;
        int vertical_down = -50;
        int horizontal_up = 50;
        int horizontal_down= -50;
        int xd;
        int yd;
        pthread_mutex_lock(&in);
        int x = info->x;
        int y = info->y;
        int i = info->n;
        int pid;
        pid =getpt();
        cout<<"child thread= "<<pid<<endl;
        cout<< "Start coordinate:\tx = "<<x<<"\ty = "<<y<<endl;
        while (x>horizontal_down && x<horizontal_up && y>vertical_down && y< vertical_up)
        {
                xd = -50+rand()%100;
                yd = -50+rand()%100;
                cout<<"delta \tx="<<xd<<"\tdelta y="<<yd<<endl;
                x+=xd;
                y+=yd;
                pthread_mutex_lock(&out);
                cout<<"new coordinate: x=\t"<<x<<"\ty="<<y<<endl;
                pthread_mutex_unlock(&out);
        }
        pthread_mutex_unlock(&in);
        pthread_mutex_lock(&out);
        cout<<"ballon["<<i<<"] is dead"<<endl;
        pthread_mutex_unlock(&out);
        pthread_exit(NULL);
        return 0;
}

int main()
{
        int number,i;
        pthread_mutex_init(&in,NULL);
        pthread_mutex_init(&out,NULL);
        cout<<"Enter numbers ballons: ";
        cin>>number;
        srand(time(0));
        pthread_t thread[number];
        struct start threadData[number];
        for ( i=1; i<=number; i++)
        {
                threadData[i].x = -10+rand()%20;
                threadData[i].y = -10+rand()%20;
                threadData[i].n = i;
                pthread_create(&thread[i], NULL, balls, &threadData[i]);
        }
        for(i=1;i<=number; i++)
        {
                pthread_join(thread[i],NULL);
        }
 pthread_mutex_destroy(&in);
 pthread_mutex_destroy(&out);
return 0;
