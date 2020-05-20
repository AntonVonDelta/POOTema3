#include "Compacta.h"
Compacta::Compacta() :Car(std::vector<Characteristic> { {"Teren", "Oras"}, {"Teren","Drum lung"}, { "Model disponibil","hatchback" }, { "Model disponibil","combi" }, { "Model disponibil","sedan" }, { "Dimensiune", "intre 4.2m si 4.5m" }}) {}
Compacta::Compacta(const Compacta& other) : Car(other) {}
Compacta::Compacta(std::vector<Characteristic> car_data, std::string serie_vehicul, std::string culoare_vehicul, int km_parcursi, int ani_vehicul) : Car(car_data, serie_vehicul, culoare_vehicul, km_parcursi, ani_vehicul) {}

Compacta& Compacta::operator=(const Compacta& other) {
	Car::operator=(other);
	return *this;
}
int Compacta::brand_price = 50;

std::istream& operator>>(std::istream& cin, Compacta& obj) {
	cin >> ((Car&)obj);
	return cin;
}
void Compacta::print() const {
	std::cout << "Compacta, date masina:\n";

	// Option 1 
	Car::print();

	// Option 2
	//(*this).Car::print();
}