#include <iostream>

int main(){
    using std::cout;
    using std::endl;

    short int width = -32768, length;
    length = 10;

    unsigned short int area = width*length;
    cout << "Width : " << width << "\n";
    cout << "Length : " << length << endl;
    cout << "Area : " << area << endl;

    width --;
    cout << width <<endl;
    width ++;
    cout << width << endl;
    return 0;
}

