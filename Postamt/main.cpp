#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"letter.h"
#include"mailbox.h"
using namespace std;

int main()
{
    try {
        // Letter
        cout << "Letter\n";
        try {
            cout << Letter{ "", "Sandra", 80, Format::Big } << '\n';
            cout << "test 1\n";
        }
        catch (runtime_error&) {
            cout << "Error 1\n";
        }
        try {
            cout << Letter{ "Jill", "Sandra", 80 } << '\n';
            cout << Letter{ "Jill", "", 80 } << '\n';
            cout << "test 2\n";
        }
        catch (runtime_error&) {
            cout << "Error 2\n";
        }
        try {
            cout << Letter{ "Jill", "Sandra", 79 } << '\n';
            cout << "test 3\n";
        }
        catch (runtime_error&) {
            cout << "Error 3\n";
        }
        try {
            cout << Letter{ "Jill", "Sandra", -3, Format::Compact } << '\n';
            cout << "test 4\n";
        }
        catch (runtime_error&) {
            cout << "Error 4\n";
        }

        const vector<Letter> letters{ {"Jill", "Sandra", 81}, {"Sandra", "Jill", 120, Format::Maxi}, {"Max", "Sandra", 90},
                                     {"Joe", "Max", 200, Format::Big}, {"Jill", "Max", 90} };
        for (const auto& l : letters)
            cout << l << ' ' << l.get_postage() << ' ' << l.capacity_consumption() << '\n';
        cerr << letters.at(3) << ' ' << letters.at(1) << '\n';
        for (const auto& l : letters) {
            for (const auto& f : vector<Format>{ Format::Standard, Format::Compact, Format::Big, Format::Maxi })
                cout << (l.get_format() == f);
            cout << ' ';
        }
        cout << '\n';
        cout << Letter{ "Me", "You", 88, Format::Compact }.capacity_consumption() << '\n';

        // Mailbox
        cout << "\nMailbox\n";
        try {
            cout << Mailbox{ 50 } << '\n';
            cout << Mailbox{ 50,{} } << '\n';
            cout << "test 5\n";
        }
        catch (runtime_error&) {
            cout << "Error 5\n";
        }
        try {
            cout << Mailbox{ 49 } << '\n';
            cout << "test 6\n";
        }
        catch (runtime_error&) {
            cout << "Error 6\n";
        }
        try {
            cout << Mailbox{ -12 } << '\n';
            cout << "test 7\n";
        }
        catch (runtime_error&) {
            cout << "Error 7\n";
        }
        try {
            cout << Mailbox{ 12 } << '\n';
            cout << "test 8\n";
        }
        catch (runtime_error&) {
            cout << "Error 8\n";
        }
        try {
            cout << Mailbox{ 50, {Format::Maxi, Format::Standard, Format::Big} } << '\n';
            cout << Mailbox{ 50, {Format::Maxi, Format::Standard, Format::Big, Format::Standard} } << '\n';
            cout << "test 9\n";
        }
        catch (runtime_error&) {
            cout << "Error 9\n";
        }
        try {
            cout << Mailbox{ 60, {Format::Maxi, Format::Standard, Format::Big, Format::Compact}, letters } << '\n';
            cout << Mailbox{ 59, {Format::Maxi, Format::Standard, Format::Big, Format::Compact}, letters } << '\n';
            cout << "test 10\n";
        }
        catch (runtime_error&) {
            cout << "Error 10\n";
        }
        try {
            cout << Mailbox{ 160, {Format::Maxi, Format::Standard, Format::Compact}, letters } << '\n';
            cout << "test 11\n";
        }
        catch (runtime_error&) {
            cout << "Error 11\n";
        }

        const Mailbox mb{ 60, {Format::Maxi, Format::Standard, Format::Big, Format::Compact}, letters };
        Mailbox my_box{ mb };
        my_box.empty();
        cerr << mb << '\n' << my_box << '\n';
        cout << mb.total_value() << ' ' << my_box.total_value() << '\n';

        //Dekommentieren für Zusatz 10 Punkte
        /*
        cout << "\nZusatz post_letters 10 Punkte\n";
        cout << "ignoriert: ";
        for (const auto& l : my_box.post_letters(letters))
          cout << l << ' ';
        cout << '\n';
        cout << my_box << '\n';
        my_box = {60};
        cout << "ignoriert: ";
        for (const auto& l : my_box.post_letters(letters))
          cout << l << ' ';
        cout << '\n';
        cout << my_box << '\n';
        my_box = {69, {Format::Maxi, Format::Big, Format::Compact}};
        for (int i{0}; i<4; ++i)
          my_box.post_letters({{"X","Y",100,Format::Big}});
        cout << my_box << '\n';
        cout << "ignoriert: ";
        auto ignored{my_box.post_letters({{"A1","B",80,Format::Big}, {"A2","B",81,Format::Standard},
                    {"A3","B",82,Format::Standard}, {"A4","B",83,Format::Maxi}, {"A5","B",84,Format::Standard},
                    {"A6","B",85,Format::Compact}, {"A7","B",86,Format::Maxi}, {"A8","B",87,Format::Compact}})};
        for (const auto& l : ignored)
          cout << l << ' ';
        cout << '\n';
        cout << my_box << '\n';
        cout << '\n';
        */

        //Dekommentieren für Zusatz 15 Punkte
        /*
        cout << "\nZusatz sort 15 Punkte\n";
        my_box = mb;
        cout << my_box << '\n';
        my_box.sort({});
        cout << my_box << '\n';
        my_box.sort({Format::Maxi, Format::Compact, Format::Standard, Format::Big});
        cout << my_box << '\n';
        my_box.sort({Format::Compact, Format::Big});
        cout << my_box << '\n';
        try {
          my_box.sort({Format::Compact, Format::Big, Format::Standard, Format::Big});
          cout << my_box << '\n';
          cout << "test 12\n";
        }
        catch (runtime_error&) {
          cout << "Error 12\n";
        }
        */

    }
    catch (exception& e) {
        cout << "Unerwartete Exception: " << e.what() << '\n';
    }
    return 0;
}