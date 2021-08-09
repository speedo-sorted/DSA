 
#include <iostream> 
#include<ctype.h>

using namespace std; 
class complex{
	int a,b;
	public:
	void show(){
		cout<<"answer: "<<a<<'+'<<b<<'i'<<endl;

	}
	friend istream& operator >> (istream&,complex&);
};
istream& operator >> (istream& f,complex &c){
	cin>>c.a>>c.b;

	return f;
	


}


int main() 

{	
	complex c1;
	cin>>c1;
	c1.show();
	return 0; 
} 
