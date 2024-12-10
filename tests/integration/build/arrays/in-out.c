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
int64_t _74_main(void);
void _76_f(struct struct0* _76_x);


/* Function definitions */
int64_t _74_main(void){
    int64_t _74_t1;
    int64_t _74_t2;
    int64_t _74_t3;
    struct struct0 _75_x;
    function1 _74_t5;
    struct struct0* _74_t7;
    int64_t _74_t8;
    int64_t _74_t9;
    int64_t _74_$retval;
    _74_t1 = 1;
    _74_t2 = 2;
    _74_t3 = 3;
    _75_x = (struct struct0) {_74_t1, _74_t2, _74_t3};
    _74_t5 = (function1) _76_f;
    _74_t7 = &_75_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    (void) _74_t5(_74_t7);
    $line_idx--;
    _74_t8 = 1;
    _74_t9 = 3;
    $bounds_check(_74_t8, _74_t9, "tests/integration/arrays/in-out.orng:2:8:\nfn main() -> Int {\n      ^");
    _74_$retval = *((int64_t*)&_75_x + _74_t8);
    return _74_$retval;
}

void _76_f(struct struct0* _76_x){
    int64_t _76_t1;
    int64_t _76_t2;
    _76_t1 = 1;
    _76_t2 = 3;
    $bounds_check(_76_t1, _76_t2, "tests/integration/arrays/in-out.orng:9:15:\n    x[1] = 217\n             ^");
    *((int64_t*)_76_x + _76_t1) = 217;
    return;
}


int main(void) {
  printf("%ld",_74_main());
  return 0;
}
