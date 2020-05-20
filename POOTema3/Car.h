#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include <iterator>
#include "Tools.h"

class Car {

protected:
	std::vector<Characteristic> data;
	std::string serie;
	std::string culoare;
	int km;
	int ani_vechime=0;

public:
	Car() : data(std::vector<Characteristic>{}), serie("TL"), culoare("Transparent"), km(0) {}
	Car(const Car& other):data(other.data), serie(other.serie), culoare(other.culoare), km(other.km) {}
	Car(std::vector<Characteristic> car_data) : data(car_data),serie("TL"),culoare("Transparent"),km(0) {}
	Car(std::vector<Characteristic> car_data,std::string serie_vehicul,std::string culoare_vehicul,int km_parcursi, int ani_vehicul) : data(car_data), serie(serie_vehicul), culoare(culoare_vehicul), km(km_parcursi),ani_vechime(ani_vehicul) {}
	~Car() = default;

	Car& operator=(const Car&);
	friend std::istream& operator>>(std::istream&, Car& obj);
	friend bool operator==(const Car&, const Car&);
	static Car* createFactory(std::istream& cin);

	virtual void print() const = 0;
	virtual int getPrice() const= 0;
	int getVechime();
	std::string getSerie();
	virtual std::string getCarModel()=0;
};

