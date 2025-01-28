#pragma once
#include "eSTR.h"
#include "eWeb.h"

#define EWEBLOG_DEFAULT_CAPACITY 1024

#define EWEBLOG_HANDLERS(execution_funtion) \
    {{"/weblog_get", HTTP_POST , execution_funtion , NULL}, true, {.uri_execution_function = eweblog_get_post_handler}}, \

// Nuevas definiciones
#define EWEBLOG_CHECK_INIT() do { \
    if (!eweblog_is_initialized) { \
        eweblog_init(EWEBLOG_DEFAULT_CAPACITY); \
        eweblog_is_initialized = true; \
    } \
} while(0)

extern eSTR EWEBLOG_STR;
extern bool eweblog_is_initialized;  // Nueva variable global

void eweblog_init(unsigned CAPACITY);
void eweblog_realocate(unsigned CAPACITY);
void eweblog_clear();
void eweblog_free();
void eweblog_add_str(eSTR* str);
void eweblog_add_buff(char* buff, unsigned len);

void eweblog_add_format(const char *format, ...);

esp_err_t eweblog_get_post_handler(httpd_req_t *req);