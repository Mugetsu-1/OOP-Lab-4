#include <iostream>
using namespace std;

class Patient{
    protected:
        int patient_id;
        char name[20];
        
      
};

class Ward:protected Patient {
    protected:
    char type[20];
    int bed_no;
    
  
    
};

class Payment:private Ward{
    private:
    int bill_no;
    int total_amount;
    
    public:
     void getinfo(){
            cout<<"Enter the patient name and ID \n";
            cin>>name>>patient_id;
    
        };
        
      void getdata(){
        cout<<"Enter the ward type \n";
        cin>>type;
        cout<<"Enter the bed number\n";
        cin>>bed_no;
    };
    
    void getdata1(){
        cout<<"Enter the bill number\n";
        cin>>bill_no;
        cout<<"Enter the total amount\n";
        cin>>total_amount;
    };
    
    void display(){
         cout<<"Patient Details";
        cout<<"Patient Name:"<<name<<"\n";
        cout<<"Patient ID:"<<patient_id<<"\n";
        cout<<"Ward Type:"<<type<<"\n";
        cout<<"Bed number:"<<bed_no<<"\n";
        cout<<"Bill_number:"<<bill_no<<"\n";
        cout<<"Total bill Amount:"<<total_amount<<"\n";
    }
    
};
int main() {
   Payment p1;
   p1.getinfo();
   p1.getdata();
   p1.getdata1();
   p1.display();
   
   

    return 0;
}
