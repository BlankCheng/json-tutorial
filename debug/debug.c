//
// Created by xcb on 2020/4/3.
//
#include <assert.h>  /* assert() */
#include <stdlib.h>  /* NULL, strtod() */
#include <stdio.h>

#ifndef  LEPT_PARSE_STACK_INIT_SIZE
#define LEPT_PARSE_STACK_INIT_SIZE 256
#endif

typedef struct{
    const char* json;
    char * stack;
    size_t size, top;
}lept_context;

static void* lept_context_push(lept_context* c, size_t size) {
    void* ret;
    assert(size > 0);
    if (c->top + size >= c->size) {
        if (c->size == 0)
            c->size = LEPT_PARSE_STACK_INIT_SIZE;
        while (c->top + size >= c->size)
            c->size += c->size >> 1;  /* c->size * 1.5 */
        c->stack = (char*)realloc(c->stack, c->size);
    }
    ret = c->stack + c->top;
    c->top += size;
    return ret;
}


int main(){
    lept_context c;
    char json[10] = "im json";
    c.json = json;
    c.stack = NULL;
    c.size = c.top = 0;
    *(char *)lept_context_push(&c, 1) = 'a';
    *(char *)lept_context_push(&c, 1) = 'b';
    c.stack[c.top] = '\0';

    printf("%s\n", c.stack);

    char *s = (char *) malloc(100);
    for (int i = 0; i < 99; i++){
        s[i] = '\"';
    }
    char *p = s;
    printf("%s\n", p);
    p = (char *) realloc(p, 200);
    printf("%s\n", p);
    printf("%c\n", *p);

    char d[100] = "\"aa\\nss\"";
    printf("%s", d);

}