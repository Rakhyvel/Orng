/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
} struct0;

/* Function forward definitions */
int64_t _1787_main(void);

/* Function definitions */
int64_t _1787_main(void){
    int64_t _1788_x;
    int64_t _1788_y;
    int64_t* _1787_t3;
    int64_t* _1787_t4;
    struct0 _1788_z;
    int64_t _1787_$retval;
    _1788_x = 30;
    _1788_y = 29;
    _1787_t3 = &_1788_x;
    _1787_t4 = &_1788_y;
    _1788_z = (struct0) {_1787_t3, _1787_t4};
    _1787_$retval = $add_int64_t(*_1788_z._0, *_1788_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1787_$retval;
}

int main(void) {
  printf("%ld",_1787_main());
  return 0;
}
