#pragma once
#include "Car.h"

class Mica : public Car {
	static int brand_price;

public:

	Mica();
	Mica(const Mica& other);
	Mica(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul);
	~Mica() = default;

	Mica& operator=(const Mica&);
	friend std::istream& operator>>(std::istream&, Mica&);

	void print() const;
	int getPrice() const { return brand_price; }
	std::string getCarModel() { return "Mica"; }
};
