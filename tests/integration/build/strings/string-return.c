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
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _2_main();

/* Function definitions */
uint8_t _2_main() {
    struct0 _3_x;
    uint8_t _2_$retval;
    _3_x = (struct0) {string_0, 11};
    _2_$retval = *((uint8_t*)_3_x._0 + 1);
    return _2_$retval;
}

int main()
{
  printf("%d",_2_main());
  return 0;
}
