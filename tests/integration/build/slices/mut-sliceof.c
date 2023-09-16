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
    int64_t _3;
    int64_t _4;
} struct0;
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t13;
    struct1 _3_y;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 2, 3, 4, 5};
    _2_t13 = (int64_t*)&_3_x;
    _3_y = (struct1) {_2_t13, 5};
    *((int64_t*)_3_y._0 + 2) = 81;
    _2_$retval = *((int64_t*)_3_y._0 + 2);
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
