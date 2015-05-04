#ifndef __FSM__
#define __FSM__
typedef unsigned char byte;

extern const int ENDIAN; // 1 - little endian, 0 - big endian

extern enum commands{
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

extern const char* stack_proc2avr[];

enum arg_types {
    NO_ARGS,
    CONST,
    REG,
    ADR
};

extern const int arg_type[];

extern const int command_size[];

extern const char* stack_proc2avr[]; 

typedef struct {
    int next_state;
    int (*action) ();
} FSM_elem;

int adr_convert(int* adr_table, int inp_buf_size, byte* inp_buf,
				 const int* command_size);

int FSM_start(byte* inp_buf, int inp_buf_size, byte* out_buf, 
              int out_buf_size);


enum state {
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

int record();

int parse();

int FSM_exit();

#endif
