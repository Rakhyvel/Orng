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
    int64_t _3;
} struct0;

typedef struct0*(*function1)(struct0*);

/* Function forward definitions */
int64_t _58_main(void);
struct0* _60_f(struct0* _60_x);

/* Function definitions */
int64_t _58_main(void) {
    int64_t _58_t1;
    int64_t _58_t2;
    int64_t _58_t3;
    int64_t _58_t4;
    struct0 _59_x;
    int64_t _58_t5;
    function1 _58_t6;
    struct0* _58_t8;
    struct0* _58_t7;
    int64_t _58_$retval;
    _58_t1 = 1;
    _58_t2 = 2;
    _58_t3 = 3;
    _58_t4 = 4;
    _59_x = (struct0) {_58_t1, _58_t2, _58_t3, _58_t4};
    _58_t5 = 3;
    _58_t6 = _60_f;
    _58_t8 = &_59_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _58_t7 = _58_t6(_58_t8);
    $line_idx--;
    _58_$retval = *((int64_t*)_58_t7 + _58_t5);
    return _58_$retval;
}

struct0* _60_f(struct0* _60_x) {
    int64_t _60_t1;
    struct0* _60_$retval;
    _60_t1 = 3;
    *((int64_t*)_60_x + _60_t1) = 78;
    _60_$retval = _60_x;
    return _60_$retval;
}

int main(void) {
  printf("%ld",_58_main());
  return 0;
}
