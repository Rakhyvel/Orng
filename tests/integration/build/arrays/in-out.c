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
int64_t _58_main(void);
void _60_f(struct struct0* _60_x);


/* Function definitions */
int64_t _58_main(void){
    int64_t _58_t1;
    int64_t _58_t2;
    int64_t _58_t3;
    struct struct0 _59_x;
    function1 _58_t5;
    struct struct0* _58_t7;
    int64_t _58_t8;
    int64_t _58_t9;
    int64_t _58_$retval;
    _58_t1 = 1;
    _58_t2 = 2;
    _58_t3 = 3;
    _59_x = (struct struct0) {_58_t1, _58_t2, _58_t3};
    _58_t5 = (function1) _60_f;
    _58_t7 = &_59_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    (void) _58_t5(_58_t7);
    $line_idx--;
    _58_t8 = 1;
    _58_t9 = 3;
    $bounds_check(_58_t8, _58_t9, "tests/integration/arrays/in-out.orng:2:8:\nfn main() -> Int {\n      ^");
    _58_$retval = *((int64_t*)&_59_x + _58_t8);
    return _58_$retval;
}

void _60_f(struct struct0* _60_x){
    int64_t _60_t1;
    int64_t _60_t2;
    _60_t1 = 1;
    _60_t2 = 3;
    $bounds_check(_60_t1, _60_t2, "tests/integration/arrays/in-out.orng:9:15:\n    x[1] = 217\n             ^");
    *((int64_t*)_60_x + _60_t1) = 217;
    return;
}


int main(void) {
  printf("%ld",_58_main());
  return 0;
}
