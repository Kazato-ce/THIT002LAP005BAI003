#ifndef CTIME_H
#define CTIME_H

#include <iostream>

class CTime {
private:
    int gio, phut, giay;

    void chuanHoa(); // Chuẩn hóa thời gian

public:
    CTime(int h = 0, int m = 0, int s = 0);

    // Toán tử cộng, trừ với số giây
    CTime operator+(int seconds) const;
    CTime operator-(int seconds) const;

    // Tiền tố ++ và --
    CTime& operator++();   // ++ct
    CTime& operator--();   // --ct

    // Hậu tố ++ và --
    CTime operator++(int); // ct++
    CTime operator--(int); // ct--

    // Nhập / Xuất
    friend std::ostream& operator<<(std::ostream& out, const CTime& t);
    friend std::istream& operator>>(std::istream& in, CTime& t);
};

#endif
