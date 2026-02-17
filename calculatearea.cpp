#include<iostream>
using	namespace	std;
//function	overloading
float	area(int	side){
	return	side*side;
}

float	area(int	lenght,int	width){
	return	lenght*width;
}

float	area(float	radius){
	return	3.1416*radius*radius;
}

int	main(){
	cout<<"	area	of	square:"<<area(5)<<endl;
	cout<<"	area	of	rectangle:"	<<area(4,8)<<endl;
	cout<<"	area	of	triangle:"<<area(7.9f)<<endl;
	return	0;
}

