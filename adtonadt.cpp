//deriving adt class from a different adt class
//            Animal
//            /    \
//      Mammal      Fish
//       /   \
//  Horse    Dog

#include <iostream>
using namespace std;

enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

class Animal{
    public:
        Animal(int);
        virtual ~Animal(){
            cout<<"Animal destructor\n";
        }
        virtual int GetAge() const{
            return itsAge;
        }
        virtual void SetAge(int age){
            itsAge = age;
        }
        virtual void Sleep() const = 0; // this is how we declare a class to be abstract type (one or more needed)
        virtual void Eat() const = 0; //each of the virtual functions from the adt class should be implemented in derived class
        virtual void Reproduce() const = 0;
        virtual void Move() const = 0;
        virtual void Speak() const = 0;
    private:
    int itsAge;
};

Animal::Animal(int age):itsAge(age){
    cout<<"Animal constructor..\n";
}

// mammal inherits mammal
class Mammal:public Animal{
    public:
        Mammal(int age):Animal(age){
            cout<<"Mammal constructor..\n";
        }
        virtual ~Mammal() {
            cout<<"Mammal destructor..\n";
        }
        virtual void Reproduce() const{
            cout<<"Mammal reproduction depicted..\n";
        }
};

class Fish:public Animal{
    public:
        Fish(int age):Animal(age){
            cout<<"Fish constructor..\n";
        }
        virtual ~Fish(){
            cout<<"Fish destructor..\n";
        }
        virtual void Sleep() const{
            cout<<"Fish sleeping..\n";
        }
        virtual void Eat() const{
            cout<<"Fish eating..\n";
        }
        virtual void Reproduce() const{
            cout<<"Fish reproducing ..\n";
        }
        virtual void Move() const {
            cout<<"fish swimming..\n";
        }
        virtual void Speak() const{}
};

class Horse: public Mammal{
    public:
        Horse(int age, COLOR color): Mammal(age), itsColor(color){
            cout<<"Horse constructor ..\n";
        }
        virtual ~Horse(){
            cout<<"Horse destructor..\n";
        }
        virtual void Speak() const{
            cout<<"Horse Speaking..\n";
        }
        virtual COLOR GetItsColor() const{
            return itsColor;
        }
        virtual void Sleep() const{
            cout<<"Horse sleeping..\n";
        }
        virtual void Eat()const{
            cout<<"Horse eating..\n";
        }
        virtual void Move() const{
            cout<<"Horse running..\n";
        }

        //no reproduce, uses Mammals reproduce method

    protected:
        COLOR itsColor;
};

class Dog: public Mammal{
    public:
        Dog(int age, COLOR color):  Mammal(age), itsColor(color){
            cout<<"Dog constructor..\n";
        }
        virtual ~Dog() {
            cout<<"Dog destructor..\n";
        }
        virtual void Speak() const{
            cout<<"Dog speaking..\n";
        }
        virtual void Eat() const{
            cout<<"Dog Eating..\n";
        }
        virtual void Sleep() const{
            cout<<"Dog Sleeping..\n";
        }
        virtual void Move() const{
            cout<<"Dog running..\n";
        }
        virtual void Reproduce() const{
            cout<<"Dog reproducing..\n";
        }
    protected:
        COLOR itsColor;
};

int main(){
    Animal *pAnimal = 0; //null pointer to animal object
    int choice;
    bool fQuit = false;

    while(1){
        cout<<"(1)Dog (2)Horse (3)Fish (0)Quit";
        cin>>choice;
        switch(choice){
            case 1:
                pAnimal = new Dog(5, Brown);
                break;
            case 2:
                pAnimal = new Horse(4, Black);
                break;
            case 3:
                pAnimal = new Fish(5);
                break;
            default:
                fQuit = true;
                break;
        }
        if (fQuit)
            break;
        pAnimal->Speak();
        pAnimal->Eat();
        pAnimal->Reproduce();
        pAnimal->Move();
        pAnimal->Sleep();
        delete pAnimal;
        cout<<"\n";
    }
    return 0;

}