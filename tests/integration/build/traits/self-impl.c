/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct5;

/* Struct, union, and function definitions */
struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct2* _0;
    struct struct2 _1;
};

typedef struct struct2(*function0)(struct struct2*, struct struct2);

typedef int64_t(*function3)(struct struct2*);

struct struct5 {
    struct struct2* _0;
    struct struct2 _1;
};

typedef struct struct2(*function4)(struct struct2*, struct struct2);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _145_main(void);
struct struct2 _141_add(void* _141_$self_ptr, struct struct2 _141_other);
int64_t _143_cab(void* _143_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _145_main(void){
    int64_t _145_t1;
    int64_t _145_t2;
    struct struct2 _146_a;
    struct struct2* _145_t5;
    int64_t _145_t7;
    int64_t _145_t8;
    struct struct2 _145_t6;
    function4 _145_t9;
    struct struct2 _145_t4;
    struct struct2* _145_t11;
    function3 _145_t12;
    int64_t _145_t10;
    int64_t _145_$retval;
    _145_t1 = 100;
    _145_t2 = 90;
    _146_a = (struct struct2) {_145_t1, _145_t2};
    _145_t5 = &_146_a;
    _145_t7 = 100;
    _145_t8 = 9;
    _145_t6 = (struct struct2) {_145_t7, _145_t8};
    _145_t9 = (function4) _141_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _145_t4 = _145_t9(_145_t5, _145_t6);
    $line_idx--;
    _146_a = _145_t4;
    _145_t11 = &_145_t4;
    _145_t12 = (function3) _143_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _145_t10 = _145_t12(_145_t11);
    $line_idx--;
    _145_$retval = _145_t10;
    return _145_$retval;
}

struct struct2 _141_add(void* _141_$self_ptr, struct struct2 _141_other){
    struct struct2 _142_self;
    int64_t _141_t2;
    int64_t _141_t3;
    struct struct2 _141_$retval;
    _142_self = *(struct struct2*)_141_$self_ptr;
    _141_t2 = $add_int64_t(_142_self._0, _141_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _141_t3 = $add_int64_t(_142_self._1, _141_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _141_$retval = (struct struct2) {_141_t2, _141_t3};
    return _141_$retval;
}

int64_t _143_cab(void* _143_$self_ptr){
    struct struct2 _144_self;
    int64_t _143_$retval;
    _144_self = *(struct struct2*)_143_$self_ptr;
    _143_$retval = $add_int64_t(_144_self._0, _144_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _143_$retval;
}


int main(void) {
  printf("%ld",_145_main());
  return 0;
}
