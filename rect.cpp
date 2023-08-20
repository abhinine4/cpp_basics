#include "rect.hpp"

Rectangle::Rectangle(int top, int left, int bottom, int right){
    itsTop = top;
    itsBottom = bottom;
    itsLeft = left;
    itsRight = right;

    itsUpperLeft.SetX(left);
    itsUpperLeft.SetY(top);


    itsUpperRight.SetX(right);
    itsUpperRight.SetY(top);

    itsLowerLeft.SetX(left);
    itsLowerLeft.SetY(bottom);

    itsLowerRight.SetX(right);
    itsLowerRight.SetY(bottom);
}

Rectangle::~Rectangle(){

}

int Rectangle::GetArea() const {
    int width = itsRight - itsLeft;
    int height = itsTop - itsBottom;
    return (width * height);
}

int main(){
    Rectangle MyRectangle(100, 20, 50, 80);
    int Area = MyRectangle.GetArea();
    std::cout << "Area : " <<Area << "\n";
    std::cout << "Upper Left X coord : " << MyRectangle.GetUpperLeft().GetX();
    return 0;
}





