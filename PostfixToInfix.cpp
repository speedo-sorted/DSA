#include<bits\stdc++.h>
using namespace std;
void PostToInfix(string x);
int main(){

    PostToInfix("ABCD+-/");


    return 0;
}

void PostToInfix(string x){
   int len=x.size();
   char div='/',mul='*',add='+',sub='-';
   vector<char> vec;

    int s=0,p=0,i=0;

   while(i<len){
       while(i!=(vec.size()*2) || i==0){
           if(x[i]==div || x[i]==mul || x[i]==add || x[i]==sub){
               vec[vec.size()]=x[i];
               
           }
           i++;
                     
       }
       while(vec.size()!=0){
           cout<<'(';   p++;
           cout<<x[s]<<vec[vec.size()-1];
           vec.pop_back();
            s++;
           

       }
       cout<<x[s];
       s=s+p+1;
       for(;p>=1;--p) {cout<<')';}
       p=0;
       




   }




}