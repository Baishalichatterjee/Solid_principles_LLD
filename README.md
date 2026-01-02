🧱 Problem Statement

We want to send notifications via different channels (Email, SMS, WhatsApp, etc.) while following SOLID principles.

✅ SOLID Principles Covered
Principle	How it’s followed

S – Single Responsibility	Each class has only one reason to change
O – Open/Closed	New notification types can be added without modifying existing code
L – Liskov Substitution	Derived classes can replace base class safely
I – Interface Segregation	Small, focused interfaces
D – Dependency Inversion	High-level module depends on abstraction, not concrete classes



🔍 How This Code Follows SOLID (Quick Explanation)

🟢 S – Single Responsibility

EmailNotification → only sends emails

SMSNotification → only sends SMS

NotificationService → only handles notification logic

🟢 O – Open/Closed

Want to add PushNotification?

class PushNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending Push Notification: " << message << endl;
    }
};


✅ No existing code modified

🟢 L – Liskov Substitution

Any Notification child can replace Notification* safely

🟢 I – Interface Segregation

Notification interface has only one responsibility

No unnecessary methods

🟢 D – Dependency Inversion

NotificationService depends on abstraction (Notification), not concrete classes
