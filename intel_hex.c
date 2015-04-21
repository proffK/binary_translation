#include "intel_hex.h"
#include <stdio.h>

const char* first_hex_str = ":020000020000FC\x0D\n";

const int first_hex_str_size = 17;

const char* end_hex_str = ":00000001FF\x0d\n";

const int end_hex_str_size = 13;

const int byte_line_size = 16; 

enum intel_hex2bin_errno {
    CONV_OK,
    WRONG_SUM,
    INCORRECT_FORMAT,
    INCORRECT_CHAR
};

int intel_hex2bin_errno;

#define CONV_ERR(err)  intel_hex2bin_errno = err

int intel_hex2bin(char* inp_buf, byte* out_buf, int* inp_buf_size){
    
    #define ERR_LINE cur_char - inp_buf
    
    char* cur_char = inp_buf;
    byte data_counter = 0;
    byte sum = 0;
    int i = 0;

    cur_char += first_hex_str_size;
    CONV_ERR(CONV_OK);

    while (i < *inp_buf_size){
        int j = 0;
        if (*cur_char != ':'){
            CONV_ERR(INCORRECT_FORMAT);
            return ERR_LINE;
        }
        
        ++cur_char;
        data_counter = str_hex2byte(cur_char);

        if (data_counter == 0){
            *inp_buf_size = i + 1;
            return 0;
        }
        
        cur_char += 8; /* check !*/ 
        j = data_counter;
        
        while (j--){
            out_buf[i] = str_hex2byte(cur_char);
            ++i;
            cur_char += 2;
        }

        sum = (byte) ((int) chk_sum(out_buf + i - data_counter, data_counter)
                      + (i - 1) / 256 + i % 256);

        if ((byte) (0 - sum) != str_hex2byte(cur_char)){
            CONV_ERR(WRONG_SUM);   
            return ERR_LINE;
        }

        cur_char += 3;

        if (*cur_char != '\n'){
            CONV_ERR(INCORRECT_FORMAT);
            return ERR_LINE;
        }

        ++cur_char;
    }
    
    CONV_ERR(INCORRECT_FORMAT);

    return ERR_LINE;

    #undef ERR_LINE

}

byte str_hex2byte(char* cur_num){

    return char2hex(cur_num[0]) * 16 + char2hex(cur_num[1]);
    
}

byte char2hex(char inp){

    if ('0' <= inp && inp <= '9') return (inp - '0');

    if ('A' <= inp && inp <= 'F') return (inp - 'A' + 10);
    
    CONV_ERR(INCORRECT_CHAR);

    return 255;

}

byte chk_sum(byte* first_byte, int sum_size){

    byte sum = 0;

    while (sum_size--){
       sum += *(first_byte++);
    }

    return sum;

}

int bin_dump(byte* buf, unsigned long size, FILE* out){
    
   int i = 0;

   for (i = 0; i < size; ++i){ 
        
        if (i % byte_line_size == 0) fprintf(out, "\n%04d:", i);

        fprintf(out, "%02X ", buf[i]);
        
   }

   return 0;
}
#undef CONV_ERR

int bin2intel_hex(byte* inp_buf, char* out_buf, int inp_buf_size){
#define NEW_HEX_LINE(x) (!(x / byte_line_size))
#define LINE_CUT(x) (x / byte_line_size) * byte_line_size
    int i = 0;
    int j = inp_buf_size;

    sprintf(out_buf, "%s", first_hex_str);

    out_buf += first_hex_str_size;

    while (j--){
        
        if ((!(i % byte_line_size) || i == inp_buf_size - 1) && i != 0) {
            byte sum = 0;
            if (inp_buf_size - i > 1 || !(i % byte_line_size))
                sum = chk_sum(inp_buf + i - byte_line_size,
                              byte_line_size);
            else {
                sum = chk_sum(inp_buf + i + LINE_CUT(i) - inp_buf_size + 1,
                              inp_buf_size - LINE_CUT(i));
            }

            sprintf(out_buf, "%02X",(byte)((byte) 0 - (byte)
                                    ((int) sum + (i - 1) / 256 + i % 256)));  
            out_buf += 2;

            if (i != inp_buf_size - 1){
                sprintf(out_buf, "\x0D\n:%1X%1X%04X00", !NEW_HEX_LINE(j),
                        (j % byte_line_size) * NEW_HEX_LINE(j),  i); 
            out_buf += 11;
            }
            else {
                sprintf(out_buf, "\x0d\n%s", end_hex_str);
                return 0;
            }

        }
        
        if (i == 0) {
            sprintf(out_buf, ":10000000");
            out_buf += 9;
        }

        sprintf(out_buf, "%02X",(byte) inp_buf[i]);
        out_buf += 2;
        ++i;
    }
    sprintf(out_buf, "%s\n", end_hex_str);

    return 0;
#undef LINE_CUT
#undef NEW_HEX_LINE
}



            





    

