#include <iostream>
using namespace std;

//function prototype
void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);

int main(){
    int valOne=1, valTwo=2;
    int choice, i;
    const int MaxArray = 5;
    // array of pts to non member functions
    void (*pFuncArray[MaxArray])(int&, int&);

    for(i=0; i<MaxArray;i++){
        cout<<"(1)Change values (2)Square (3)Cube (4)Swap: ";
        cin >> choice;
        switch(choice){
            case 1:
                pFuncArray[i] = GetVals;
                break;
            case 2:
                pFuncArray[i] = Square;
                break;
            case 3:
                pFuncArray[i] = Cube;
                break;
            case 4:
                pFuncArray[i] = Swap;
                break;
            default:
                pFuncArray[i] = 0;
        }
    }

    for (i=0;i<MaxArray;i++){
        if(pFuncArray[i]==0)
            continue;
        pFuncArray[i](valOne, valTwo);
        PrintVals(valOne, valTwo);
    }
    return 0;
}

void PrintVals(int x, int y){
    cout<<"x :"<<x<<" and y :"<<y<<endl;
}

void Square(int & rx, int & ry){
    rx *= rx;
    ry *= ry;
}

void Cube(int & rx, int & ry){
    int temp;
    temp = rx;
    rx *= rx;
    // rx = rx * rx * rx;
    rx = rx * temp;

    temp = ry;
    ry *= ry;
    ry = temp * ry;
}

void Swap(int & rx, int & ry){
    int temp;
    temp = rx;
    rx = ry;
    ry = temp;
}

void GetVals(int & rvalone, int & rvaltwo){
    cout << "New value for valone: ";
    cin >> rvalone;
    cout << "New value for valtwo: ";
    cin>> rvaltwo;
}
