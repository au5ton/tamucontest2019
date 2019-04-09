#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int p=0;
	int x;
	for(int i=0; i<n; i++){
		std::cin >> x;
		p+=x;
	}
	std::cout << "Hello " << p << " worlds" << std::endl;

}
