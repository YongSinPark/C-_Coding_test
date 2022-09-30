#include <iostream>
#include <string>
#include <vector>

using namespace std;

union 
{
    unsigned char led;
    struct {
        unsigned b0:1;
        unsigned b1:1;
        unsigned b2:1;
        unsigned b3:1;
        unsigned b4:1;
        unsigned b5:1;
        unsigned b6:1;
        unsigned b7:1;
    } a;
} u;

int main()
{
    u.led = 0xff;
    printf("u.led ==> %0x\n", u.led);
    printf("u.a.b0 ==> %d\n", u.a.b0);

    u.a.b0 = 0;
    printf("u.led ==> %0x\n", u.led);
    u.a.b7 = 0;
    printf("u.led ==> %0x\n", u.led);

    return 0;
}