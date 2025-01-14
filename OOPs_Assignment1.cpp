#include<iostream>
#include<string>
using namespace std;

class Student
{
    public:
        string Name;
        int RollNo;
        string Course;
        int age;
};

int main()
{
    Student st1, st2, st3;
    st1.Name = "Vivek";
    st1.RollNo = 26;
    st1.Course = "BTech";
    st1.age = 20;

    st2.Name = "Rashi";
    st2.RollNo = 36;
    st2.Course = "BTech";
    st2.age = 20;

    st3.Name = "Vipin";
    st3.RollNo = 106;
    st3.Course = "BSC";
    st3.age = 20;

    cout<<"Student-1 details: \n";
    cout<< st1.Name<<endl<<st1.RollNo<<endl<<st1.Course<<endl<<st1.age<<"\n\n";
    cout<<"Student-2 details: \n";
    cout<< st2.Name<<endl<<st2.RollNo<<endl<<st2.Course<<endl<<st2.age<<"\n\n";
    cout<<"Student-3 details: \n";
    cout<< st3.Name<<endl<<st3.RollNo<<endl<<st3.Course<<endl<<st3.age<<"\n\n";

    return 0;
}