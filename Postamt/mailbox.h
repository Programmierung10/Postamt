#ifndef MAILBOX_H
#define MAILBOX_H
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"letter.h"
using namespace std;

//Definition der Klasse Mailbox

class Mailbox {
	int capacity;
	vector<Format>allowed_formats;
	vector<Letter>contained_letters;
public:
	Mailbox(int capacity, vector<Format>allowed_formats = { Format::Standard }, vector<Letter>contained_letters = {});
	int total_value() const;
	void empty();
	ostream& print(ostream& a)const;
};
ostream& operator<<(ostream& a, const Mailbox m1);











#endif