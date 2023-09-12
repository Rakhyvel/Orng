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
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _3_a;
    int64_t* _3_b;
    int64_t* _3_c;
    struct0 _2_t25;
    int64_t _2_$retval;
    _3_x = (struct0) {0, 0, 0};
    _3_a = (((int64_t*)&_3_x)+0);
    _3_b = (((int64_t*)&_3_x)+1);
    _3_c = (((int64_t*)&_3_x)+2);
    _2_t25 = (struct0) {100, 30, 30};
    **&_3_a = (&_2_t25)->_0;
    **&_3_b = (&_2_t25)->_1;
    **&_3_c = (&_2_t25)->_2;
    _2_$retval = *_3_a + *_3_b + *_3_c;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
