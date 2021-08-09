#include<iostream>
using namespace std;

int main()
{
    int ary[]={1,2,4};
    int(*val)[3];           //pointer to array of size 3 declared
    val=&ary;               //size of a pointer is 32 bit (8 bytes) here 
    cout<<"address val is storing  "<<val<<endl<<"address ary is storing  "<<ary<<endl<<"size of val  "<<sizeof(val)<<endl;





    return 0;
}

