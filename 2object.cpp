#include<iostream>
using	namespace	std;
class	student{
	private:
		int	marks;
	public:
		string	name;
		string	address;
		string	phone;
		
		void	display(){
			cout<<"form	submitted"<<endl;
			cout<<"name"<<name<<endl;
			cout<<"address"<<address<<endl;
			cout<<"phone"<<phone<<endl;
			cout<<"marks"<<marks<<endl;
		}
		void	set_marks(int	m){
		marks=m;
	}
};	

int	main(){
	student	S1,S2;
	S1.name="munaza";
	S1.address="SOON	VALLEY";
	S1.phone="030076";
	S1.set_marks(89);
	S1.display();
	
	S2.name="ALISHBA";
	S2.address="SGD";
	S2.phone="0300876";
	S2.set_marks(75);
	S2.display();
	return	0;
}
