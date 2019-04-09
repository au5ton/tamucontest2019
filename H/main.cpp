#include <iostream>

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int lcm(int nums[], int n){
	int i;
	int r=1;
	for(int i=0; i<n; i++)
		r=r*nums[i]/gcd(r, nums[i]);
	return r;
}

int main(){
	int n;
	std::cin >> n;
	int *f = new int[n];
	for(int i=0; i<n; i++)
		std::cin >> f[i];

	std::cout << lcm(f, n) << std::endl;
}
