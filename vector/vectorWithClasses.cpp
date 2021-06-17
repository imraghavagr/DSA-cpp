#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

//problem - you are at origin(0,0)
//given the x,y coordinates of n cars
//sort the cars in ascending order of the distance from you
class Car{
	public:
		string car_name;
		int x,y;
		Car(string n, int x, int y){
			car_name = n;
			this->x = x;
			this->y = y;

		}
		int dist(){
			return x*x  + y*y;
		}

};

bool cmpr(Car c1, Car c2){
	int d1 = c1.dist();
	int d2 = c2.dist();
	if(d1 == d2){
		return c1.car_name<c2.car_name;
	}
	return d1<d2;
}
int main(){

	int n;
	cin>>n;

	vector<Car> v;
	for(int i = 0; i<n; i++){
		string name;
		int x,y;
		cin>>name>>x>>y;
		Car temp(name,x,y);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmpr);

	for(auto it : v){
		cout<<"car "<<it.car_name<<" Dist "<<it.dist()<<" Location "<< it.x<<","<<it.y<<endl;
	}

	return 0;
}
