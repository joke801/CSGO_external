#pragma once
#include "CommonIncludes.hpp"
#include <random>
#include <wincrypt.h>

class Random {
private:
	std::mt19937 mt_Rand;

	unsigned int HashedSeed(int h1, int h2, int h3, int h4, int h5);

public:

	Random();

	bool Initialize();

	template<typename T>
	T RandomNum(T max, T min) {
		std::uniform_real_distribution<double> rng(max, min);
		return  static_cast<T>(rng(mt_Rand));
	}

};
extern Random cRandomDevice;
