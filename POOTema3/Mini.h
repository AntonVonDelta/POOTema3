#pragma once
#include "Car.h"

class Mini : public Car {
	static int brand_price;

public:

	Mini();
	Mini(const Mini& other);
	Mini(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi,int ani_vehicul);
	~Mini() = default;

	Mini& operator=(const Mini&);
	friend std::istream& operator>>(std::istream&, Mini&);

	void print() const;
	int getPrice() const { return brand_price; }
	std::string getCarModel() { return "Mini"; }
};

