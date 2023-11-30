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
int64_t _97_main(void);

/* Function definitions */
int64_t _97_main(void) {
    int64_t _97_t2;
    int64_t _97_t3;
    struct0 _97_t1;
    int64_t _97_t5;
    int64_t _97_t6;
    struct0 _97_t4;
    struct1 _98_x;
    int64_t _97_$retval;
    _97_t2 = 1;
    _97_t3 = 2;
    _97_t1 = (struct0) {_97_t2, _97_t3};
    _97_t5 = 3;
    _97_t6 = 4;
    _97_t4 = (struct0) {_97_t5, _97_t6};
    _98_x = (struct1) {_97_t1, _97_t4};
    _98_x._0._0 = 77;
    _97_$retval = _98_x._0._0;
    return _97_$retval;
}

int main(void) {
  printf("%ld",_97_main());
  return 0;
}
