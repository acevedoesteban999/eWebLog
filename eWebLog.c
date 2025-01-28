#include "eWebLog.h"

eSTR EWEBLOG_STR;


void eweblog_init(unsigned CAPACITY){
    estr_init(&EWEBLOG_STR);
    estr_prepare_str(&EWEBLOG_STR,CAPACITY);
}

void eweblog_realocate(unsigned CAPACITY){
    estr_prepare_str(&EWEBLOG_STR,CAPACITY);
}

void eweblog_clear(){
    estr_clear(&EWEBLOG_STR);
}

void eweblog_free(){
    estr_free(&EWEBLOG_STR);
}

void eweblog_add_str(eSTR*str){
    eweblog_add_buff(str->ptr_char,str->length);
}
void eweblog_add_buff(char* buff, unsigned len) {
    if (EWEBLOG_STR.length + len > EWEBLOG_STR.capacity)
        estr_clear(&EWEBLOG_STR);
    estr_append_str(&EWEBLOG_STR, false, buff);
}