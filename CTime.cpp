#include "CTime.h"
#include <iomanip>

CTime::CTime(int h, int m, int s) : gio(h), phut(m), giay(s) {
    chuanHoa();
}

void CTime::chuanHoa() {
    if (giay < 0 || phut < 0 || gio < 0) {
        gio = phut = giay = 0;
        return;
    }

    phut += giay / 60;
    giay %= 60;

    gio += phut / 60;
    phut %= 60;

    gio %= 24;
}

CTime CTime::operator+(int seconds) const {
    int total = gio * 3600 + phut * 60 + giay + seconds;
    total = (total % 86400 + 86400) % 86400; // Đảm bảo dương
    return CTime(total / 3600, (total / 60) % 60, total % 60);
}

CTime CTime::operator-(int seconds) const {
    return (*this) + (-seconds);
}

CTime& CTime::operator++() {
    *this = *this + 1;
    return *this;
}

CTime& CTime::operator--() {
    *this = *this - 1;
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    *this = *this + 1;
    return temp;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    *this = *this - 1;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const CTime& t) {
    out << std::setfill('0') << std::setw(2) << t.gio << ":"
        << std::setw(2) << t.phut << ":" << std::setw(2) << t.giay;
    return out;
}

std::istream& operator>>(std::istream& in, CTime& t) {
    std::cout << "Nhập giờ: ";
    in >> t.gio;
    std::cout << "Nhập phút: ";
    in >> t.phut;
    std::cout << "Nhập giây: ";
    in >> t.giay;
    t.chuanHoa();
    return in;
}
