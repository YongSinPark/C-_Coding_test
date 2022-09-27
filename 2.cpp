#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Led
{
private:
    char led[10][5] = {"led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8"};
    char state[10];
public:
    Led();
    virtual ~Led();
    void Led_init();
    void Led_state();
    void Led_print();
    void Led_onoff(int led, int onoff);
    void Led_all_off();
    void Led_all_on();
};

Led::Led()
{
}
Led::~Led()
{

}

void Led::Led_all_on()
{
    for(int i = 0; i < 8; i++)
        {
            state[i] = 1;
        }
}

void Led::Led_all_off()
{
    for(int i = 0; i < 8; i++)
        {
            state[i] = 0;
        }
}
void Led::Led_state()
{
    string str;
    cout << "Input led_state : " ;
    cin >> str;
    if(str == "ledallon")
    {
        Led_all_on();
    } 
    if(str == "ledalloff")
    {
        Led_all_off();
    }
    if(str == "led1on")
    {   
        Led_all_off();
        Led_onoff(1,1);
    }
    if(str == "led1off")
    {
        Led_all_on();
        Led_onoff(1,0);
    }
    if(str == "led2on")
    {
        Led_all_off();
        Led_onoff(2,1);
    }
    if(str == "led2off")
    {
        Led_all_on();
        Led_onoff(2,0);
    }
    if(str == "led3on")
    {
        Led_all_off();
        Led_onoff(3,1);
    }
    if(str == "led3off")
    {
        Led_all_on();
        Led_onoff(3,0);
    }
    if(str == "led4on")
    {
        Led_all_off();
        Led_onoff(4,1);
    }
    if(str == "led4off")
    {
        Led_all_on();
        Led_onoff(4,0);
    }
    if(str == "led5on")
    {
        Led_all_off();
        Led_onoff(5,1);
    }
    if(str == "led5off")
    {
        Led_all_on();
        Led_onoff(5,0);
    }
    if(str == "led6on")
    {
        Led_all_off();
        Led_onoff(6,1);
    }
    if(str == "led6off")
    {
        Led_all_on();
        Led_onoff(6,0);
    }
    if(str == "led7on")
    {
        Led_all_off();
        Led_onoff(7,1);
    }
    if(str == "led7off")
    {
        Led_all_on();
        Led_onoff(7,0);
    }
    if(str == "led8on")
    {
        Led_all_off();
        Led_onoff(8,1);
    }
    if(str == "led8off")
    {
        Led_all_on();
        Led_onoff(8,0);
    }
}

void Led::Led_onoff(int led, int onoff)
{
    state[led-1] = onoff;
}

void Led::Led_print()
{
    cout << "============Led state============" << endl;
        for(int i = 0; i < 8; i++)
        {
            cout << led[i] << " ";
        }
        cout << endl;
        cout << endl;
        for(int i = 0; i < 8; i++)
        {
            if( state[i] == 1) cout << "ON" << " ";
            if( state[i] == 0) cout << "OFF" << " ";
        }
        cout << endl;
}

int main()
{
    Led* led = new Led();
    
    while(1)
    {
        led->Led_state();
        led->Led_print();
    }
    return 0;
}
