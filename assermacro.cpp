#define DEBUG
#include <iostream>

using namespace std;

#ifndef DEBUG
    #define ASSERT(x)
#else
    #define ASSERT(x) \
        if (!(x)) \
        {\
            cout<<"Error ! Assert "<<#x<<"Failed\n"; \
            cout<<" on line "<<__LINE__<<"\n"; \
            cout<<" in file "<<__FILE__<<"\n"; \
        }
#endif

int main(){
    int x=5;
    cout<<"First assert: \n";
    ASSERT(x==5);
    cout<<"\n Second Assert: \n";
    ASSERT(x != 5);
    cout<<"\n Done \n";
    return 0;
}