
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


class Two{
   private:
        string Name;
        Two *ptr;
        static int N;
        static double Queue;
        static Two *TimePtr;
        static Two *FirstPtr;
        
       
       int Check(double Number){
          double Ost, y;
          Ost  = modf(Number, &y);
          if (Number > 0 && Ost == 0.0){
                  return 1;
          }
          return 0;
          }
    
        void AddPtr(Two *ptr){
            TimePtr->ptr = ptr;
        }
    
        void DelPtrFirst(){
            Two *Time = FirstPtr->ptr;
            
            FirstPtr = Time;
        }
   public:
    Two(string Name, double Queue){
        if (this->Queue > 0 ){
            cout << "Длина очереди уже задана, используйте другую инициализацию"<< endl;
        }
        else{
            if (Check(Queue)){
                this->Queue = Queue;
                this->Name = Name;
                N = 1;
                FirstPtr = this;
                TimePtr = this;
            }
            else {
                cout << "Длина очереди задана не корректно"<< endl;
            }
        }
    }
    
    Two(string Name){
        if (Check(Queue)){
            if (N < Queue){
                this-> Name = Name;
                AddPtr(this);
                TimePtr = this;
                N++;
            }
            else{
                this-> Name = Name;
                DelPtrFirst();
                AddPtr(this);
                TimePtr = this;
                
            }
        }
        else {
            cout << "Длина очереди задана не корректно"<< endl;
        }
    }
    
        int  GetQueue(){
            return Queue;
    }
    
   void printName(){
        cout<< Name<< endl;
    }
    
        static void PrintQueue(){
        Two *FirstLink = FirstPtr;
        int i = 0;
        string ForPrint;
        while(i != N){
            ForPrint =FirstLink->Name;
            cout << ForPrint << endl;
            FirstLink = FirstLink->ptr;
            i++;
        }
        
    }
    
    
   };


    int Two :: N;
    double Two :: Queue;
    Two* Two :: TimePtr;
    Two* Two :: FirstPtr;
