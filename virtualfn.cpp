#include <iostream>

using namespace std;

class Mammal{
    public:
        Mammal():itsAge(1){}
        virtual ~Mammal(){}
        virtual void Speak() const {cout<<"Mammal Speaks !\n";}
    protected:
        int itsAge;
};

class Dog: public Mammal{
    public:
        void Speak() const{
            cout<<"Dog Speaks !\n";
        }
};

class Cat: public Mammal{
    public:
        void Speak() const{
            cout<<"Cat Speaks !\n";
        }
};

void ValueFunction(Mammal);
void PtrFunction(Mammal *);
void RefFunction(Mammal&);

int main(){
    Mammal * ptr = 0;
    int choice;
    while(1){
        bool fQuit = false;
        cout<<"(1)dog (2)cat (0)quit: ";
        cin>>choice;
        switch (choice){
            case 0:
                fQuit=true;
                break;
            case 1:
                ptr = new Dog;
                break;
            case 2:
                ptr = new Cat;
                break;
            default:
                ptr = new Mammal;
                break;
        }
        if (fQuit)
            break;
        PtrFunction(ptr);
        RefFunction(*ptr);
        ValueFunction(*ptr);
        
    }
    return 0;
}

void ValueFunction(Mammal MammalValue){
    MammalValue.Speak();
}

void PtrFunction(Mammal *pMammal){
    pMammal->Speak();
}

void RefFunction(Mammal & rMammal){
    rMammal.Speak();
}

