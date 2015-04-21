#ifndef __FSM__
#define __FSM__

typedef struct {
    int next_state;
    int (*action) ();
} FSM_elem;

const int temp_reg1 = 31;

const int temp_reg2 = 30;

int FSM_start(byte* inp_buf, int inp_buf_size, byte* out_buf, int out_buf_size, FSM_table table);

static int record();

static int parse();

static byte* opcode_decoder(const char* str_opcode);

#endif
