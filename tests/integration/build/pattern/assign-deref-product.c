/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t* _2_a;
    int64_t* _2_b;
    int64_t* _2_c;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0};
    _2_a = (int64_t*)&_2_x;
    _2_b = ((int64_t*)&_2_x + 1);
    _2_c = ((int64_t*)&_2_x + 2);
    **&_2_a = 100;
    **&_2_b = 30;
    **&_2_c = 30;
    _1_$retval = *_2_a + *_2_b + *_2_c;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
