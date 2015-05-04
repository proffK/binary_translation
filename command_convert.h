
typedef unsigned char byte;

const int ENDIAN = 1; // 1 - little endian, 0 - big endian

extern enum state {
   ST_INIT,
   ST_WT,      //WAIT
   ST_END,
   ST_RPUSH,
   ST_PUSH, 
   ST_POP ,
   ST_ADD ,
   ST_SUB ,
   ST_MUL ,
   ST_DIV ,
   ST_OUT ,
   ST_CALL,
   ST_RET ,
   ST_JE  ,
   ST_JNE ,
   ST_JB  ,
   ST_JNB ,
   ST_JA  ,
   ST_JNA ,
   ST_INP ,
   ST_PKPO,
   ST_PUPO,
   ST_PUOU,
   ST_PUPU,
   ST_PPJN,
   ST_PUPK,
   ST_PKJN,
   ST_UKSU,
   ST_JP  
};


enum commands{
    END = -1, 
    RPUSH = 0,  
	PUSH = 1,   
	POP = 2,    
	ADD = 3,    
	SUB = 4,    
	MUL = 5,    
	DIV = 6,    
	OUT = 7,    
	CALL = 8,   
	RET = 9,    
	JE = 10,    
	JNE = 11,   
	JB = 12,    
	JNB = 13,   
	JA = 14,    
	JNA = 15,   
	INP = 16,   
	JP = 17
};

const char* stack_proc2avr[ST_JP + 1] = {
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
    "000011TtTTTTtttt"  //         add temp2, temp1
    "1001001TTTTT1111", //         push temp1
                        //
    "1001000ttttt1111"  //SUB   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000110TtTTTTtttt"  //         sub temp2, temp1
    "1001001TTTTT1111", //         push temp1
                        //
    "1001000ttttt1111"  //MUL   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "1001001000001111"  //         push r0
    "1001001000011111"  //         push r1
    "100111tTttttTTTT"  //         mul temp1, temp2
    "00000001TTTT0000"  //         movw temp1:temp2, r0:r1
    "1001000000011111"  //         pop r1
    "1001000000001111"  //         pop r0
    "1001001ttttt1111"  //         push temp1
    "1001001TTTTT1111", //         push temp2
                        //
    "0000000000000000", //DIV   == nop (no div in avr)
                        //
    "1001000ttttt1111"  //OUT   == pop temp1
    "10111kktttttkkkk", //         out const, temp1
                        //
    "1101aaaaaaaaaaaa", //CALL  == rcall relative_adress
                        //
    "1001010100001000", //RET   == ret
                        //
    "1001000ttttt1111"  //JE    == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000101tTttttTTTT"  //         cp temp1, temp2
    "111100aaaaaaa001", //         breq relative_adress
                        //
    "1001000ttttt1111"  //JNE   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000101tTttttTTTT"  //         cp temp1, temp2
    "111101aaaaaaa001", //         brne relative_adress
                        //
    "1001000ttttt1111"  //JB    == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000101tTttttTTTT"  //         cp temp2, temp1
    "111100aaaaaaa000", //         brlo relative_adress
                        //
    "1001000ttttt1111"  //JNB   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000101tTttttTTTT"  //         cp temp2, temp1
    "111101aaaaaaa000", //         brsh relative_adress
                        //
    "1001000ttttt1111"  //JA    == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000101tTttttTTTT"  //         cp temp1, temp2
    "111100aaaaaaa000", //         brlo relative_adress
                        //
    "1001000ttttt1111"  //JNA   == pop temp1
    "1001000TTTTT1111"  //         pop temp2
    "000101tTttttTTTT"  //         cp temp1, temp2
    "111101aaaaaaa000", //         brsh relative_adress
                        //
    "10110kktttttkkkk"  //INP   == in const, temp1
    "1001001ttttt1111", //         push temp1
    
    "1110kkkkttttkkkk"  //PUSHK+POP == ldi temp, const
    "001011rtrrrrtttt", //             mov reg, temp

    "001011RrRRRRrrrr", //PUSH+POP  == mov reg1, reg2
    
    "10111kkrrrrrkkkk", //PUSH+OUT  == out port, reg1
    
    "1001001rrrrr1111"
    "1001001RRRRR1111", //PUSH+PUSH == push reg1, push reg2
    
	"000101RrRRRRrrrr"  //PUSH+PUSH+JNE = cp reg1, reg2
    "111101aaaaaaa001", //                brne relative_adress
    
    "1001001rrrrr1111"  //PUSH+PUSHK
    "1110kkkkttttkkkk"
    "1001001ttttt1111",
    
	"0011kkkkrrrrkkkk"  //PUSH+PUSHK+JNE
	"111101aaaaaaa001", 
	
	"001011trttttrrrr"  //                  mov temp ,reg
	"0101kkkkttttkkkk"  //PUSH+PUSHK+SUB == subi temp, const
	"1001001ttttt1111", //                  push temp

    "1100aaaaaaaaaaaa" //JP     == rjmp relative_adress

};

enum arg_types {
    NO_ARGS,
    CONST,
    REG,
    ADR
};

const int arg_type[JP + 1] = {

   CONST,   // RPUSH
   REG,     // PUSH 
   REG,     // POP  
   NO_ARGS, // ADD  
   NO_ARGS, // SUB  
   NO_ARGS, // MUL  
   NO_ARGS, // DIV  
   CONST,   // OUT  
   ADR,     // CALL 
   NO_ARGS, // RET  
   ADR,     // JE   
   ADR,     // JNE  
   ADR,     // JB   
   ADR,     // JNB  
   ADR,     // JA   
   ADR,     // JNA  
   CONST,   // INP  
   ADR      // JP  
};

const int command_size[ST_JP + 1] = {
            	
   0,
   0,
   0,
   4,       // RPUSH
   2,       // PUSH 
   2,       // POP  
   8,       // ADD  
   8,       // SUB  
   20,      // MUL  
   2,       // DIV  
   4,       // OUT  
   2,       // CALL 
   2,       // RET  
   8,       // JE   
   8,       // JNE  
   8,       // JB   
   8,       // JNB  
   8,       // JA   
   8,       // JNA  
   4,       // INP
   4,
   2,
   2,
   4,
   4,
   6,
   4,
   6,  
   2       // JP   
};

int command_convert(const char* convert_array[], byte* out_command,
                    int state);  
                    
int bin_str2byte(char* str, byte* out, const int endian); 


