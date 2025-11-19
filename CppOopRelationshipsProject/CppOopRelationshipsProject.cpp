#include <iostream>
#include <memory>

// Composition
class Engine
{
public:
    Engine() { std::cout << this << " Engine construct\n"; }
    ~Engine() { std::cout << this << " Engine destruct\n"; }
};
class Car
{
    int speed;
    Engine engine;
public:
    Car() { std::cout << this << " Car construct\n"; }
    ~Car() { std::cout << this << " Car destruct\n"; }
};

// Agregation
class Employee
{
public:
    Employee() { std::cout << "Employee construct\n"; }
    ~Employee() { std::cout << "Employee destruct\n"; }
};
class Company
{
    Employee* employee;
public:
    Company(Employee* employee = nullptr) 
        : employee{ employee }
    { std::cout << "Company construct\n"; }

    ~Company() { std::cout << "Company destruct\n"; }
};

// Association
class Doctor;
class Patient
{
    Doctor* doctor;
};
class Doctor
{
    Patient* patient;
};

// Dependeces
class Fraction
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

void CompositionExample();
void AgregationExample();

class Shape
{
public:
    /*Shape() { std::cout << this << " Shape construct\n"; }
    ~Shape() { std::cout << this << " Shape destruct\n"; }*/
    virtual double Square() = 0;
};
//class Figure
//{
//public:
//    Figure() { std::cout << this << " Figure construct\n"; }
//    ~Figure() { std::cout << this << " Figure destruct\n"; }
//};
class Rectangle : public Shape 
{
    double width;
    double height;
public:
    Rectangle(double width = 0, double height = 0)
        : width{ width }, height{ height } {}
    double Square() override
    {
        return width * height;
    }
    /*Rectangle() { std::cout << this << " Rectangle construct\n"; }
    ~Rectangle() { std::cout << this << " Rectangle destruct\n"; }*/
};

class Circle : public Shape
{
    double radius;
public:
    Circle(double radius = 0)
        : radius{ radius } {}
    double Square() override
    {
        return 3.1415 * radius * radius;
    }
};

class Ellipse : public Shape
{

};

class IPrintable
{
public:
    virtual void Print() = 0;
};


//class Square : public Rectangle
//{
//public:
//    Square() { std::cout << this << " Square construct\n"; }
//    ~Square() { std::cout << this << " Square destruct\n"; }
//};

class Message
{
protected:
    std::string text;
public:
    Message() : Message("") {}
    Message(std::string text) : text{ text } {};

    virtual void Show()
    {
        std::cout << "Message: " << text << "\n";
    }
};

class SmsMessage : public Message
{
protected:
    std::string phone;
public:
    SmsMessage() : SmsMessage("", "") {}
    SmsMessage(std::string text, std::string phone) 
        : Message(text), phone{ phone } {};

    void Show()
    {
        std::cout << "Sms to " << phone << ":\n\t";
        Message::Show();
    }
};
int main()
{
    /*Message message("Hello world");
    message.Show();*/

    /*SmsMessage smsMessage("Hello people", "999");
    smsMessage.Show();

    Message message = smsMessage;
    message.Show();*/

    /*Message* message = new Message("Hello world");
    message->Show();

    SmsMessage* smsMessage = new SmsMessage("Hello people", "000");
    smsMessage->Show();

    message = smsMessage;
    message->Show();*/
    
    Shape* shape;
    
    /*shape = new Rectangle(20, 30);
    std::cout << shape->Square() << "\n";

    shape = new Circle(20);
    std::cout << shape->Square() << "\n";*/

    Shape* shapes[3];
    shapes[0] = new Rectangle(30, 10);
    shapes[1] = new Circle(30);
    shapes[2] = new Rectangle(15, 26);

    for(int i{}; i < 3; i++)
        std::cout << shapes[i]->Square() << "\n";
}

void CompositionExample()
{
    std::cout << "start codes...\n";

    {
        Engine engine;
    }
    std::cout << "other codes...\n";

    {
        Car car;
    }
    std::cout << "final codes...\n";
}

void AgregationExample()
{
    //std::unique_ptr<Employee> eptr(new Employee());
    //Employee* employee = new Employee;
    Company company(new Employee());
}
