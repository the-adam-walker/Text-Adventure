/*
 * Items.h
 *
 *  Created on: Oct 30, 2018
 *      Author: Mark
 */

#ifndef ITEMS_H_
#define ITEMS_H_
#include<iostream>
#include <string>
#include <fstream>
#include "util.h"
using namespace std;

class Item {
protected: //TODO Fix this!!!!
	string name;
	string target;
	float bonus;
	bool isPrecent;
	bool isEnchanted;
	string enchantmentName;
	string enchantmentTarget;
	float enchantmentBonus;
	bool enchantmentPrecent;
public:
	Item(string name = "random");
	string getName() {return name;}
	string getTargetStat() {return target;}
	float getBonus() {return bonus;}
	bool precent() {return isPrecent;}
	bool hasEnchantment() { return isEnchanted; }
	string getEnchantmentName() { return enchantmentName;}
	string getEnchantmentTargetStat() { return enchantmentTarget;}
	float getEnchantmentBonus() { return enchantmentBonus; }
	bool getEnchantmentPrecent() { return enchantmentPrecent; }
	bool operator==(Item&);
	friend ostream& operator<<(ostream& os, Item& item);
	~Item();
};

class Enchanted_Item : public Item {
public:

public:
	Enchanted_Item(string name = "random");
	friend ostream& operator<<(ostream& os, Enchanted_Item& item);
	~Enchanted_Item();
};
#endif /* ITEMS_H_ */
