#pragma once
#include <iostream>
#include <set>
#include <map>
#include "Car.h"
#include "Monovolum.h"
#include "Exceptions.h"

template<class  T>
class Vanzare {
	int nr_masini_stoc = 0;
	int nr_masini_vandute = 0;
	std::set<std::pair<T*, bool>> stoc;
	std::set<std::pair<T*, bool>> vandute;
	bool zile_vara = false;

public:
	Vanzare() = default;
	Vanzare(const Vanzare& other) {
		nr_masini_stoc = other.nr_masini_stoc;
		nr_masini_vandute = other.nr_masini_vandute;
		stoc = other.stoc;
		vandute = other.vandute;
	}
	~Vanzare() {
		for (auto el : stoc) {
			delete el.first;
		}
		for (auto el : vandute) {
			delete el.first;
		}
	}


	void addStock(T* obj,bool nou) {
		stoc.insert({obj,nou});
		nr_masini_stoc++;
	}
	bool isInStock(T& obj) {
		for (auto el : stoc) {
			if (*el.first == obj) return true;
		}
		return false;
	}

	// Returns the price for this particular car
	float operator-=(T& obj) {
		if (nr_masini_stoc == 0) return 0;

		for (auto el : stoc) {
			if (*el.first == obj) {
				nr_masini_vandute++;
				nr_masini_stoc--;
				
				vandute.insert({el.first,el.second});
				stoc.erase(el);			// This is safe because altough we invalidate the interator we are immediatelly returning thus no undefined behaviour ;)

				if (el.second) return el.first->getPrice();
				if (zile_vara) return ((float)el.first->getPrice()*10) / 100;
				return el.first->getVechime()==0? el.first->getPrice():((float)el.first->getPrice()) / el.first->getVechime();
			}
		}

		throw CarNotFound();
	}

	int getSoldCars() { return nr_masini_vandute; }
	int getStockCars() { return nr_masini_stoc; }
	void changeTime(bool isSummer) {
		zile_vara = isSummer;
	}
};

template<>
class Vanzare<Monovolum> {
public:
	int nr_masini_stoc = 0;
	int nr_masini_vandute = 0;
	std::set<std::pair<Monovolum*, bool>> stoc;
	std::set<std::pair<Monovolum*, bool>> vandute;
	bool zile_vara = false;

public:
	Vanzare() = default;
	Vanzare(const Vanzare & other) {
		nr_masini_stoc = other.nr_masini_stoc;
		nr_masini_vandute = other.nr_masini_vandute;
		stoc = other.stoc;
		vandute = other.vandute;
	}
	~Vanzare() {
		for (auto el : stoc) {
			delete el.first;
		}
		for (auto el : vandute) {
			delete el.first;
		}
	}


	void addStock(Monovolum* obj, bool nou) {
		stoc.insert({ obj,nou });
		nr_masini_stoc++;
	}
	bool isInStock(Monovolum& obj) {
		for (auto el : stoc) {
			if (*el.first == obj) return true;
		}
		return false;
	}

	// Returns the price for this particular car
	float operator-=(Monovolum& obj) {
		if (nr_masini_stoc == 0) return 0;

		for (auto el : stoc) {
			if (*el.first == obj) {
				nr_masini_vandute++;
				nr_masini_stoc--;

				vandute.insert({ el.first,el.second });
				stoc.erase(el);			// This is safe because altough we invalidate the interator we are immediatelly returning thus no undefined behaviour ;)

				if (el.second) return el.first->getPrice();
				if (zile_vara) return ((float)el.first->getPrice() * 10) / 100;
				return el.first->getVechime() == 0 ? el.first->getPrice() : ((float)el.first->getPrice()) / el.first->getVechime();
			}
		}

		throw CarNotFound();
	}

	int getSoldCars() { return nr_masini_vandute; }
	int getStockCars() { return nr_masini_stoc; }
	void changeTime(bool isSummer) {
		zile_vara = isSummer;
	}
};
