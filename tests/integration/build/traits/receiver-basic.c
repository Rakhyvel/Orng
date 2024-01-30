/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct4;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct4 {
    struct struct2* _0;
    int64_t _1;
};

typedef int64_t(*function3)(struct struct2*, int64_t);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _75_main(void);
int64_t _73_a(void* _73_$self_ptr, int64_t _73_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _75_main(void){
    int64_t _75_t1;
    int64_t _75_t2;
    struct struct2 _76_my_val;
    struct struct2* _75_t4;
    int64_t _75_t5;
    function3 _75_t6;
    int64_t _75_t3;
    int64_t _75_t7;
    int64_t _75_$retval;
    _75_t1 = 200;
    _75_t2 = 45;
    _76_my_val = (struct struct2) {_75_t1, _75_t2};
    _75_t4 = &_76_my_val;
    _75_t5 = 2;
    _75_t6 = (function3) _73_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _75_t3 = _75_t6(_75_t4, _75_t5);
    $line_idx--;
    _75_t7 = 1;
    _75_$retval = $sub_int64_t(_75_t3, _75_t7, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _75_$retval;
}

int64_t _73_a(void* _73_$self_ptr, int64_t _73_x){
    struct struct2 _74_self;
    int64_t _73_t0;
    int64_t _73_$retval;
    _74_self = *(struct struct2*)_73_$self_ptr;
    _73_t0 = $mult_int64_t(_74_self._1, _73_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _73_$retval = $add_int64_t(_74_self._0, _73_t0, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _73_$retval;
}


int main(void) {
  printf("%ld",_75_main());
  return 0;
}
