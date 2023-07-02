#ifndef LETTER_H
#define LETTER_H
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

enum class Format { Standard, Compact, Big, Maxi };
const vector<string> format_names{ "Standard", "Compact", "Big", "Maxi" };

//Definition der Klasse Letter
class Letter {
	string recipient;
	string sender;
	int postage;
	Format format;
public:
	Letter(string recipient, string sender, int postage, Format format = Format::Standard);
	Format get_format() const;
	int get_postage() const;
	int capacity_consumption() const;
	ostream& print(ostream& o)const;
};
ostream& operator<<(ostream& o, const Letter l1);






#endif