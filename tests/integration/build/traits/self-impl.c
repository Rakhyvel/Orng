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
int64_t _100_main(void);
struct struct2 _96_add(void* _96_$self_ptr, struct struct2 _96_other);
int64_t _98_cab(void* _98_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _100_main(void){
    int64_t _100_t1;
    int64_t _100_t2;
    struct struct2 _101_a;
    struct struct2* _100_t4;
    int64_t _100_t6;
    int64_t _100_t7;
    struct struct2 _100_t5;
    function4 _100_t8;
    struct struct2 _100_t3;
    struct struct2* _100_t10;
    function3 _100_t11;
    int64_t _100_t9;
    int64_t _100_$retval;
    _100_t1 = 100;
    _100_t2 = 90;
    _101_a = (struct struct2) {_100_t1, _100_t2};
    _100_t4 = &_101_a;
    _100_t6 = 100;
    _100_t7 = 9;
    _100_t5 = (struct struct2) {_100_t6, _100_t7};
    _100_t8 = (function4) _96_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _100_t3 = _100_t8(_100_t4, _100_t5);
    $line_idx--;
    _101_a = _100_t3;
    _100_t10 = &_100_t3;
    _100_t11 = (function3) _98_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _100_t9 = _100_t11(_100_t10);
    $line_idx--;
    _100_$retval = _100_t9;
    return _100_$retval;
}

struct struct2 _96_add(void* _96_$self_ptr, struct struct2 _96_other){
    struct struct2 _97_self;
    int64_t _96_t1;
    int64_t _96_t2;
    struct struct2 _96_$retval;
    _97_self = *(struct struct2*)_96_$self_ptr;
    _96_t1 = $add_int64_t(_97_self._0, _96_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _96_t2 = $add_int64_t(_97_self._1, _96_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _96_$retval = (struct struct2) {_96_t1, _96_t2};
    return _96_$retval;
}

int64_t _98_cab(void* _98_$self_ptr){
    struct struct2 _99_self;
    int64_t _98_$retval;
    _99_self = *(struct struct2*)_98_$self_ptr;
    _98_$retval = $add_int64_t(_99_self._0, _99_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _98_$retval;
}


int main(void) {
  printf("%ld",_100_main());
  return 0;
}
