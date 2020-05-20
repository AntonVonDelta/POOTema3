#include <iostream>
#include<fstream>
#include "Car.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Monovolum.h"
#include "Vanzare.h"
#include "Exceptions.h"

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
	Vanzare<Car> vanzare;
	Vanzare<Monovolum> mono_vanzare;
	vector<Car*> cars;
	int nr_cars;
	fi >> nr_cars;

	for (int i = 0; i < nr_cars; i++) {
		Car* temp_car;
		try {
			temp_car = Car::createFactory(fi);
		} catch (NoClassFound ex) {
			cout <<"Error while in factory: "<< ex.what() << endl;
			break;
		}
		
		string nou_text;
		bool nou = false;
		fi >> nou_text;
		if (nou_text == "1") nou = true;

		temp_car->print();
		cout << endl;

		cars.push_back(temp_car);

		if(temp_car->getCarModel()=="Monovolum") mono_vanzare.addStock(static_cast<Monovolum*>(temp_car), nou);
		else vanzare.addStock(temp_car, nou);
	}



	cout << endl << endl << "############## Vanzare Masini in ordine ##############" << endl;
	cout << "Masini in stocul obisnuit: " << vanzare.getStockCars() << endl<<endl;

	vanzare.changeTime(true);
	for (int i = 0; i < cars.size(); i++) {
		Car* temp_car = cars[i];
		float sell_price;

		try {
			sell_price = (vanzare -= *temp_car);
		} catch (CarNotFound ex) {
			cout << "Error while selling car " << temp_car->getCarModel() << " : " << temp_car->getSerie() << " -> " << ex.what() << endl;
			continue;
		}
		
		cout << "Price for a " << temp_car->getCarModel()<<" with Id : " << temp_car->getSerie()<<" " << " is " << sell_price << endl;
	}
	cout << endl<< "Masini ramase in stocul obisnuit: " << vanzare.getStockCars() << endl;




	cout << endl << endl << "############## Vanzare Monovolume ramase ##############" << endl;
	cout << "Masini in stocul de monovolume: " << mono_vanzare.getStockCars() << endl << endl;
	for (int i = 0; i < cars.size(); i++) {
		Car* temp_car = cars[i];
		float sell_price;

		try {
			Monovolum* mono_car = dynamic_cast<Monovolum*>(temp_car);

			if (mono_car == nullptr) continue;
			sell_price = (mono_vanzare -= *mono_car);
		} catch (CarNotFound ex) {
			cout << "Error while selling car " << temp_car->getCarModel() << " : " << temp_car->getSerie() << " -> " << ex.what() << endl;
			continue;
		}

		cout << "Price for a " << temp_car->getCarModel() << " with Id : " << temp_car->getSerie() << " " << " is " << sell_price << endl;
	}
	cout << endl << "Masini ramase in stocul de monovolume: " << mono_vanzare.getStockCars() << endl;

	return 0;
}