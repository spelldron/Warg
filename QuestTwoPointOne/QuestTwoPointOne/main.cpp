#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class One{
private:
    double Queue;
    string *MasQueue;
    
    int Check(double Number){
    double Ost, y;
    Ost  = modf(Number, &y);
    if (Number > 0 && Ost == 0.0){
            return 1;
    }
    return 0;
    }

public:
    template <size_t N>
    One(string (&MasQueue2)[N]){
        cout << sizeof(MasQueue2)/24 << endl;
        if ( Check(sizeof(MasQueue2)/ 24)){
            this->Queue = sizeof(MasQueue2)/ 24;
            this-> MasQueue = MasQueue2;
        }
    }

    int GetQueue(){
        return Queue;
    }
    
    void ChangeQueue(string Name){
        int i = 0;
        if(Check(Queue)){
            while(i != Queue-1){
                MasQueue[i]=MasQueue[i+1];
                i++;
            }
            MasQueue[i] = Name;
        }
        
    }
    
    template <size_t N>
    void ChangeQueue(string (&Names)[N]){
           int j = 0;
           if(Check(Queue)){
               while(j*24 != sizeof(Names)){
                   int i = 0;
                   while(i != Queue-1){
                       MasQueue[i]=MasQueue[i+1];
                       i++;
                   }
                   MasQueue[i] = Names[j];
                   j++;
                }
            }
         }
    
    void printQueue(){
        if (Check(Queue)){
            for(int i = 0; i<Queue; i++){cout<<MasQueue[i] << " ";};
            }
        }
};
