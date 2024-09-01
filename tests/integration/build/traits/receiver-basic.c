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
int64_t _1698_main(void);
int64_t _1696_a(void* _1696_$self_ptr, int64_t _1696_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1698_main(void){
    int64_t _1698_t1;
    int64_t _1698_t2;
    struct struct2 _1699_my_val;
    struct struct2* _1698_t5;
    int64_t _1698_t6;
    function3 _1698_t7;
    int64_t _1698_t4;
    int64_t _1698_t8;
    int64_t _1698_$retval;
    _1698_t1 = 200;
    _1698_t2 = 45;
    _1699_my_val = (struct struct2) {_1698_t1, _1698_t2};
    _1698_t5 = &_1699_my_val;
    _1698_t6 = 2;
    _1698_t7 = (function3) _1696_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _1698_t4 = _1698_t7(_1698_t5, _1698_t6);
    $line_idx--;
    _1698_t8 = 1;
    _1698_$retval = $sub_int64_t(_1698_t4, _1698_t8, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _1698_$retval;
}

int64_t _1696_a(void* _1696_$self_ptr, int64_t _1696_x){
    struct struct2 _1697_self;
    int64_t _1696_t1;
    int64_t _1696_$retval;
    _1697_self = *(struct struct2*)_1696_$self_ptr;
    _1696_t1 = $mult_int64_t(_1697_self._1, _1696_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1696_$retval = $add_int64_t(_1697_self._0, _1696_t1, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1696_$retval;
}


int main(void) {
  printf("%ld",_1698_main());
  return 0;
}