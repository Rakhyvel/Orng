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
int64_t _159_main(void);
int64_t _157_a(void* _157_$self_ptr, int64_t _157_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _159_main(void){
    int64_t _159_t1;
    int64_t _159_t2;
    struct struct2 _160_my_val;
    struct struct2* _159_t5;
    int64_t _159_t6;
    function3 _159_t7;
    int64_t _159_t4;
    int64_t _159_t8;
    int64_t _159_$retval;
    _159_t1 = 200;
    _159_t2 = 45;
    _160_my_val = (struct struct2) {_159_t1, _159_t2};
    _159_t5 = &_160_my_val;
    _159_t6 = 2;
    _159_t7 = (function3) _157_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _159_t4 = _159_t7(_159_t5, _159_t6);
    $line_idx--;
    _159_t8 = 1;
    _159_$retval = $sub_int64_t(_159_t4, _159_t8, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _159_$retval;
}

int64_t _157_a(void* _157_$self_ptr, int64_t _157_x){
    struct struct2 _158_self;
    int64_t _157_t1;
    int64_t _157_$retval;
    _158_self = *(struct struct2*)_157_$self_ptr;
    _157_t1 = $mult_int64_t(_158_self._1, _157_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _157_$retval = $add_int64_t(_158_self._0, _157_t1, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _157_$retval;
}


int main(void) {
  printf("%ld",_159_main());
  return 0;
}
