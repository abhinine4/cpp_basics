#include <iostream>

using namespace std;

enum BREED { GOLDEN, CARIN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal{
    // constructor and destructor
    public:
        Mammal();
        ~Mammal();

        // accessor
        int GetAge() const{
            return itsAge;
        }
        int GetWeight() const{
            return itsWeight;
        }

        void SetAge(int age){
            itsAge = age;
        }

        void SetWeight(int weight){
            itsWeight = weight;
        }

        // other methods
        void Speak() const{
            cout<<"Mammal Sound ! \n";
        }

        void Sleep() const{
            cout<<"shhhh. I'm sleeping. \n";
        }

    protected:
        int itsAge;
        int itsWeight;

};

Mammal::Mammal():itsAge(2), itsWeight(5){}
Mammal::~Mammal(){}

class Dog: public Mammal{
    public:
        //constructor and destructor
        Dog();
        ~Dog();

        //accessor
        BREED GetBreed() const{
            return itsBreed;
        }

        void SetBreed(BREED breed){
            itsBreed = breed;
        }

        // other methods
        void WagTail() const{
            cout<<"Tail wagging...\n";
        }

        void BegForFood() const{
            cout<<"Begging for food. \n";
        }

    private:
        BREED itsBreed;
};

Dog::Dog():itsBreed(CARIN){}
Dog::~Dog(){}

int main(){
    Dog fido;
    fido.Speak();
    fido.WagTail();
    cout<<"Fido is a "<<fido.GetBreed()<<" breed.\n";
    return 0;
}


