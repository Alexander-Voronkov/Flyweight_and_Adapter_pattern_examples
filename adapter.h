#pragma once
#include<iostream>
#include<string>


using namespace std;


class StandartPhone
{
public:
    string screen = "малий старий екран";
    virtual void getused() = 0;
};

class Nokia: public StandartPhone 
{
public:
    void getused() override
    {
        cout << "Використовується нокіа, у якого "+this->screen << endl;
    }
};

class User
{
public:
    void use(StandartPhone* sp)
    {
        sp->getused();
    }
};

class SmartPhone
{
public:
    string smartscreen = "сенсорний екран";
    virtual void playgames() = 0;
};

class Samsung : public SmartPhone
{
public:
    void playgames()override
    {
        cout << "Використовуєтся Самсунг, на якому можна грати в ігри та який має "+this->smartscreen << endl;
    }
};


class StandartToSmartPhoneAdapter : public SmartPhone
{
    StandartPhone * sp;

public:
    StandartToSmartPhoneAdapter(StandartPhone* stph) { sp = stph; }
    void playgames() override
    {
        sp->getused();
    }
};
