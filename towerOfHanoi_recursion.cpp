#include<iostream>
using namespace std;

/*
    tower of hanoi (using recursion)

    function takes 4 parameters :

    n -> number of blocks
    src -> source holder
    des -> destination holder
    hlp -> helper holder

    function prints all moves to move all of the blocks from source to destionation holder

*/

void towerOfHanoi(int n,char src,char des,char hlp){
    if(n==0)
        return;
    towerOfHanoi(n-1,src,hlp,des);
    cout<<"move "<<src<<" to "<<des<<'\n';
    towerOfHanoi(n-1,hlp,des,src);
}

int main(){

    // 4 blocks , A is source and C is destination
    
    towerOfHanoi(4,'A','C','B');

    return 0;
}
