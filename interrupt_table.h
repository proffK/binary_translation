#ifndef __INTERRUPT__
#define __INTERRUPT__

const byte interrupt_table[] = {
    0X19, 0XC0,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X18, 0X95,
    0X0F, 0XEF,
    0X0D, 0XBF,
    0X02, 0XE0,
    0X0E, 0XBF

}; 

const int interrupt_table_size = 58;

#endif
