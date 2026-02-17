# include<iostream>
using namespace std;
class university {
public:
string university_name;
void display (){
cout<<university_name<<endl;
}
};

class department:public university {
public:
string depart_name;
void display(){
cout<<depart_name<<endl;
}
};
 
 class teacher: public department {
 public:
 string teacher_name;
 string subject;
 void display(){
 cout<<teacher_name<<endl<<subject<<endl;
 }
 };
 int main(){
 teacher T;
 //T.universityname="university of Sargodha";
// T.departname="SE";
 T.teacher_name="mam khudija ";
 T.subject="OOP";
 T.display();
 
 university U;
 U.university_name="university of Sargodha";
 
 U.display();
 department D;
 D.depart_name="SE";
 D.display();
 }
