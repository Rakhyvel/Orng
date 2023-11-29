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
int64_t _56_main(void);

/* Function definitions */
int64_t _56_main(void) {
    int64_t _57_x;
    int64_t _57_y;
    int64_t* _56_t3;
    int64_t* _56_t4;
    struct0 _57_z;
    int64_t _56_$retval;
    _57_x = 30;
    _57_y = 29;
    _56_t3 = &_57_x;
    _56_t4 = &_57_y;
    _57_z = (struct0) {_56_t3, _56_t4};
    _56_$retval = $add_int64_t(*_57_z._0, *_57_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _56_$retval;
}

int main(void) {
  printf("%ld",_56_main());
  return 0;
}
