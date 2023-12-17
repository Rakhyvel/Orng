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
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _1679_main(void);

/* Function definitions */
int64_t _1679_main(void){
    int64_t _1679_t2;
    int64_t _1679_t3;
    struct0 _1679_t1;
    int64_t _1679_t5;
    int64_t _1679_t6;
    struct0 _1679_t4;
    struct1 _1680_x;
    int64_t _1679_$retval;
    _1679_t2 = 1;
    _1679_t3 = 2;
    _1679_t1 = (struct0) {_1679_t2, _1679_t3};
    _1679_t5 = 3;
    _1679_t6 = 4;
    _1679_t4 = (struct0) {_1679_t5, _1679_t6};
    _1680_x = (struct1) {_1679_t1, _1679_t4};
    _1680_x._0._0 = 77;
    _1679_$retval = _1680_x._0._0;
    return _1679_$retval;
}

int main(void) {
  printf("%ld",_1679_main());
  return 0;
}
