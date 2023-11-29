/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _322_main(void);

/* Function definitions */
int64_t _322_main(void) {
    int64_t _322_t1;
    double _322_t2;
    struct0 _323_x;
    int64_t _322_$retval;
    _322_t1 = 137;
    _322_t2 = 0;
    _323_x = (struct0) {_322_t1, _322_t2};
    _322_$retval = _323_x._0;
    return _322_$retval;
}

int main(void) {
  printf("%ld",_322_main());
  return 0;
}
