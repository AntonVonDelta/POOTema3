#include "Monovolum.h"
Monovolum::Monovolum() :Car(std::vector<Characteristic> { {"Model disponibil","van"}, {"Capacitate", "5-7 persoane"}}) {}
Monovolum::Monovolum(const Monovolum& other) : Car(other) {}
Monovolum::Monovolum(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul) : Car(car_data, serie_vehicul, culoare_vehicul, km_parcursi, ani_vehicul) {}

Monovolum& Monovolum::operator=(const Monovolum& other) {
	Car::operator=(other);
	return *this;
}
int Monovolum::brand_price = 7451;
 
std::istream& operator>>(std::istream& cin, Monovolum& obj) {
	cin >> ((Car&)obj);
	return cin;
}
void Monovolum::print() const {
	std::cout << "Monovolum, date masina:\n";

	// Option 1 
	Car::print();

	// Option 2
	//(*this).Car::print();
}