#include "Mica.h"
Mica::Mica() :Car(std::vector<Characteristic> { {"Teren", "Oras"}, { "Dimensiune","intre 3.85m si 4.1m" }}) {}
Mica::Mica(const Mica& other) : Car(other) {}
Mica::Mica(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul) : Car(car_data, serie_vehicul, culoare_vehicul, km_parcursi, ani_vehicul) {}

Mica& Mica::operator=(const Mica& other) {
	Car::operator=(other);
	return *this;
}
int Mica::brand_price = 500;

std::istream& operator>>(std::istream& cin, Mica& obj) {
	cin >> ((Car&)obj);
	return cin;
}
void Mica::print() const {
	std::cout << "Mica, date masina:\n";

	Car::print();
}