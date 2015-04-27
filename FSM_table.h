#ifndef __FSM_TABLE__
#define __FSM_TABLE__

const FSM_elem FSM_table[ST_JP + 1][ST_JP + 1] = {
#define _p_ parse
#define _r_ record
#define _e_  FSM_exit
    {{ST_END,_e_} ,{ST_RPUSH,_p_} ,{ST_PUSH,_p_} ,{ST_POP,_p_} ,{ST_ADD,_p_ },
     {ST_SUB,_p_} ,{ST_MUL,_p_  } ,{ST_DIV,_p_ } ,{ST_OUT,_p_} ,{ST_CALL,_p_},
     {ST_RET,_p_} ,{ST_JE,_p_   } ,{ST_JNE,_p_ } ,{ST_JB,_p_ } ,{ST_JNB,_p_ },
     {ST_JA,_p_ } ,{ST_JNA,_p_  } ,{ST_INP,_p_ } ,{ST_JP,_p_}} , 
                                                
    {{ST_END,_e_} ,{ST_RPUSH,_p_} ,{ST_PUSH,_p_} ,{ST_POP,_p_} ,{ST_ADD,_p_ },
     {ST_SUB,_p_} ,{ST_MUL,_p_  } ,{ST_DIV,_p_ } ,{ST_OUT,_p_} ,{ST_CALL,_p_},
     {ST_RET,_p_} ,{ST_JE,_p_   } ,{ST_JNE,_p_ } ,{ST_JB,_p_ } ,{ST_JNB,_p_ },
     {ST_JA,_p_ } ,{ST_JNA,_p_  } ,{ST_INP,_p_ } ,{ST_JP,_p_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}}, 
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}},
                                                
    {{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_},
     {ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_} ,{ST_WT,_r_}} 
    
#undef _p_
#undef _e_
#undef _r_
};
#endif
