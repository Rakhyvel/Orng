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
int64_t _186_main(void);
struct struct2 _182_add(void* _182_$self_ptr, struct struct2 _182_other);
int64_t _184_cab(void* _184_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _186_main(void){
    int64_t _186_t1;
    int64_t _186_t2;
    struct struct2 _187_a;
    struct struct2* _186_t5;
    int64_t _186_t7;
    int64_t _186_t8;
    struct struct2 _186_t6;
    function4 _186_t9;
    struct struct2 _186_t4;
    struct struct2* _186_t11;
    function3 _186_t12;
    int64_t _186_t10;
    int64_t _186_$retval;
    _186_t1 = 100;
    _186_t2 = 90;
    _187_a = (struct struct2) {_186_t1, _186_t2};
    _186_t5 = &_187_a;
    _186_t7 = 100;
    _186_t8 = 9;
    _186_t6 = (struct struct2) {_186_t7, _186_t8};
    _186_t9 = (function4) _182_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _186_t4 = _186_t9(_186_t5, _186_t6);
    $line_idx--;
    _187_a = _186_t4;
    _186_t11 = &_186_t4;
    _186_t12 = (function3) _184_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _186_t10 = _186_t12(_186_t11);
    $line_idx--;
    _186_$retval = _186_t10;
    return _186_$retval;
}

struct struct2 _182_add(void* _182_$self_ptr, struct struct2 _182_other){
    struct struct2 _183_self;
    int64_t _182_t2;
    int64_t _182_t3;
    struct struct2 _182_$retval;
    _183_self = *(struct struct2*)_182_$self_ptr;
    _182_t2 = $add_int64_t(_183_self._0, _182_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _182_t3 = $add_int64_t(_183_self._1, _182_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _182_$retval = (struct struct2) {_182_t2, _182_t3};
    return _182_$retval;
}

int64_t _184_cab(void* _184_$self_ptr){
    struct struct2 _185_self;
    int64_t _184_$retval;
    _185_self = *(struct struct2*)_184_$self_ptr;
    _184_$retval = $add_int64_t(_185_self._0, _185_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _184_$retval;
}


int main(void) {
  printf("%ld",_186_main());
  return 0;
}
