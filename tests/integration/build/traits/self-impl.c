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
int64_t _1790_main(void);
struct struct2 _1786_add(void* _1786_$self_ptr, struct struct2 _1786_other);
int64_t _1788_cab(void* _1788_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1790_main(void){
    int64_t _1790_t1;
    int64_t _1790_t2;
    struct struct2 _1791_a;
    struct struct2* _1790_t5;
    int64_t _1790_t7;
    int64_t _1790_t8;
    struct struct2 _1790_t6;
    function4 _1790_t9;
    struct struct2 _1790_t4;
    struct struct2* _1790_t11;
    function3 _1790_t12;
    int64_t _1790_t10;
    int64_t _1790_$retval;
    _1790_t1 = 100;
    _1790_t2 = 90;
    _1791_a = (struct struct2) {_1790_t1, _1790_t2};
    _1790_t5 = &_1791_a;
    _1790_t7 = 100;
    _1790_t8 = 9;
    _1790_t6 = (struct struct2) {_1790_t7, _1790_t8};
    _1790_t9 = (function4) _1786_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _1790_t4 = _1790_t9(_1790_t5, _1790_t6);
    $line_idx--;
    _1791_a = _1790_t4;
    _1790_t11 = &_1790_t4;
    _1790_t12 = (function3) _1788_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _1790_t10 = _1790_t12(_1790_t11);
    $line_idx--;
    _1790_$retval = _1790_t10;
    return _1790_$retval;
}

struct struct2 _1786_add(void* _1786_$self_ptr, struct struct2 _1786_other){
    struct struct2 _1787_self;
    int64_t _1786_t2;
    int64_t _1786_t3;
    struct struct2 _1786_$retval;
    _1787_self = *(struct struct2*)_1786_$self_ptr;
    _1786_t2 = $add_int64_t(_1787_self._0, _1786_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _1786_t3 = $add_int64_t(_1787_self._1, _1786_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _1786_$retval = (struct struct2) {_1786_t2, _1786_t3};
    return _1786_$retval;
}

int64_t _1788_cab(void* _1788_$self_ptr){
    struct struct2 _1789_self;
    int64_t _1788_$retval;
    _1789_self = *(struct struct2*)_1788_$self_ptr;
    _1788_$retval = $add_int64_t(_1789_self._0, _1789_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _1788_$retval;
}


int main(void) {
  printf("%ld",_1790_main());
  return 0;
}
