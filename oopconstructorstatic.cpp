#include<iostream>
using	namespace	std;
class	student{
	public:
		string	name;
		string	department;
		int	regno;
		static	int	counter;
		student(string	w,string	r){
			name=w;
			department=r;
			regno=++counter;
	}
	
	void	display(){
		cout<<name<<endl<<department<<endl<<regno<<endl;
	}
};
int	student::counter=1000;
	int	main(){
	student	S("shazain","CS");
	student	s1("muhammad	ali","SE");
	S.display();
	s1.display();

			
	}
