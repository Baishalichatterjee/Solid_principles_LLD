#include <iostream>
using namespace std;

/*

1. INTERFACE (Abstraction)

(I - Interface Segregation)
(D - Dependency Inversion)
*/
class Notification {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification() {}
};

/*

2. LOW-LEVEL MODULES
(S - Single Responsibility)
(L - Liskov Substitution)

*/
class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class WhatsAppNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending WhatsApp Message: " << message << endl;
    }
};

/*

3. HIGH-LEVEL MODULE
(O - Open/Closed)
(D - Dependency Inversion)

*/
class NotificationService {
private:
    Notification* notification;

public:
    NotificationService(Notification* notification) {
        this->notification = notification;
    }

    void notify(const string& message) {
        notification->send(message);
    }
};

/*

4. CLIENT CODE

*/
int main() {
    EmailNotification email;
    SMSNotification sms;
    WhatsAppNotification whatsapp;

    NotificationService emailService(&email);
    NotificationService smsService(&sms);
    NotificationService whatsappService(&whatsapp);

    emailService.notify("Welcome to SOLID Principles!");
    smsService.notify("Your OTP is 1234");
    whatsappService.notify("Meeting at 10 AM");

    return 0;
}
