/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint32_t _0;
    int64_t _1;
    double _2;
} struct0;

/* Function forward definitions */
int64_t _1492_main(void);

/* Function definitions */
int64_t _1492_main(void){
    uint32_t _1492_t1;
    int64_t _1492_t2;
    double _1492_t3;
    struct0 _1493_x;
    int64_t _1492_$retval;
    _1492_t1 = 960;
    _1492_t2 = 247;
    _1492_t3 = 3.14e+00;
    _1493_x = (struct0) {_1492_t1, _1492_t2, _1492_t3};
    _1492_$retval = _1493_x._1;
    return _1492_$retval;
}

int main(void) {
  printf("%ld",_1492_main());
  return 0;
}
