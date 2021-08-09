#include<bits\stdc++.h>
using namespace std;

struct node{
    int marks;
    string name;
    node* next;


};
node *start,*r,*save,*end;
void insert(string nam,int mark){
    cout<<"insert at: \n1.begining\n2.end\n3.index"<<endl;
    int choice;
    cin>>choice;
    
    if(start==0){
            ::r=new node;               //write name as name
            ::r->name=nam;
            ::r->marks=mark;
            ::r->next=0;
            start=::r;
            ::end=::r;
            if(choice==3){cout<<"Auto created 1st node at index 0"<<endl;}
            //delete ::r?
    }
    else{
        switch (choice){
        
            case 1:                
                {
                    
                    ::r=new node;
                    ::r->name=nam;
                    ::r->marks=mark;
                    ::r->next=start;
                    start=::r;
                    //delete ::r?               
                    break;
                }
            case 2:
                {
                    ::r=new node;
                    ::r->name=nam;
                    ::r->marks=mark;
                    ::r->next=0;
                    ::end->next=::r;
                    ::end=::r;
                    //delete ::r?               
                    break;
                }
            case 3:
            {
                int index;
                cin>>index;
                save=start;
                for(int i=0;i<index-1;++i){
                    save=save->next;
                }
                ::r=new node;
                ::r->marks=mark;
                ::r->name=nam;
                ::r->next=save->next;
                save->next=::r;
                //delete ::r,save?
                
                
                break;
            }
            default:
            {
                cout<<"wrong choice"<<::endl;
            }
        }       
                   
    }
    


}
void display(){
    ::r=start;
    while(::r!=0){
        cout<<::r->name<<'\t'<<::r->marks<<::endl;
        ::r=::r->next;
    }

}
void dele(string nam){
    if(start==0)    {cout<<"underflow!";    return;}
    else if(start->name==nam)   {if(start->next==0){::end=0;}   r=start;   start=start->next;  delete r;}
    else{
        r=start;
        while(r->next!=0){
            if(r->name==nam){
                if(r->next->next==0)  {::end=r->next;}
                save=r;
                r=r->next;
                delete save;
                
                return;
            }
            r=r->next;

        }
        cout<<"not found..";
        return;

    }




}  
int main(){
    ::end=0;
    start=save=r=0;
    insert("raj",26);
    insert("bhim",100);
    insert("lal",50);
    display();
    cout<<'\n';
    
    dele("lal");
    display();




delete ::start,::end,::r,::save;

    return 0;
}