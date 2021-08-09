#include<bits/stdc++.h>
using namespace std;
int main(){





    return 0;
}
struct status{
    int total_years;
    vector<int> yr;
    vector<string> ty;


};

class chetna{
    int karm_point;
    bool current_existance;
    int yoni;
    status stats;


    public:
    void show_existance(){          //opps it comes under workable
        if(current_existance)   cout<<"physically exist as "<<type<<endl;     //make nonworkable
        else cout<<"living in ....";        //enter place of existance
        
    }
    void change_existance(){
                                     //*******
    }
    void show_status(){
        cout<<"the status of this chetna is -"<<endl<<endl<<"1.The number of yoni is: "<<yoni<<endl<<"2.yoni description "<<endl;
        cout<<"\t\t "<<"Sno."<<'\t'<<"Yoni name"<<'\t'<<"yoni years"<<endl;
        cout<<"\t\t____________________________________________________________\n";
        for(int i=1;i<=yoni;++i){
            cout<<"\t\t\t";
            if(i==yoni) cout<<"***";
            cout<<i<<'\t'<<stats.ty[i]<<'\t'<<stats.yr[i]<<endl;
        }
        cout<<"\n\nthe total years chetna has lived is: "<<stats.total_years;
                                     
    }

};
class workable:public chetna  {
    string type;

    public:
    void display_type() cout<<"the type is "<<type<<endl;
    void change_type(string s){
        type=s;
        cout<<"new type existance "<<type<<endl;
    }

};
class human:public workable {
                                                //karm_point-=30;
    string h_type;
    int year;
    public:
    void display_human(){
         cout<<"the human type is "<<h_type<<endl<<"the karm_point after is "<<karm_point<<endl;
    }   
    void change_h_type(string s){
        h_type=s;
        cout<<"new h_type is "<<h_type<<endl;

    }
    

};