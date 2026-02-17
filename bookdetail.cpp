#include<iostream>
using	namespace	std;

class	book{
	public:
		string	title;
		string	author;
		int	price;
		void	display(){
			cout<<"book	details"<<endl;	
			cout<<"title"<<title<<endl;
			cout<<"author"<<author<<endl;
			cout<<"price"<<price<<endl;
		}
	};
	
int	main(){
	book	B;
	B.title="testing	computer	software";
	B.author="hungQ		Nguyen";
	B.price=3000;
	B.display();
}
