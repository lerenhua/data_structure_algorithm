#ifndef UTILS_H
#define UTILS_H

typedef struct String {
    int len;
    char * str;
} String;

/* 从输入获取字符串 */
String *GetInputStr(void);
String * CreateString(char* str);

int GenArrangement(String *str, int set_pos);

#endif