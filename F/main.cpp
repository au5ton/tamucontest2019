#include <iostream>
#include <cmath>

int main(){
	long long n;
	std::cin >> n;

	if(n<26){
		std::cout << 0 << std::endl;
	} else {
		// long long i=3;
		// //while(n>=(pow(i, 3)-pow(i-2, 3)))
		// if(n>10000){
		// 	i=42;
		// } else if(i>100000){
		// 	i=131;
		// } else if(i>100000){
		// 	i=410;
		// }
		// while(n>=(6*i*i-12*i+8))
		// 	  i++;
		// std::cout << i-1 << std::endl;
		//
		std::cout << int(sqrt((1.0/6)*n-(1.0/3)))+1 << std::endl;
	}
}
