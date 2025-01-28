#include "eWebLog.h"

eSTR EWEBLOG_STR;


void eweblog_init(unsigned CAPACITY){
    estr_init(&EWEBLOG_STR);
    estr_prepare_str(&EWEBLOG_STR,CAPACITY);
}

void eweblog_realocate(unsigned CAPACITY){
    EWEBLOG_CHECK_INIT();
    estr_prepare_str(&EWEBLOG_STR,CAPACITY);
}

void eweblog_clear(){
    EWEBLOG_CHECK_INIT();
    estr_clear(&EWEBLOG_STR);
}

void eweblog_free(){
    EWEBLOG_CHECK_INIT();
    estr_free(&EWEBLOG_STR);
}

void eweblog_add_str(eSTR*str){
    eweblog_add_buff(str->ptr_char,str->length);
}

void eweblog_add_buff(char* buff, unsigned len) {
    EWEBLOG_CHECK_INIT();
    if (EWEBLOG_STR.length + len > EWEBLOG_STR.capacity)
        estr_clear(&EWEBLOG_STR);
    estr_append_str(&EWEBLOG_STR, false, buff);
}


void eweblog_add_format(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int size = vsnprintf(NULL, 0, format, args);
    if (size < 0) {
        va_end(args);
        return ;
    }

    char *buff = (char *)malloc(size + 1); 
    if (!buff) {
        va_end(args);
        return ; 
    }

    vsnprintf(buff, size + 1, format, args);
    va_end(args);
    
    eweblog_add_buff(buff,size);
    free(buff);
}


esp_err_t eweblog_get_post_handler(httpd_req_t *req){
    EWEBLOG_CHECK_INIT();
    httpd_resp_set_type(req, "text/html");
    eweb_send_resp_try_chunk_str(req, &EWEBLOG_STR);
    return ESP_OK;
}

