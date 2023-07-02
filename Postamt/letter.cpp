#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"letter.h"
using namespace std;

Letter::Letter(string recipient, string sender, int postage, Format format) :recipient{ recipient }, sender{ sender }, postage{ postage }, format{ format } {
	if (recipient.empty())
		throw runtime_error("error 1");
	if(sender.empty())
		throw runtime_error("error 2");
	if(postage < 80)
		throw runtime_error("error 3");
}
Format Letter::get_format() const {
	return format;
}
int Letter::get_postage() const {
	return postage;
}
int Letter::capacity_consumption() const {
	return 2*static_cast<int>(format) + 10;
}
ostream& Letter:: print(ostream& o)const{
	o << "[" << recipient << ", " << sender << ", " << postage << ", " << format_names.at(static_cast<int>(format)) << "]";
	return o;
}
/*in der Form [recipient, sender, postage, format] ausgegeben werden, z.B.:
[Anna, Peter, 120, Maxi]. Der vordefinierte Vektor format names kann f¨ur die Ausgabe der Formate verwendet werden.*/
ostream& operator<<(ostream& o, const Letter l1) {
	return l1.print(o);
}
