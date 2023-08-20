//virtual inheritance and multiple inheritance

#include <iostream>

using namespace std;

typedef int HANDS;
enum COLOR { Red, Green, Yellow, White, Black, Brown};

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
    private:
        int itsAge;
};

Animal::Animal(int age):itsAge(age){
    cout<<"Animals constructor\n";
}

class Horse: virtual public Animal{
    public:
        Horse(COLOR color, HANDS height, int age);
        virtual ~Horse(){
            cout<<"Horse destructor..\n";
        }
        virtual void Whinny() const {
            cout<<"Whinny..\n";
        }
        virtual HANDS GetHeight() const{
            return itsHeight;
        }
        virtual COLOR GetColor() const{
            return itsColor;
        }
    protected:
        HANDS itsHeight;
        COLOR itsColor;
};

Horse::Horse(COLOR color, HANDS height, int age):
    Animal(age),
    itsColor(color),
    itsHeight(height){
        cout<<"Horse COnstructor \n";
    }

class Bird: virtual public Animal{
    public:
        Bird(COLOR color, bool migrates, int age);
        virtual ~Bird(){
            cout<<"Bird destructor..\n";
        }
        virtual void Chirp() const{
            cout<<"Chirp \n";
        }

        virtual void fly() const{
            cout<<"I can fly \n";
        }
        virtual COLOR GetColor()const{
            return itsColor;
        }
        virtual bool GetMigration() const{
            return itsMigration;
        }
        
    protected:
        COLOR itsColor;
        bool itsMigration;
};

Bird::Bird(COLOR color, bool migrates, int age):
Animal(age), // calling base class constructor
itsColor(color),
itsMigration(migrates){
    cout<<"Bird constructor..\n";
}

//multiple inheritance
class Pegasus: public Horse, public Bird{
    public:
        //overriding Whinny from horse
        void Chirp() const {
            Whinny();
        }
        Pegasus(COLOR, HANDS, bool, long, int);
        virtual ~Pegasus(){
            cout<<"Pegasus destructor..\n";
        }
        virtual long GetNumberBelievers() const{
            return itsNumberBelievers;
        }

        // using color from horse
        virtual COLOR GetColor() const{
            return Horse::itsColor;
        }
    private:
        long itsNumberBelievers;
};

Pegasus::Pegasus(COLOR acolor, HANDS hands, bool migrates, long NumBelieve, int age):
    Horse(acolor, hands, age),
    Bird(acolor, migrates, age),
    Animal(age*2),
    itsNumberBelievers(NumBelieve){
        cout<<"Pegasus constructor...\n";
    }

int main(){
    Pegasus *pPeg = new Pegasus(Red, 5, true, 10, 2);
    int age = pPeg->GetAge();
    cout<<"This pegasus is "<<age<<" years old \n";
    delete pPeg;
    return 0;
}