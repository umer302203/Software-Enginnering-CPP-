#include<iostream>
using namespace std;
class person {
public:
string name ;
int phoneno;
string address ;
person (){
cout<<"this is base class ;"<<endl;
}
~person(){
cout<<"destructor called is:"<<endl;
}

};
class faculty : public person {
public :
string designation ;
faculty(){
cout<<"this is the derived  class"<<endl;
}
~faculty(){
cout<<"destructor called"<<endl;
}
void display (){
cout<<name <<endl<<address <<endl<<designation <<endl<<phoneno<<endl;
cout<<"show these thing "<<endl;}
};
//class student :public faculty{
//public:

int main(){
faculty f;
f.name="ali";
f.address="SGD";
f.designation ="professor";
f.phoneno=567888;
f.display();
}