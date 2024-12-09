/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef struct struct0*(*function1)(struct struct0*);

/* Function forward definitions */
int64_t _64_main(void);
struct struct0* _66_f(struct struct0* _66_x);


/* Function definitions */
int64_t _64_main(void){
    int64_t _64_t1;
    int64_t _64_t2;
    int64_t _64_t3;
    int64_t _64_t4;
    struct struct0 _65_x;
    function1 _64_t6;
    struct struct0* _64_t8;
    struct struct0* _64_t7;
    int64_t _64_t9;
    int64_t _64_t10;
    int64_t _64_$retval;
    _64_t1 = 1;
    _64_t2 = 2;
    _64_t3 = 3;
    _64_t4 = 4;
    _65_x = (struct struct0) {_64_t1, _64_t2, _64_t3, _64_t4};
    _64_t6 = (function1) _66_f;
    _64_t8 = &_65_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _64_t7 = _64_t6(_64_t8);
    $line_idx--;
    _64_t9 = 3;
    _64_t10 = 4;
    $bounds_check(_64_t9, _64_t10, "tests/integration/arrays/call-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _64_$retval = *((int64_t*)_64_t7 + _64_t9);
    return _64_$retval;
}

struct struct0* _66_f(struct struct0* _66_x){
    int64_t _66_t1;
    int64_t _66_t2;
    struct struct0* _66_$retval;
    _66_t1 = 3;
    _66_t2 = 4;
    $bounds_check(_66_t1, _66_t2, "tests/integration/arrays/call-index.orng:8:15:\n    x^[3] = 78\n             ^");
    *((int64_t*)_66_x + _66_t1) = 78;
    _66_$retval = _66_x;
    return _66_$retval;
}


int main(void) {
  printf("%ld",_64_main());
  return 0;
}
