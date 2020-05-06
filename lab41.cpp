#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
        {

        cout << "Balloon number:\t" << argv[1] << endl;
        srand(time(0));
        int horizont_up = 50;
        int horizont_down = -50;
        int vertical_up = 50;
        int vertical_down = -50;
        int xd, yd;
        int x,y;
        cout << "Start coordinate:\tx = " << x << "\ty = " << y << endl;

        while(x > horizont_down && x < horizont_up && y > vertical_down && y < vertical_up)
        {
                 xd = -50 + rand() % 100;
                 yd = -50 + rand() % 100;
                 cout<<"delta_x="<<xd<<endl<<"delta_y="<<yd<<endl;
                x += xd;
                y += yd;
                cout << "new coordinate: x = " << x << "\ty = " << y<<endl;
        }
        cout << "balloon [" << argv[1] << "] is dead"<<endl;
        return 0;
}
