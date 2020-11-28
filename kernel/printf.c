#include <stdint.h>
#include <stdbool.h>
//TODO: add bool
typedef struct print_properties {
    unsigned int is_signed:1;
    unsigned int leftalign:1;
    unsigned int zeropad:1;
    unsigned int alwayssign:1;
    unsigned int alternate:1;
    unsigned int space:1;
    unsigned int size:2; // 0 for 8bit, 1 for 16 bit, 2 for 32 bit, 3 for 64 bit (unsupported)
    unsigned int dosign:1;
    unsigned int minimumsize_given:1;
    unsigned int minimumsize;
} print_properties_t;
static int print_int(intmax_t i, int base, const char basestring[], char *outbuf, int bufsize, print_properties_t props) {
    switch (props.size) {
    case 0:
        i = (int8_t)i;
        break;
    case 1:
        i = (int16_t)i;
        break;
    case 2:
        i = (uint32_t)i;
        break;
    case 3:
        break;
    }
    //This is a bad way of doing this. Too bad!
    uintmax_t u = *((uintmax_t *)&i);

    int printed=0;
    
    if (props.is_signed) {
        char sign = i < 0; //0 positive, 1 negative
        while (i) {
            outbuf[bufsize - printed - 1] = basestring[i % base];
            i /= base;
            printed++;
        }
        if (props.minimumsize_given && !props.leftalign) {
            while (printed < props.minimumsize) {
                outbuf[bufsize - printed - 1] = props.zeropad ? basestring[0] : ' ';
                printed++;
            }
        }
        
        if (props.dosign) {
            if (sign) {
                //always put -
                outbuf[bufsize - printed - 1] = '-';
                printed++;
            } else if (props.alwayssign) {
                outbuf[bufsize - printed - 1] = '+';
                printed++;
            } else if (props.space) {
                outbuf[bufsize - printed - 1] = ' ';
                printed++;
            }
        }
    } else {
        while (u) {
            outbuf[bufsize - printed - 1] = basestring[u % base];
            u /= base;
            printed++;
        }
        if (props.minimumsize_given && !props.leftalign) {
            while (printed < props.minimumsize) {
                outbuf[bufsize - printed - 1] = props.zeropad ? basestring[0] : ' ';
                printed++;
            }
        }
        if (props.dosign) {
            if (props.alwayssign) {
                outbuf[bufsize - printed - 1] = '+';
                printed++;
            } else if (props.space) {
                outbuf[bufsize - printed - 1] = ' ';
                printed++;
            }
        }
    }
    //now we shift to the left / pad it out with spaces
    //if %(number) worked, we should be 
    return printed;
}
static char bighex[] = "0123456789ABCDEF";
static char smallhex[] = "0123456789abcdef";
static char decimal[] = "0123456789";
int printf(const char *format, ...) {
    char parsing_formatter = 0;
    for (int i = 0; format[i]; i++) {
        if (parsing_formatter) {

        } else {
            if (format[i] == '%') {
                parsing_formatter = 1;
            } else {
                
            }
        }
    }
}