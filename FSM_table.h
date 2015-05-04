#ifndef __FSM_TABLE__
#define __FSM_TABLE__

const FSM_elem FSM_table[ST_JP + 1][ST_JP + 1] = {
#define _p_ parse
#define _r_ record
#define _e_  FSM_exit

#define WAIT_STR  {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},\
                   {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},\
                   {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},\
                   {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}

    {{ST_END,_e_} ,{ST_RPUSH,_p_} ,{ST_PUSH,_p_} ,{ST_POP,_p_} ,{ST_ADD,_p_ },
     {ST_SUB,_p_} ,{ST_MUL,_p_  } ,{ST_DIV,_p_ } ,{ST_OUT,_p_} ,{ST_CALL,_p_},
     {ST_RET,_p_} ,{ST_JE,_p_   } ,{ST_JNE,_p_ } ,{ST_JB,_p_ } ,{ST_JNB,_p_ },
     {ST_JA,_p_ } ,{ST_JNA,_p_  } ,{ST_INP,_p_ } ,{ST_JP,_p_}} ,  // ST_INIT
                                                
    {{ST_END,_e_} ,{ST_RPUSH,_p_} ,{ST_PUSH,_p_} ,{ST_POP,_p_} ,{ST_ADD,_p_ },
     {ST_SUB,_p_} ,{ST_MUL,_p_  } ,{ST_DIV,_p_ } ,{ST_OUT,_p_} ,{ST_CALL,_p_},
     {ST_RET,_p_} ,{ST_JE,_p_   } ,{ST_JNE,_p_ } ,{ST_JB,_p_ } ,{ST_JNB,_p_ },
     {ST_JA,_p_ } ,{ST_JNA,_p_  } ,{ST_INP,_p_ } ,{ST_JP,_p_}},  // ST_WT
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}, 
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, //ST_END
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_PKPO,_p_} ,{ST_WT,_r_}, 
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, //ST_PUSHK 

    {{ST_WT,_r_} ,{ST_PUPK,_p_} ,{ST_PUPU,_p_} ,{ST_PUPO,_p_} ,{ST_WT,_r_}, 
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_PUOU,_p_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, //ST_PUSH
                                                
    WAIT_STR , // ST_POP 
    WAIT_STR , // ST_ADD 
    WAIT_STR , // ST_SUB 
    WAIT_STR , // ST_MUL 
    WAIT_STR , // ST_DIV 
    WAIT_STR , // ST_OUT 
    WAIT_STR , // ST_CALL
    WAIT_STR , // ST_RET 
    WAIT_STR , // ST_JE  
    WAIT_STR , // ST_JNE 
    WAIT_STR , // ST_JB  
    WAIT_STR , // ST_JNB 
    WAIT_STR , // ST_JA  
    WAIT_STR , // ST_JNA 
    WAIT_STR , // ST_INP
    WAIT_STR ,
    WAIT_STR ,
    WAIT_STR ,
	{{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_PPJN,_p_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}},
    WAIT_STR , 
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_UKSU,_p_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_PKJN,_p_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
    WAIT_STR ,
    WAIT_STR ,
    WAIT_STR 
#undef _p_
#undef _e_
#undef _r_
#undef WAIT_STR
};
#endif
