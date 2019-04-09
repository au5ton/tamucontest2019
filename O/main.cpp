#include <iostream>
#include <vector>
#include <string>

struct Point{
	int x, y;
};

Point getNext(Point prev, int &dir, bool isLeft){
	Point next;
	if(isLeft){
		switch(dir){
		case 0:
			next.x=prev.x+1;
			next.y=prev.y+2;
			dir=1;
			break;
		case 1:
			next.x=prev.x-1;
			next.y=prev.y+2;
			dir=2;
			break;
		case 2:
			next.x=prev.x-2;
			next.y=prev.y;
			dir=3;
			break;
		case 3:
			next.x=prev.x-1;
			next.y=prev.y-2;
			dir=4;
			break;
		case 4:
			next.x=prev.x+1;
			next.y=prev.y-2;
			dir=5;
			break;
		case 5:
			next.x=prev.x+2;
			next.y=prev.y;
			dir=0;
			break;
		}
	} else {
		switch(dir){
		case 0:
			next.x=prev.x+1;
			next.y=prev.y-2;
			dir=5;
			break;
		case 1:
			next.x=prev.x+2;
			next.y=prev.y;
			dir=0;
			break;
		case 2:
			next.x=prev.x+1;
			next.y=prev.y+2;
			dir=1;
			break;
		case 3:
			next.x=prev.x-1;
			next.y=prev.y+2;
			dir=2;
			break;
		case 4:
			next.x=prev.x-2;
			next.y=prev.y;
			dir=3;
			break;
		case 5:
			next.x=prev.x-1;
			next.y=prev.y-2;
			dir=4;
			break;
		}
	}
	return next;	
}

	
int main(){
	std::vector<Point> points;
	std::string s;
	std::cin >> s;
	Point p{0,0};
	int str_length = s.size();
	int dir =0;
	points.push_back(p);
	for(int i=0; i<str_length; i++){
		p=getNext(p, dir, s.at(i)=='L');
		points.push_back(p);
	}
	Point p1{0,0};
	points.push_back(p1);

	double total =0;
	for(int i=0; i<points.size()-1; i++){
		total+=points[i].x*points[i+1].y;
		total-=points[i+1].x*points[i].y;
	}
	std::cout << abs(total/24);
}
