/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef struct struct0*(*function1)(struct struct0*);

/* Function forward definitions */
int64_t _59_main(void);
struct struct0* _61_f(struct struct0* _61_x);

/* Function definitions */
int64_t _59_main(void){
    int64_t _59_t1;
    int64_t _59_t2;
    int64_t _59_t3;
    int64_t _59_t4;
    struct struct0 _60_x;
    function1 _59_t5;
    struct struct0* _59_t7;
    struct struct0* _59_t6;
    int64_t _59_t8;
    int64_t _59_t9;
    int64_t _59_$retval;
    _59_t1 = 1;
    _59_t2 = 2;
    _59_t3 = 3;
    _59_t4 = 4;
    _60_x = (struct struct0) {_59_t1, _59_t2, _59_t3, _59_t4};
    _59_t5 = _61_f;
    _59_t7 = &_60_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _59_t6 = _59_t5(_59_t7);
    $line_idx--;
    _59_t8 = 3;
    _59_t9 = 4;
    $bounds_check(_59_t8, _59_t9, "tests/integration/arrays/call-index.orng:2:3:\nfn main() -> Int {\n ^");
    _59_$retval = *((int64_t*)_59_t6 + _59_t8);
    return _59_$retval;
}

struct struct0* _61_f(struct struct0* _61_x){
    int64_t _61_t1;
    int64_t _61_t2;
    struct struct0* _61_$retval;
    _61_t1 = 3;
    _61_t2 = 4;
    $bounds_check(_61_t1, _61_t2, "tests/integration/arrays/call-index.orng:8:15:\n    x^[3] = 78\n             ^");
    *((int64_t*)_61_x + _61_t1) = 78;
    _61_$retval = _61_x;
    return _61_$retval;
}

int main(void) {
  printf("%ld",_59_main());
  return 0;
}
