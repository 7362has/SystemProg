// Example program
#include <iostream>

using namespace std;

int main()
{
   
    int a[5], b[5];

for(int i=0;i<5;i++)
{
    cout<<"vvedi"<<" a["<< i<<"]"<<endl;
    cin>>a[i];
    cout<<"vvedi"<<"  b["<<i<<"]"<<endl;
    cin>>b[i];
}

int c=0;
int sum=0;
    
    for (int i=0;i<5;i++)
    {
        c=a[i]*b[i];
        sum=c+sum;    
        }
    
 cout<<sum<<endl;
 
}
