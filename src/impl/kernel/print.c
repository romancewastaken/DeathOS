#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

typedef __builtin_va_list va_list;
#define va_start(ap, X) __builtin_va_start(ap, X)
#define va_arg(ap, type) __builtin_va_arg(ap, type)
#define va_end(ap) __builtin_va_end(ap)

struct Char 
{
    uint8_t character;
    uint8_t color;
};

struct Char volatile * buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) 
{
    struct Char empty = (struct Char) 
    {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) 
    {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void print_clear() 
{
    for (size_t i = 0; i < NUM_ROWS; i++) 
    {
        clear_row(i);
    }
}

void print_newline() 
{
    col = 0;

    if (row < NUM_ROWS - 1) 
    {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) 
    {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS - 1);
}

void print_char(char character) 
{
    if (character == '\n') 
    {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) 
    {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void print_str(char* str) 
{
    for (size_t i = 0; 1; i++) 
    {
        char character = (uint8_t) str[i];

        if (character == '\0') 
        {
            return;
        }

        print_char(character);
    }
}

void print_set_color(uint8_t foreground, uint8_t background) 
{
    color = foreground + (background << 4);
}


void _putc(unsigned char c) 
{
     print_char((char)c); 
}

void printf(const char* fmt, ...)
{
    const char digits[] = "0123456789abcdef";
    va_list ap;
    char buf[10];
    char* s;
    unsigned char u;
    int c, i, pad;

    va_start(ap, fmt);
    while ((c = *fmt++) != 0)
     {
        if (c == '%') 
        {
            c = *fmt++;
            if (c == 'l')
                c = *fmt++;
            switch (c) 
            {
            case 'c':
                _putc(va_arg(ap, int));
                continue;
            case 's':
                s = va_arg(ap, char*);
                if (s == (void*)0)
                    s = (char*)"<NULL>";
                for (; *s; s++)
                    _putc((int)*s);
                continue;
            case '%':
                _putc('%');
                continue;
            case 'd':
            case 'i':
                c = 'u';
            case 'u':
            case 'x':
            case 'X':
                u = va_arg(ap, unsigned);
                s = buf;
                if (c == 'u') 
                {
                    do
                        *s++ = digits[u % 10U];
                    while (u /= 10U);
                } else 
                {
                    pad = 0;
                    for (i = 0; i < 8; i++) {
                        if (pad)
                            *s++ = '0';
                        else 
                        {
                            *s++ = digits[u % 16U];
                            //if ((u /= 16U) == false)
                                pad = 1;
                        }
                    }
                }
                while (--s >= buf)
                    _putc((int)*s);
                continue;
            }
        }
        _putc((int)c);
    }
    va_end(ap);
}