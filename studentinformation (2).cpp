#include<iostream>
using	namespace	std;

class	student{
	public:
		string	name;
		string	department	;
		int	rollnumber;
		void	display(){
			cout<<"student	information"<<endl;	
			cout<<"name"<<name<<endl;
			cout<<"department"<<department<<endl;
			cout<<"rollnumber"<<rollnumber<<endl;
		}
	};
	
int	main(){
	student	S;
	S.name="shahzain";
	S.department="software	engineering";
	S.rollnumber=3456;
	S.display();
}
