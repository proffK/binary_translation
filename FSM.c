#include "FSM.h"
#include <stdlib.h>
#include <stdio.h>
#include "FSM_table.h"

extern const int command_size[];

byte* cur_inp_byte = NULL;

byte* begin_inp_byte = NULL;

byte* cur_out_byte  = NULL; 

int cur_state = 0;

byte reg_list[2] = {};

int const_list[2] = {};

int addr_list[2] = {};

const byte temp_list[2] = {30 , 31};

int* adr_table = NULL;

int FSM_start(byte* inp_buf, int inp_buf_size, byte* out_buf, 
              int out_buf_size) {

    int temp_state = 0;
    byte* tempinp_byte = 0;
    byte* tempout_byte = 0;
    int exit_code = 0;
    static int repeat_flag = 1;
    
    begin_inp_byte = cur_inp_byte = inp_buf;
    cur_out_byte = out_buf;
    cur_state = ST_INIT;

    
    if (repeat_flag) {
        adr_table = (int*) calloc (inp_buf_size, sizeof(int));
        repeat_flag = 0;
    }

    while (!exit_code) {

        if (*cur_inp_byte == 255) FSM_exit();
        
        temp_state = FSM_table[cur_state]
                              [(signed char)*cur_inp_byte + 1].next_state;
        tempinp_byte = cur_inp_byte;
        
        exit_code = FSM_table[cur_state]
                             [(signed char)*cur_inp_byte + 1].action();


        cur_state = temp_state;

        adr_table[tempinp_byte - inp_buf] = (cur_out_byte - out_buf);
        
        //printf("...%d->%d\n",temp_byte - inp_buf,
        //       adr_table[temp_byte - inp_buf]); 

    }

    return cur_out_byte - out_buf;

}

int record(){

    cur_out_byte += command_convert(stack_proc2avr,
                                  cur_out_byte, cur_state - 3);

    return 0;

}

int parse(){
   static cur_reg = 0;

   switch (arg_type[*cur_inp_byte]){

       case NO_ARGS:
           ++cur_inp_byte;
           break;
       case CONST:
           ++cur_inp_byte;
           const_list[0] = *cur_inp_byte;
           ++cur_inp_byte;
           break;
       case REG:
           ++cur_inp_byte;
           if (cur_state == ST_PUPU) {
			   reg_list[cur_reg] = *cur_inp_byte;
			   cur_reg = 0;
		   }
		   else {
			   cur_reg = 0;
			   reg_list[cur_reg] = *cur_inp_byte;
		   }
           if (cur_state == ST_PUSH) cur_reg = 1;
           ++cur_inp_byte;
           break;
       case ADR:
           ++cur_inp_byte;
           addr_list[0] = (adr_table[*cur_inp_byte] - 
                           adr_table[cur_inp_byte - 1 - begin_inp_byte]) / 2;
           //printf("/%d\n", adr_table[*cur_inp_byte]);     //radari2
           //printf("///%d\n", adr_table[cur_inp_byte - 1 - begin_inp_byte]);
           //printf("//////%d\n", addr_list[0]);
           ++cur_inp_byte;
           break;
       default:
           return 1;

   }
   
   return 0;

}


int FSM_exit() {

    return 1;

}




