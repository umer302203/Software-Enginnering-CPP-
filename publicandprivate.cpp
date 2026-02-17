#include<iostream>
#include<string>
using	namespace	std;
class	bankaccount{
	private:
				double	balance;
		public:
			string	accountholdername;
			bankaccount(string	name,double	initialbalance){
		accountholdername	=name;
				balance=initialbalance;
			}
			void	deposit(double	amount){
				if(amount>0){
					balance+=amount;
				}
				else{
					cout<<"invalid	deposit	amount"<<endl;
				}
			
			}
			double	getbalance(){
				return	balance;
			}	
		
};		
int	main(){
	bankaccount	account1("ali",3000);
	account1.deposit(6000);
	
		cout<<"accountholder:"<<account1.accountholdername<<endl;
		cout<<"updated	balance:"<<account1.getbalance()<<endl;
		return	0;
			}

