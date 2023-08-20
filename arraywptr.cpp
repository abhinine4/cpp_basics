#include <iostream>

class CAT{
    public:
        CAT(){
            itsAge=1; 
            itsWeight=5;
        }
        ~CAT();
        int GetAge() const{
            return itsAge;
        }
        int GetWeight() const{
            return itsWeight;
        }

        void SetAge(int age) {
            itsAge = age;
        }
    private:
        int itsAge;
        int itsWeight;
};

CAT :: ~CAT(){

}

int main(){
    // new allocates memory in free space (heap)
    CAT * Family = new CAT[500];
    int i;
    for(i=0; i<500; i++){
        Family[i].SetAge(2*i+1);
    }

    for(int i=0; i<500; i++){
        std::cout<<"Cat #"<<i+1<<" : ";
        std::cout<<Family[i].GetAge() <<std::endl;
    }

    delete [] Family;
    return 0;
}