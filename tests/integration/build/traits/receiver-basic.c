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
int64_t _120_main(void);
int64_t _118_a(void* _118_$self_ptr, int64_t _118_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _120_main(void){
    int64_t _120_t1;
    int64_t _120_t2;
    struct struct2 _121_my_val;
    struct struct2* _120_t5;
    int64_t _120_t6;
    function3 _120_t7;
    int64_t _120_t4;
    int64_t _120_t8;
    int64_t _120_$retval;
    _120_t1 = 200;
    _120_t2 = 45;
    _121_my_val = (struct struct2) {_120_t1, _120_t2};
    _120_t5 = &_121_my_val;
    _120_t6 = 2;
    _120_t7 = (function3) _118_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _120_t4 = _120_t7(_120_t5, _120_t6);
    $line_idx--;
    _120_t8 = 1;
    _120_$retval = $sub_int64_t(_120_t4, _120_t8, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _120_$retval;
}

int64_t _118_a(void* _118_$self_ptr, int64_t _118_x){
    struct struct2 _119_self;
    int64_t _118_t1;
    int64_t _118_$retval;
    _119_self = *(struct struct2*)_118_$self_ptr;
    _118_t1 = $mult_int64_t(_119_self._1, _118_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _118_$retval = $add_int64_t(_119_self._0, _118_t1, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _118_$retval;
}


int main(void) {
  printf("%ld",_120_main());
  return 0;
}
