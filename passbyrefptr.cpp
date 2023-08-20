#include <iostream>

using namespace std;
class SimpleCat{
    public:
        SimpleCat();
        SimpleCat(SimpleCat&); //copy constructor
        ~SimpleCat();
};

SimpleCat::SimpleCat(){
    cout<<"Simple Cat Constructor...\n";
}

SimpleCat::SimpleCat(SimpleCat&){
    cout<<"Copy constructor called ... \n";
}

SimpleCat::~SimpleCat(){
    cout<<"Simple cat destrucor called...\n";
}
//fn prototype
SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat * FunctionTwo(SimpleCat *theCat);

int main(){
    cout << "Creating a cat ... \n";
    SimpleCat Frisky;
    cout<<"Calling fn_one...\n";
    FunctionOne(Frisky);
    cout<<"Calling fn_two...\n";
    FunctionTwo(&Frisky);
    return 0;
}

// fn implementation
// create multiple copies of if objects are passed
SimpleCat FunctionOne(SimpleCat theCat){
    cout << "Fn_one returning..\n";
    return theCat;
}

// extra copies are not made when passing by refernece using pointers
SimpleCat* FunctionTwo(SimpleCat *theCat){
    cout <<"fn_two..returning..\n";
    return theCat;
}