#pragma once
#include "Car.h"

class Compacta : public Car {
	static int brand_price;

public:

	Compacta();
	Compacta(const Compacta& other);
	Compacta(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul);
	~Compacta() = default;

	Compacta& operator=(const Compacta&);
	friend std::istream& operator>>(std::istream&, Compacta&);

	void print() const;
	int getPrice() const { return brand_price; }
	std::string getCarModel() { return "Compacta"; }
};

