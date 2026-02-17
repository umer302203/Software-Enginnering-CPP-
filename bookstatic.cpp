#include<iostream>
using	namespace	std;
class	book{
	public:
	string	author;
	string	title;
	int	newbook;
	static	int	count;
	book(string	w,	string	s){
		author=w;
		title=s;
		count++;
	}
	void	display(){
		cout<<author<<endl<<title<<endl;
	}
	static	void	showcount(){
		cout<<"total	book:"<<count<<endl;
	}
};
int	book::count=1;
int	main(){
	book	b("the	art	of	thi","yhurdeeed");
	b.display();
}
