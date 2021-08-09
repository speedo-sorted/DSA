#include<bits\stdc++.h>

using namespace std;
void intopo(string);
bool pref(char,char);
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        intopo(s);
    }


    return 0;
}
void intopo(string str){
    string vec;
    int i=0;
    while(i<str.size()){
        if(str[i]==')'){
            while(vec.size()!=0 || vec[vec.size()-1]!='(')    {
                if(vec[vec.size()-1]!='('){
                    (cout<<vec[vec.size()-1]);
                }
                    
                       vec.pop_back();
                }
        }
        else if(str[i]=='(')    {vec.push_back(str[i]);}
        else if(str[i]=='/' || str[i]=='*' || str[i]=='+' || str[i]=='-'){
            if(vec.size()!=0){
                if(pref(str[i],vec[vec.size()-1]))  {vec.push_back(str[i]);}
                else    {cout<<vec[vec.size()-1];   vec.pop_back(); vec.push_back(str[i]);}
            }
            else
            vec.push_back(str[i]);
        }
        else
        {
            cout<<str[i];
        }
        
        i++;
    }
    

    for(int l=vec.size()-1;l>=0;--l)    {cout<<vec[vec.size()-1];}
    return;

}
bool pref(char stx,char vey){
    if(vey=='/')    {return 1;}
    else if(vey=='*' && (stx=='/'))   {return 1;}
    else if(vey=='+' && (stx=='/' || stx=='*')) {return 1;}
    else if(vey==stx){return 1;}
    else if(vey=='('){return 1;}
    else {return 0;}

}