#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main(){
        int number, status;\
                cout<<endl;
        cout << "Enter number of balloons: ";
        cin >> number;
        pid_t parrent = getpid();
        pid_t child;
        for(int i = 0; i < number; ++i)
        {
                child = fork();
                switch(child)
                {
                        case -1:
                                cout << "-1 Error to fork process"<<endl;
                        case 0:
                               execl("lab41", "lab41", to_string(i+1).c_str(), NULL);
                        default:

                                cout << "\n PID:" << getpid() << "|" << child << endl;
                                 wait(&status);
                }
        }
        exit(0);
        return 0;
}
