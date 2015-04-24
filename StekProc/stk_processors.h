#ifndef stk_processors
#define stk_processors
#include "m_stack.h"
#include <stdio.h>

/*!This struct is processor
 * \param regs - pointer of register array
 * \param stk - pointer of stack
 * \param data - pointer of code memory this processor
 * \param n_reg - number of registors
 */
typedef unsigned char byte;

typedef struct {
	byte* regs;
	stack* stk;
	byte* data;
	int data_size;
	int n_reg;
	int counter;
} processor; 

processor* processor_create(int stack_size, int n_reg, long buffer_size);

int processor_delete(processor* proc);

int P_add(processor* proc);

int P_sub(processor* proc);

int P_mul(processor* proc);

int P_div(processor* proc);

int P_sin(processor* proc);

int P_cos(processor* proc);

int P_pow(processor* proc);

int P_pop(processor* proc, int reg);

int P_push(processor* proc, int reg);

int P_rpush(processor* proc, byte val);

int P_sqrt(processor* proc);

int processor_is_valide(processor* proc);

/*! This function send error messenge in log file proc_log.txt
 */
int processor_dump(int const_err, processor* proc);

int processor_flash(processor* proc, byte* firmware, int firmware_size);

int processor_start(processor* proc, FILE* input_stream, FILE* output_stream);

#endif 
