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
int64_t _67_main(void);
void _69_f(struct struct0* _69_x);


/* Function definitions */
int64_t _67_main(void){
    int64_t _67_t1;
    int64_t _67_t2;
    int64_t _67_t3;
    struct struct0 _68_x;
    function1 _67_t5;
    struct struct0* _67_t7;
    int64_t _67_t8;
    int64_t _67_t9;
    int64_t _67_$retval;
    _67_t1 = 1;
    _67_t2 = 2;
    _67_t3 = 3;
    _68_x = (struct struct0) {_67_t1, _67_t2, _67_t3};
    _67_t5 = (function1) _69_f;
    _67_t7 = &_68_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    (void) _67_t5(_67_t7);
    $line_idx--;
    _67_t8 = 1;
    _67_t9 = 3;
    $bounds_check(_67_t8, _67_t9, "tests/integration/arrays/in-out.orng:2:8:\nfn main() -> Int {\n      ^");
    _67_$retval = *((int64_t*)&_68_x + _67_t8);
    return _67_$retval;
}

void _69_f(struct struct0* _69_x){
    int64_t _69_t1;
    int64_t _69_t2;
    _69_t1 = 1;
    _69_t2 = 3;
    $bounds_check(_69_t1, _69_t2, "tests/integration/arrays/in-out.orng:9:15:\n    x[1] = 217\n             ^");
    *((int64_t*)_69_x + _69_t1) = 217;
    return;
}


int main(void) {
  printf("%ld",_67_main());
  return 0;
}
