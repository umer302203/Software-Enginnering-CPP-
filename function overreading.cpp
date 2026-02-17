#include<iostream>
using namespace std;
class employee {
public:
void work(){
cout<<"employee is working"<<endl;
}
};
class professor:public employee {
public:
void work(){
cout<<"professor is teaching"<<endl;
}
};
int main (){
employee E;
professor P;
E.work();
P.work();
}
