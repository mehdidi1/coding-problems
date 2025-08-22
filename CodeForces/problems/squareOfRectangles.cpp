#include <iostream>

bool canRectangle(int l1, int b1, int l2, int b2, int l3, int b3) {
    if (l1 == l2 && l2 == l3)
        return l1  == b1 + b2 + b3;

    if (b1 == b2 && b2 == b3)
        return l1 + l2 + l3 == b1 ;
    if (l1 == l2 + l3) {
        if (b2 == b3)
            return l1 == b1 + b2 ;
    }
    if (b1 == b2 + b3) {
        if (l2 == l3)
            return b1 = l1 + l2;

    }
    return false;
}bool canRectangle2(int l1, int b1, int l2, int b2, int l3, int b3) {

    if (b1 == b2 && b2 == b3)
        return l1 + l2 + l3 == b1;
    return false;
}

bool canRectangle3(int l1, int b1, int l2, int b2, int l3, int b3) {

    if (l1 == l2 + l3) {
        if (b2 == b3)
            return l1 == b1 + b2 ;
    }

    return false;
}

bool canRectangle4(int l1, int b1, int l2, int b2, int l3, int b3) {
    if (b1 == b2 + b3) {
        if (l2 == l3)
            return b1 = l1 + l2;
    }
    return false;
}

int main() {
    // Your code goes here
    int t;
    int l1, l2, l3, b1, b2, b3;
    std::cin >> t;
    while (t--) {
        std::cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        bool result = canRectangle(l1, b1, l2, b2, l3, b3)||canRectangle2(l1, b1, l2, b2, l3, b3)||canRectangle3(l1, b1, l2, b2, l3, b3)||canRectangle4(l1, b1, l2, b2, l3, b3);
        if (result)
            std::cout << "YES" << std::endl;
        else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
