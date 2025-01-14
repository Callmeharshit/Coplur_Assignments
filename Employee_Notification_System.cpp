#include<iostream>
#include<string>
using namespace std;

class Notification 
{
    public:
        virtual void send(const string& message) = 0; 
        virtual ~Notification() = default; // destructor of 
};


class email_Notification : public Notification 
{
    public:
        void send(const string& message) override 
        {
            cout << "Sending Email: " << message << endl;
        }
};

class SMS_Notification : public Notification 
{
    public:
        void send(const string& message) override 
        {
            cout << "Sending SMS: " << message << endl;
        }
};

class push_Notification : public Notification 
{
    public:
        void send(const string& message) override 
        {
            cout << "Sending Push Notification: " << message << endl;
        }
};

int main() 
{
    // Creation of objects for class Notification
    email_Notification email;
    SMS_Notification sms;
    push_Notification push;

    string policyMessage = "Terms and conditions may apply.";
    string eventMessage = "Wednesday";
    string alertMessage = "Hello!";

    email.send(policyMessage);
    sms.send(eventMessage);
    push.send(alertMessage);

    return 0;
}
