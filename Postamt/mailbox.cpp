#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"letter.h"
#include"mailbox.h"
using namespace std;

Mailbox::Mailbox(int capacity, vector<Format> allowed_formats, vector<Letter>contained_letters) :capacity{ capacity }, allowed_formats{ allowed_formats }, contained_letters{ contained_letters } {
	if (capacity < 50)
		throw runtime_error("error 5");
	if(allowed_formats.empty())
		throw runtime_error("error 6");
    int i{ 0 }, j{ 0 }, k{ 0 }, l{ 0 };
    for (const auto& a : allowed_formats) {
        switch (a) {
        case Format::Standard: ++i; break;
        case Format::Compact: ++j; break;
        case Format::Big: ++k; break;
        case Format::Maxi: ++l; break;
        }
        if (i > 1 || j > 1 || k > 1 || l > 1)
            throw runtime_error("format double");
    }
    int sum{ 0 };
    for (const auto& b : contained_letters)
        sum += b.capacity_consumption();
    if(sum > capacity)
        throw runtime_error("error 7");
    
    for (const auto& c : contained_letters) {
        for (const auto& allowed : allowed_formats) {
            if (c.get_format() != allowed) {
            throw runtime_error("format not allowed (error code whatever)");
            }
        }

    }
       

}
int Mailbox::total_value() const {
    int sum{ 0 };
    for (const auto& a : contained_letters)
        sum += a.get_postage();
    return sum;
}
void Mailbox:: empty() {
    contained_letters.clear();
}
/*Form
[{Liste erlaubter Formate}, Kapazitaet: capacity, {Liste von Briefen}] erfolgen, z.B.:
[{Standard, Maxi}, Kapazit¨at: 250, {[Anna, Peter, 120, Maxi], [Reinhold, Julia, 90, Standard]}]*/
ostream& Mailbox:: print(ostream& a)const {
    a << "[{";
    bool f = true;
    for (const auto& i : allowed_formats)
    {
        if (f)
            f = false;
        else
            a << ", ";
        a << format_names.at(static_cast<int>(i));
    }
    a << "}, Kapazitaet:" << capacity << ", {";
    for (size_t i{ 0 }; i < contained_letters.size(); ++i) {
        a << contained_letters.at(i);
        if (i < contained_letters.size() - 1)
            a << ", ";
    }
    a << "}]";
    return a;
}

ostream& operator<<(ostream& a, const Mailbox m1) {
    return m1.print(a);
}