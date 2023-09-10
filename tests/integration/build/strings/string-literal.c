/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x4E\x4F\x57\x20\x59\x55\x4F\x20\x43\x45\x45\x2E\x2E\x2E";

/* Function forward definitions */
uint8_t _2_main();

/* Function definitions */
uint8_t _2_main() {
    struct0 _3_x;
    int64_t _2_t1;
    uint8_t _2_t2;
    uint8_t _2_$retval;
    _3_x = (struct0) {string_0, 15};
    _2_t1 = 5;
    _2_t2 = *(((uint8_t*)((&_3_x)->_0))+_2_t1);
    _2_$retval = _2_t2;
    return _2_$retval;
}

int main()
{
  printf("%d",_2_main());
  return 0;
}
