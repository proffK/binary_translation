#include "command_convert.h"
#include <string.h>
#include <stdio.h>

extern byte reg_list[];

extern int const_list[];

extern int addr_list[];

extern const byte temp_list[];



int command_convert(const char* convert_array[], byte* out_command
                    , int state){
    
    int com_len = 0, cur_char = 0;
    int tmp1 = temp_list[0];
    int tmp2 = temp_list[1];
    int reg1 = reg_list[0];
    int reg2 = reg_list[1];
    int cst1 = const_list[0];
    unsigned int adr1 = addr_list[0] - command_size[state + 3] / 2;
    const int MAX_LEN = 1000;
    char temp_str[1000] = {0};
    int tmp_coun1 = 0, tmp_coun2 = 0;

    com_len = strlen(convert_array[state]);

    if (com_len > MAX_LEN) return -1;

    while (com_len--) {
		
		if (com_len % 16 == 0) {
			
			tmp1 = temp_list[0];
			tmp2 = temp_list[1];
			tmp_coun1 = tmp_coun2 = 0;
			
		}

        cur_char = convert_array[state][com_len];
        //printf ("\n%c", cur_char);
        switch (cur_char) {

            case '0':case '1':
                temp_str[com_len] = cur_char;
                break; 
            case 't':
                temp_str[com_len] = tmp1 % 2 + '0';
                tmp1 /= 2;
                ++tmp_coun1;

                if (tmp_coun1 == 5) {

                    tmp1 = temp_list[0];
                    tmp_coun1 = 0;

                }

                break;
            case 'T':
                temp_str[com_len] = tmp2 % 2 + '0';
                tmp2 /= 2;
                ++tmp_coun2;

                if (tmp_coun2 == 5) {

                    tmp2 = temp_list[1];
                    tmp_coun2 = 0;

                }

                break;
            case 'r':
                temp_str[com_len] = reg1 % 2 + '0';
                reg1 /= 2;
                break;
            case 'R':
                temp_str[com_len] = reg2 % 2 + '0';
                reg2 /= 2;
                break;
            case 'k':
                temp_str[com_len] = cst1 % 2 + '0';
                cst1 /= 2;
                break;
            case 'a':
                temp_str[com_len] = adr1 % 2 + '0';
                adr1 /= 2;
                break; 

        }

        //printf (" %c\n", temp_str[com_len]);
    }
    printf("\n%s\n", temp_str);
    
    return bin_str2byte(temp_str, out_command, ENDIAN);

}

int bin_str2byte(char* str, byte* out, const int endian){

    int i = 0, offset = 0;
    int str_count = 0;

    byte first = 0, second = 0;

    while (str[offset]) {

         for (i = 0; i < 8; ++i){
             
             first *= 2;
             first += str[offset + i] - '0';

         }

         for (i = 8; i < 16; ++i){

             second *= 2;
             second += str[offset + i] - '0';

         }
         
         str_count = offset / 8;

         if (endian) {
             
             out[str_count] = second;
             out[str_count + 1] = first;

         }
         else {

             out[str_count] = first;
             out[str_count + 1] = second;

         }

         offset += 16;

    }

    return offset / 8;

}



                   
