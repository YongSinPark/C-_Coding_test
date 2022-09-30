#include <iostream>

union U{
    unsigned char led;
    struct a{
        unsigned led1:1;
        unsigned led2:1;
        unsigned led3:1;
        unsigned led4:1;
        unsigned led5:1;
        unsigned led6:1;
        unsigned led7:1;
        unsigned led8:1;
    };
} u;

int main()
{
    u.led = 0xff;

    printf("%x\n", u.led);

    return 0;
}