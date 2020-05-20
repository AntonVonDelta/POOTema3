#include "Mini.h"
Mini::Mini() :Car(std::vector<Characteristic> { {"Teren", "Oras"}, {"Combustibil","mic litraj"}, { "Dimensiune", "sub 4m" }}) {}
Mini::Mini(const Mini& other):Car(other) {}
Mini::Mini(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul): Car(car_data, serie_vehicul, culoare_vehicul, km_parcursi, ani_vehicul) {}

Mini& Mini::operator=(const Mini& other) {
	Car::operator=(other);
	return *this;
}

int Mini::brand_price = 100;

std::istream& operator>>(std::istream& cin, Mini& obj) {
	cin >> ((Car&)obj);
	return cin;
}

void Mini::print() const {
	std::cout << "Mini, date masina:\n";

	// Option 1 
	Car::print();

	// Option 2
	//(*this).Car::print();
}