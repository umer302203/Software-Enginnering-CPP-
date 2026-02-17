#include<iostream>
using namespace std;
class calculator {
public:
int add(int aa,int bb){
return aa+bb;
}
float add(float x,float y){
return x+y;
}
int add(int aa,int bb,int cc){
return aa+bb+cc;
}
//void display(){
//cout<<"addition"<<endl;
//}
};
int main(){
calculator C;
cout<<"sum of integer"<<C.add(3,4)<<endl;
cout<<"sum of integer"<<C.add(3,5,7)<<endl;
cout<<"sum of float"<<C.add(3.4f,5.6f)<<endl;
return 0;
}