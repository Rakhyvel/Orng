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
} struct0;

typedef void(*function1)(struct0*);

/* Function forward definitions */
int64_t _114_main(void);
void _118_f(struct0* _118_x);

/* Function definitions */
int64_t _114_main(void){
    int64_t _114_t1;
    int64_t _114_t2;
    int64_t _114_t3;
    struct0 _115_x;
    function1 _114_t4;
    struct0* _114_t6;
    int64_t _114_t7;
    int64_t _114_t8;
    int64_t _114_$retval;
    _114_t1 = 1;
    _114_t2 = 2;
    _114_t3 = 3;
    _115_x = (struct0) {_114_t1, _114_t2, _114_t3};
    _114_t4 = _118_f;
    _114_t6 = &_115_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    _114_t4(_114_t6);
    $line_idx--;
    _114_t7 = 1;
    _114_t8 = 3;
    $bounds_check(_114_t7, _114_t8, "tests/integration/arrays/in-out.orng:2:3:\nfn main() -> Int {\n ^");
    _114_$retval = *((int64_t*)&_115_x + _114_t7);
    return _114_$retval;
}

void _118_f(struct0* _118_x){
    int64_t _118_t1;
    int64_t _118_t2;
    _118_t1 = 1;
    _118_t2 = 3;
    $bounds_check(_118_t1, _118_t2, "tests/integration/arrays/in-out.orng:9:15:\n    x[1] = 217\n             ^");
    *((int64_t*)_118_x + _118_t1) = 217;
    return;
}

int main(void) {
  printf("%ld",_114_main());
  return 0;
}
