#include <iostream>
#include<fstream>
#include "Car.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Monovolum.h"
#include "Vanzare.h"

using namespace std;

ifstream fi("Input.txt");


int main() {
	cout << "############## Default constructor si citire din fisier ##############" << endl;
	Mini temp;
	temp.print();

	cout << endl;

	fi >> temp;
	temp.print();

	cout <<endl<<endl<< "############## Vanzare - Creare stock ##############" << endl;
	Vanzare<Car> v;
	vector<Car*> cars;
	int nr_cars;
	fi >> nr_cars;

	for (int i = 0; i < nr_cars; i++) {
		Car* temp_car = Car::createFactory(fi);
		
		string nou_text;
		bool nou = false;
		fi >> nou_text;
		if (nou_text == "1") nou = true;

		temp_car->print();
		cout << endl;

		cars.push_back(temp_car);
		v.addStock(temp_car, nou);
	}

	cout << endl << endl << "############## Vanzare - Masini in ordine##############" << endl;
	for (int i = 0; i < cars.size(); i++) {

		Car* temp_car = cars[i];
		float sell_price = (v -= *temp_car);
		cout << "Price for a " << temp_car->getCarModel()<<" with Id : " << temp_car->getSerie()<<" " << " is " << sell_price << endl;
	}
	return 0;
}