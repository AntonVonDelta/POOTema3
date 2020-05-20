#pragma once
#include "Car.h"

class Monovolum : public Car {
	static int brand_price;

public:

	Monovolum();
	Monovolum(const Monovolum& other);
	Monovolum(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul);
	~Monovolum() = default;

	Monovolum& operator=(const Monovolum&);
	friend std::istream& operator>>(std::istream&, Monovolum&);

	void print() const;
	int getPrice() const { return brand_price; }
	std::string getCarModel() { return "Monovolum"; }
};

