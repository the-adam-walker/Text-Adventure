/* Author  : Mark Burrell
 * File    : Item.cpp
 * Date    : 30 Oct 2018
 * Project : CS225 Group Project
 * Purpose : Primarily to handle generation of Items and their enchanted subtype. Designed to work off a single pointer type
 */

#include "Items.h"

using namespace std;

Item::Item(string name) {
	//cout << "Building item" << endl;;
	isEnchanted = false;
	bool validItem = false;
	string line;
	do {
		try {
			ifstream fin("Items.txt");
			int rand;
			getline(fin, line);
			int NUMBER_OF_ITEMS = stoi(line);
			vector<string> parser;
			if (name.compare("random") == 0) {
				rand = randInt(0, NUMBER_OF_ITEMS);
				//	cout << rand << endl;
				for (int i = 0; i <= rand; i++) {
					getline(fin, line);
					parser = stringSplit(line);
				}
			} else {
				do {
					getline(fin, line);
					if (line.length() < 3) {
						throw "No Such item!";
					}
					parser = stringSplit(line);
				} while (parser.at(0).compare(name) != 0);
			}

			this->name = parser.at(0);
			this->target = parser.at(1);
			this->bonus = stoi(parser.at(2));
			if (parser.at(3) == "F") {
				this->isPrecent = false;
			} else {
				this->isPrecent = true;
			}
			//cout << "finished building item" << this->name << endl;
			fin.close();
			validItem = true;
		} catch (const char* c) {
			cout << c << endl;
			validItem = false;
		} catch (...) {
			cout << "Unknown error during item generation, returning junk item"
					<< endl;
			name = "Rusted Junk";
			target = "health";
			bonus = 0;
			isPrecent = 0;
			validItem = true;
		}
	} while (!validItem);
}

ostream& Item::displayItem(ostream& os) {
	os << "Item: " << name << " Bonus: " << bonus;
	//fflush(stdout);
	return os;
}

ostream& operator<<(ostream& os, Item& item) {
	return item.displayItem(os);
}

bool Item::operator==(Item& item) {
	if (item.name == name)
		return true;
	return false;
}
Item::~Item() {
	cout << name << " has been destroyed" << endl;
}
EnchantedItem::EnchantedItem(string name) {
	isEnchanted = true;
	string line;
	bool validItem = false;
	do {
		try {
			ifstream fin("Enchantment.txt");
			int rand;
			getline(fin, line);
			int NUMBER_OF_ITEMS = stoi(line);
			vector<string> parser;
			if (name.compare("random") == 0) {
				rand = randInt(0, NUMBER_OF_ITEMS);
				//	cout << rand << endl;
				for (int i = 0; i <= rand; i++) {
					getline(fin, line);
					parser = stringSplit(line);
				}
			} else {
				do {
					getline(fin, line);
					parser = stringSplit(line);
				} while (parser.at(0).compare(name) != 0);
			}

			this->enchantmentName = parser.at(0);
			this->enchantmentTarget = parser.at(1);
			this->enchantmentBonus = stoi(parser.at(2));
			if (parser.at(3) == "F") {
				this->enchantmentPrecent = false;
			} else {
				this->enchantmentPrecent = true;
			}
			//cout << "finished building Enchantment" << this->name << endl;
			fin.close();
			validItem = true;
		} catch (const char* c) {
			cout << c;
			validItem = false;
		} catch (...) {
			cout
					<< "Unknown error during Enchantment generation, returning old enchantment"
					<< endl;
			enchantmentName = "Decayed magic";
			enchantmentTarget = "health";
			enchantmentBonus = 0;
			enchantmentPrecent = false;
			validItem = true;
		}
	} while (!validItem);
}

ostream& EnchantedItem::displayItem(ostream& os) {
	os << "Item: " << name << " with " << enchantmentName << " Item Bonus: "
			<< bonus << " Enchantment Bonus: " << enchantmentBonus;
	//fflush(stdout);
	return os;
}
ostream& operator<<(ostream& os, EnchantedItem& item) {
	return item.displayItem(os);
}
EnchantedItem::~EnchantedItem() {
	cout << enchantmentName << "Has been removed" << endl;
}

