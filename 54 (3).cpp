#include<iostream>
using	namespace	std;
class	student{
	public:
	string	name;
	string	rollnumber;
	int	marks;
	student(string	r,	string	s,	int	w){
	name=r;
	rollnumber=s;
	marks=w;
}
	void	display(){
	cout<<name<<endl<<rollnumber<<endl<<marks<<endl;
	}
};
int	main(){
	student	s1	("munaza","5678",87);
	student	s2("alishba","67894",90);
	student	s3("bilal","7654",67);
	s1.display();
	s2.display();	
	s3.display();
}
