#include <iostream>
#include "CTime.h"

int main() {
    CTime t;
    std::cin >> t;

    std::cout << "Thời gian hiện tại: " << t << "\n";
    std::cout << "Thêm 500 giây: " << (t + 500) << "\n";
    std::cout << "Bớt 1000 giây: " << (t - 1000) << "\n";

    std::cout << "++t = " << ++t << "\n";
    std::cout << "t++ = " << t++ << "\n";
    std::cout << "Sau t++: " << t << "\n";

    std::cout << "--t = " << --t << "\n";
    std::cout << "t-- = " << t-- << "\n";
    std::cout << "Sau t--: " << t << "\n";

    return 0;
}
