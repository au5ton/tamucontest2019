#include <iostream>
#include <string>

int main(){
	int n,k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;

	std::string sk;
	int e;

	int energy=0;
	
	for(int i=0; i<k; i++){
		std::cin >> sk >> e;
		for(int j=0; j<n-sk.size()+1; j++){
			// std::cout << "Substring: " << s.substr(j, sk.size()) << std::endl;
			if(s.substr(j, sk.size())==sk)
				energy+=e;
		}
	}
	std::cout << energy << std::endl;
}
