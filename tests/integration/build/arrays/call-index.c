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
int64_t _97_main(void);
struct0* _101_f(struct0* _101_x);

/* Function definitions */
int64_t _97_main(void){
    int64_t _97_t1;
    int64_t _97_t2;
    int64_t _97_t3;
    int64_t _97_t4;
    struct0 _98_x;
    int64_t _97_t5;
    function1 _97_t6;
    struct0* _97_t8;
    struct0* _97_t7;
    int64_t _97_t9;
    int64_t _97_$retval;
    _97_t1 = 1;
    _97_t2 = 2;
    _97_t3 = 3;
    _97_t4 = 4;
    _98_x = (struct0) {_97_t1, _97_t2, _97_t3, _97_t4};
    _97_t5 = 3;
    _97_t6 = _101_f;
    _97_t8 = &_98_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _97_t7 = _97_t6(_97_t8);
    $line_idx--;
    _97_t9 = 4;
    $bounds_check(_97_t5, _97_t9, "tests/integration/arrays/call-index.orng:2:3:\nfn main() -> Int {\n ^");
    _97_$retval = *((int64_t*)_97_t7 + _97_t5);
    return _97_$retval;
}

struct0* _101_f(struct0* _101_x){
    int64_t _101_t1;
    int64_t _101_t2;
    struct0* _101_$retval;
    _101_t1 = 3;
    _101_t2 = 4;
    $bounds_check(_101_t1, _101_t2, "tests/integration/arrays/call-index.orng:8:15:\n    x^[3] = 78\n             ^");
    *((int64_t*)_101_x + _101_t1) = 78;
    _101_$retval = _101_x;
    return _101_$retval;
}

int main(void) {
  printf("%ld",_97_main());
  return 0;
}
