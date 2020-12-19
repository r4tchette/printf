// https://gist.github.com/Belgarion/80b6a178ac9b000d1d85210f9e08accb

#include <stdio.h>

int itoa_s(int value, char *buf) {
        int index = 0;
        int i = value % 10;
        if (value >= 10) {
                index += itoa_s(value / 10, buf);
        }
        buf[index] = i+0x30;
        index++;
        return index;
}

char *itoa(int value, char *buf) {
        int len = itoa_s(value, buf);
        buf[len] = '\0';
        return buf;
}

char *ftoa(float value, int decimals, char *buf) {
        int index = 0;
        // Handle negative values
        if (value < 0) {
                buf[index] = '-';
                index++;
                value = -value;
        }

        // Rounding
        float rounding = 0.5;
        for (int d = 0; d < decimals; rounding /= 10.0, d++);
        value += rounding;

        // Integer part
        index += itoa_s((int)(value), buf+index);
        buf[index++] = '.';

        // Remove everything except the decimals
        value = value - (int)(value);

        // Convert decmial part to integer
        int ival = 1;
        for (int d = 0; d < decimals; ival *= 10, d++);
        ival *= value;

        // Add decimal part to string
        index += itoa_s(ival, buf+index);
        buf[index] = '\0';
        return buf;
}

int main() {
        char buf[128];
        printf("Result %s\n", itoa(1234, buf));
        for (int i = 0; i < 128; buf[i]='x', i++);
        printf("Result %s\n", ftoa(-1234.999, 8, buf));
}
