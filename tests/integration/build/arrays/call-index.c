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
int64_t _50_main(void);
struct struct0* _52_f(struct struct0* _52_x);


/* Function definitions */
int64_t _50_main(void){
    int64_t _50_t1;
    int64_t _50_t2;
    int64_t _50_t3;
    int64_t _50_t4;
    struct struct0 _51_x;
    function1 _50_t6;
    struct struct0* _50_t8;
    struct struct0* _50_t7;
    int64_t _50_t9;
    int64_t _50_t10;
    int64_t _50_$retval;
    _50_t1 = 1;
    _50_t2 = 2;
    _50_t3 = 3;
    _50_t4 = 4;
    _51_x = (struct struct0) {_50_t1, _50_t2, _50_t3, _50_t4};
    _50_t6 = (function1) _52_f;
    _50_t8 = &_51_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _50_t7 = _50_t6(_50_t8);
    $line_idx--;
    _50_t9 = 3;
    _50_t10 = 4;
    $bounds_check(_50_t9, _50_t10, "tests/integration/arrays/call-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _50_$retval = *((int64_t*)_50_t7 + _50_t9);
    return _50_$retval;
}

struct struct0* _52_f(struct struct0* _52_x){
    int64_t _52_t1;
    int64_t _52_t2;
    struct struct0* _52_$retval;
    _52_t1 = 3;
    _52_t2 = 4;
    $bounds_check(_52_t1, _52_t2, "tests/integration/arrays/call-index.orng:8:15:\n    x^[3] = 78\n             ^");
    *((int64_t*)_52_x + _52_t1) = 78;
    _52_$retval = _52_x;
    return _52_$retval;
}


int main(void) {
  printf("%ld",_50_main());
  return 0;
}
