#include <stdio.h>
#include <stdlib.h>
#include "intel_hex.h"
#include "FSM.h"
#include "interrupt_table.h"

int main(int argc, char* argv[]){
    FILE* inp_file;
    FILE* out_file;
    byte* inp_buf = NULL;
    int inp_buf_size = 0;
    int out_buf_size = 0;
    char* hex_buf = NULL;
    int hex_buf_size = 0;
    int i = 0;
    byte* out_buf = NULL;

    if (argc == 0){
        
        printf("Too few arguments\n");
        return 1;
        
    }
    
    if (argc == 1){
        
        printf("No output file\n");
        return 1;
        
    }
    
    inp_file = fopen(argv[1], "rb");

    if (inp_file == NULL){

        printf("Can't open file\n");
        return 3;

    }

    fseek(inp_file, 0, SEEK_END);
    inp_buf_size = ftell(inp_file);

    if (inp_buf_size <= 0) {

        printf("Incorrect file\n");
        return 2;

    }

    inp_buf = (byte*) calloc (inp_buf_size, sizeof(byte));

    if (inp_buf == NULL){

        printf("No memory\n");
        return 4;

    }
    
    rewind(inp_file);

    if (inp_buf_size > fread(inp_buf, sizeof(char), inp_buf_size, inp_file)){

            printf("Incorrect file\n");
            return 2;

    }

    out_buf_size = inp_buf_size * 10;
    out_buf = (unsigned char*) calloc (out_buf_size, sizeof(unsigned char)); 

    if (out_buf == NULL){

        printf("No memory\n");
        return 4;

    }
    
    for (i = 0;i < interrupt_table_size; ++i) {
        
        *out_buf = interrupt_table[i];
        ++out_buf;

    }

    out_buf_size = FSM_start(inp_buf + 2, inp_buf_size, 
                             out_buf, out_buf_size);

    FSM_start(inp_buf + 2, inp_buf_size, out_buf, out_buf_size);
    
    out_buf_size = FSM_start(inp_buf + 2, inp_buf_size, 
                             out_buf, out_buf_size);

    out_buf -= interrupt_table_size;

    for (i = 0; i < out_buf_size + interrupt_table_size; ++i){

        printf("%02X ", out_buf[i]);

    }

    hex_buf_size = 3000;
    hex_buf = (char*) calloc (hex_buf_size, sizeof(char));
    
    if (hex_buf == NULL){

        printf("No memory\n");
        return 4;
        
    }

    hex_buf_size = bin2intel_hex(out_buf, hex_buf, 
                 out_buf_size + interrupt_table_size + 1);

    
    out_file = fopen(argv[2], "w+b");

    fwrite(hex_buf, sizeof(char), hex_buf_size
           , out_file);
          

    fclose(out_file);
    fclose(inp_file);
    
    free(hex_buf);
    free(inp_buf);
    free(out_buf);
    
    printf("Translation complete!\n");
    
    return 0;
}
