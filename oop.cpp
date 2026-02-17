#include<iostream>
using	namespace	std;

	class	student{
	public:
	string	name;
	string	address;
	string	phone;
	int	marks;
	void	submit(){
		cout<<"form	submit"<<endl;
	}
	//void	show(){
	//	cout<<"name="<<name<<endl;
	//	cout<<"address="<<address<<endl;
	//	cout<<"phone="<<phone<<endl;
	//	cout<<"marks="<<marks<<endl;
	//}
};
int	main(){
	student	S;
	S.name="ahmed";
	S.address="SGD";
	S.phone="0398";
	S.marks='75';
	S.submit();
//	S.show();
}
