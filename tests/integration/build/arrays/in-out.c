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
};

typedef void(*function1)(struct struct0*);

/* Function forward definitions */
int64_t _72_main(void);
void _74_f(struct struct0* _74_x);


/* Function definitions */
int64_t _72_main(void){
    int64_t _72_t1;
    int64_t _72_t2;
    int64_t _72_t3;
    struct struct0 _73_x;
    function1 _72_t5;
    struct struct0* _72_t7;
    int64_t _72_t8;
    int64_t _72_t9;
    int64_t _72_$retval;
    _72_t1 = 1;
    _72_t2 = 2;
    _72_t3 = 3;
    _73_x = (struct struct0) {_72_t1, _72_t2, _72_t3};
    _72_t5 = (function1) _74_f;
    _72_t7 = &_73_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    (void) _72_t5(_72_t7);
    $line_idx--;
    _72_t8 = 1;
    _72_t9 = 3;
    $bounds_check(_72_t8, _72_t9, "tests/integration/arrays/in-out.orng:2:8:\nfn main() -> Int {\n      ^");
    _72_$retval = *((int64_t*)&_73_x + _72_t8);
    return _72_$retval;
}

void _74_f(struct struct0* _74_x){
    int64_t _74_t1;
    int64_t _74_t2;
    _74_t1 = 1;
    _74_t2 = 3;
    $bounds_check(_74_t1, _74_t2, "tests/integration/arrays/in-out.orng:9:15:\n    x[1] = 217\n             ^");
    *((int64_t*)_74_x + _74_t1) = 217;
    return;
}


int main(void) {
  printf("%ld",_72_main());
  return 0;
}
