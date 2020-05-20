#include "Car.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Monovolum.h"
#include "Exceptions.h"

Car& Car::operator=(const Car& other) {
	data = other.data;
	serie = other.serie;
	culoare = other.culoare;
	km = other.km;

	return *this;
}
std::istream& operator>>(std::istream& cin, Car& obj) {
	//int nr_characteristics;
	//cin >> nr_characteristics;
	
	//obj.data.clear();
	//for (int i = 0; i < nr_characteristics; i++) {
	//	std::string prop;
	//	std::string value;
	//	cin >> prop >> value;
	//	obj.data.push_back({prop,value});
	//}
	cin >> obj.serie >> obj.culoare >> obj.km >> obj.ani_vechime;

	return cin;
}

bool operator==(const Car& first, const Car& second) {
	return first.serie == second.serie && first.culoare == second.culoare;
}

// Creates a Car from stream
Car* Car::createFactory(std::istream& cin) {
	std::string car_type;
	cin >> car_type;


	if (car_type == "Mini") {
		Mini* obj = new Mini;
		cin >> *obj;
		return obj;
	}
	if (car_type == "Mica") {
		Mica* obj = new Mica;
		cin >> *obj;
		return obj;
	}
	if (car_type == "Compacta") {
		Compacta* obj = new Compacta;
		cin >> *obj;
		return obj;
	}
	if (car_type == "Monovolum") {
		Monovolum* obj = new Monovolum;
		cin >> *obj;
		return obj;
	}

	throw NoClassFound();
}


void Car::print() const{
	for (auto el : data) {
		std::cout << el.Name << " : " << el.Value << std::endl;
	}
	std::cout << "Serie vehicul: " << serie << std::endl;
	std::cout << "Culoare vehicul: " << culoare << std::endl;
	std::cout << "Km percursi: " << km << std::endl;
	std::cout << "Vechime: " << ani_vechime << std::endl;
	std::cout << "Pret: " << getPrice() << std::endl;
}
int Car::getVechime(){ return ani_vechime; }
std::string Car::getSerie() { return serie; }