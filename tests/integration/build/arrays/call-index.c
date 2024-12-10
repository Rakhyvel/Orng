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
int64_t _66_main(void);
struct struct0* _68_f(struct struct0* _68_x);


/* Function definitions */
int64_t _66_main(void){
    int64_t _66_t1;
    int64_t _66_t2;
    int64_t _66_t3;
    int64_t _66_t4;
    struct struct0 _67_x;
    function1 _66_t6;
    struct struct0* _66_t8;
    struct struct0* _66_t7;
    int64_t _66_t9;
    int64_t _66_t10;
    int64_t _66_$retval;
    _66_t1 = 1;
    _66_t2 = 2;
    _66_t3 = 3;
    _66_t4 = 4;
    _67_x = (struct struct0) {_66_t1, _66_t2, _66_t3, _66_t4};
    _66_t6 = (function1) _68_f;
    _66_t8 = &_67_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _66_t7 = _66_t6(_66_t8);
    $line_idx--;
    _66_t9 = 3;
    _66_t10 = 4;
    $bounds_check(_66_t9, _66_t10, "tests/integration/arrays/call-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _66_$retval = *((int64_t*)_66_t7 + _66_t9);
    return _66_$retval;
}

struct struct0* _68_f(struct struct0* _68_x){
    int64_t _68_t1;
    int64_t _68_t2;
    struct struct0* _68_$retval;
    _68_t1 = 3;
    _68_t2 = 4;
    $bounds_check(_68_t1, _68_t2, "tests/integration/arrays/call-index.orng:8:15:\n    x^[3] = 78\n             ^");
    *((int64_t*)_68_x + _68_t1) = 78;
    _68_$retval = _68_x;
    return _68_$retval;
}


int main(void) {
  printf("%ld",_66_main());
  return 0;
}
