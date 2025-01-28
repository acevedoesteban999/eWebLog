#include "eSTR.h"
#define EWEBLOG_DEFAULT_CAPACITY 1024

extern eSTR EWEBLOG_STR;


void eweblog_init(unsigned CAPACITY);
void eweblog_realocate(unsigned CAPACITY);
void eweblog_clear();
void eweblog_free();
void eweblog_add_str(eSTR* str);
void eweblog_add_buff(char* buff, unsigned len);
