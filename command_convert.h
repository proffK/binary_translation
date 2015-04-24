#include "/StekProc/commands.h"

const char* stack_proc2avr[SIN] {
    "1110kkkkttttkkkk"
    "1001001ttttt1111", //RPUSH == ldi temp, const
                        //         push temp
                        //         
    "1001001rrrrr1111", //PUSH  == push reg
                        //
    "1001000rrrrr1111", //POP   == pop reg
                        //
    "1001000ttttt1111"  //ADD   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000011tTttttTTTT"  //         add temp1, temp2
    "1001001TTTTT1111", //         push temp1
                        //
    "1001000ttttt1111"  //SUB   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000110tTttttTTTT"  //         sub temp1, temp2
    "1001001TTTTT1111", //         push temp1
                        //
    

    
