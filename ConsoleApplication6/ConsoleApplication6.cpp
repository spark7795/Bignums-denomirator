#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

class BigNumber {
private:
	std::vector<int> denominators; // делители
	std::vector<int> primeNums; // простые числа
	std::vector<int> num, pow;
	//std::string *Powers = new std::string[10];
	int q = 0;
	void recDenomCalc(boost::multiprecision::cpp_int number) {
		for (q; q < primeCount; q++) {
			if (number % primeNums[q] == 0) {
				denominators.push_back(primeNums[q]);
				number = number / primeNums[q];
				//Show procedure?
				std::cout << number << std::endl;
				q = 0;
				recDenomCalc(number);
			}
			else {	q++; recDenomCalc(number);	}
			break;
		}
	}
	void denominatorsPower() {
		int temp=0;
		int pw = 0;
		int counter = 1;
		std::sort(denominators.begin(), denominators.end());
		temp = denominators[0];
		for (int i = 1; i < denominators.size(); i++) {
			if (temp == denominators[i]) {
				counter++;
			}
			else {
				num.push_back(temp); pow.push_back(counter);
				//std::cout << temp << " " << counter << std::endl;
				temp = denominators[i];
				counter = 1; 
			}
			
		}
		//std::cout << temp << " " << counter << std::endl;
		num.push_back(temp); pow.push_back(counter);
	}
public:

	int primeCount; // сколько простых чисел использовать
	boost::multiprecision::cpp_int number;
	void setNum(boost::multiprecision::cpp_int nm, int prime) {
		number = nm;
		primeCount = prime;
		}
	void printDenominatorsSimple() {
		for (int n : denominators) {
			std::cout << n << ' ';
		}
		std::cout << std::endl;
		
	}
	void printDenominatorsPower() {
		std::cout << std::endl;
		for (int i = 0; i < num.size(); i++) {
			std::cout << num[i] << "^" << pow[i] << ", ";
		}
		std::cout << std::endl;
	}
	void execution() {
		getPrime();
		recDenomCalc(number);
		denominatorsPower();
	}
	
	void getPrime() {
		int count = primeCount;
		for (int i = 2; count > 0; ++i)
		{
			bool  isPrime = true;
			for (int j = 2; j < i; ++j)
			{
				if (i  % j == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
			{
				--count;
				primeNums.push_back(i);
			}
		}
	}
};


int main() {
	
	BigNumber bn;
	boost::multiprecision::cpp_int NUM("10141824");
	int prime = 100;
	bn.setNum(NUM, prime);
	std::cout << NUM << std::endl;
	bn.execution();
	//bn.printDenominatorsSimple();
	bn.printDenominatorsPower();
	system("pause");
	return 0;
}

//void commonDenominator(boost::multiprecision::cpp_int number) {
//
//
//}