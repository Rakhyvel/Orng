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
int64_t _20_main(void);
int64_t _18_a(void* _18_$self_ptr, int64_t _18_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _20_main(void){
    int64_t _20_t1;
    int64_t _20_t2;
    struct struct2 _21_my_val;
    struct struct2* _21_my_val_ptr;
    int64_t _20_t7;
    function3 _20_t8;
    int64_t _20_t6;
    int64_t _20_t9;
    int64_t _20_$retval;
    _20_t1 = 200;
    _20_t2 = 45;
    _21_my_val = (struct struct2) {_20_t1, _20_t2};
    _21_my_val_ptr = &_21_my_val;
    _20_t7 = 2;
    _20_t8 = (function3) _18_a;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-basic.orng:15:17:\n    my_val_ptr.>a(2) + 3\n               ^";
    _20_t6 = _20_t8(_21_my_val_ptr, _20_t7);
    $line_idx--;
    _20_t9 = 3;
    _20_$retval = $add_int64_t(_20_t6, _20_t9, "tests/integration/traits/addr-receiver-basic.orng:15:23:\n    my_val_ptr.>a(2) + 3\n                     ^");
    return _20_$retval;
}

int64_t _18_a(void* _18_$self_ptr, int64_t _18_x){
    struct struct2 _19_self;
    int64_t _18_t1;
    int64_t _18_$retval;
    _19_self = *(struct struct2*)_18_$self_ptr;
    _18_t1 = $mult_int64_t(_19_self._1, _18_x, "tests/integration/traits/addr-receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _18_$retval = $add_int64_t(_19_self._0, _18_t1, "tests/integration/traits/addr-receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _18_$retval;
}


int main(void) {
  printf("%ld",_20_main());
  return 0;
}
