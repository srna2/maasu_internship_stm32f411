#include <sys/stat.h>
#include <sys/times.h>
#include "usart.h"

// Create an instance of Usart
Usart usart(USART2);

// Redirect printf to the Usart instance
extern "C" int _write(int file, char *ptr, int len) {
    (void) file;
    usart.write_buf(ptr, len);
    return len;
}

extern "C" int _fstat(int fd, struct stat *st) {
    (void) fd;
    (void) st;
    return -1; 
}

extern "C" void *_sbrk(int incr) {
    extern char _end;
    static unsigned char *heap = NULL;
    unsigned char *prev_heap;
    if (heap == NULL) heap = (unsigned char *) &_end;
    prev_heap = heap;
    heap += incr;
    return prev_heap;
}

extern "C" int _read(int fd, char *ptr, int len) {
    (void) fd;
    (void) ptr;
    (void) len;
    return -1; 
}

extern "C" int _kill(int pid, int sig) {
    return -1; 
}

extern "C" int _lseek(int file, int ptr, int dir) {
    return 0; 
}

extern "C" int _getpid(void) {
    return 1; 
}

extern "C" int _isatty(int file) {
    return 1; 
}

extern "C" int _close(int file) {
    return -1; 
}

// Removed pwm_timer and related functions
