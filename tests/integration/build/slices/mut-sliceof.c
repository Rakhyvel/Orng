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
    int64_t _2_t16;
    int64_t _2_t21;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 2, 3, 4, 5};
    _2_t13 = (((int64_t*)(&_3_x))+0);
    _3_y = (struct1) {_2_t13, 5};
    _2_t16 = 2;
    if (_2_t16 >= (&_3_y)->_1) {
        goto BB7;
    } else {
        goto BB8;
    }
BB8:
    *(((int64_t*)((&_3_y)->_0))+_2_t16) = 81;
    _2_t21 = 2;
    if (_2_t21 >= (&_3_y)->_1) {
        goto BB11;
    } else {
        goto BB12;
    }
BB12:
    _2_$retval = (*(((int64_t*)((&_3_y)->_0))+_2_t21));
    return _2_$retval;
BB11:
    $lines[$line_idx++] = "tests/integration/slices/mut-sliceof.orng:6:7:\n    y[2]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB12;
BB7:
    $lines[$line_idx++] = "tests/integration/slices/mut-sliceof.orng:5:7:\n    y[2] = 81\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB8;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
