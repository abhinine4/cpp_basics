#include <iostream>

class Point{
    public:
        void SetX(int x){
            itsX = x;
        }
        void SetY(int y){
            itsY = y;
        }
        int GetX() const{
            return itsX;
        }
        int GetY() const{
            return itsY;
        }
    private:
        int itsX;
        int itsY;
};

class Rectangle{
    public:
        Rectangle(int top, int left, int bottom, int right);
        ~Rectangle();

        int GetTop() const{
            return itsTop;
        }
        int GetLeft() const{
            return itsLeft;
        }
        int GetBottom() const{
            return itsBottom;
        }
        int GetRight() const{
            return itsRight;
        }

        Point GetUpperLeft() const{
            return itsUpperLeft;
        }

        Point GetUpperRight() const{
            return itsUpperRight;
        }

        Point GetLowerLeft() const{
            return itsLowerLeft;
        }

        Point GetLowerRight() const{
            return itsLowerRight;
        }

        void SetUpperLeft(Point Location){
            itsUpperLeft = Location;
        }
        void SetLowerLeft(Point Location){
            itsLowerLeft = Location;
        }
        void SetUpperRight(Point Location){
            itsUpperRight = Location;
        }
        void SetLowerRight(Point Location){
            itsLowerRight = Location;
        }

        int GetArea() const;

    private:
        Point itsUpperLeft;
        Point itsUpperRight;
        Point itsLowerLeft;
        Point itsLowerRight;

        int itsTop;
        int itsBottom;
        int itsLeft;
        int itsRight;
};