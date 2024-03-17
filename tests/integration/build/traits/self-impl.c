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
int64_t _1656_main(void);
struct struct2 _1652_add(void* _1652_$self_ptr, struct struct2 _1652_other);
int64_t _1654_cab(void* _1654_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1656_main(void){
    int64_t _1656_t1;
    int64_t _1656_t2;
    struct struct2 _1657_a;
    struct struct2* _1656_t5;
    int64_t _1656_t7;
    int64_t _1656_t8;
    struct struct2 _1656_t6;
    function4 _1656_t9;
    struct struct2 _1656_t4;
    struct struct2* _1656_t11;
    function3 _1656_t12;
    int64_t _1656_t10;
    int64_t _1656_$retval;
    _1656_t1 = 100;
    _1656_t2 = 90;
    _1657_a = (struct struct2) {_1656_t1, _1656_t2};
    _1656_t5 = &_1657_a;
    _1656_t7 = 100;
    _1656_t8 = 9;
    _1656_t6 = (struct struct2) {_1656_t7, _1656_t8};
    _1656_t9 = (function4) _1652_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _1656_t4 = _1656_t9(_1656_t5, _1656_t6);
    $line_idx--;
    _1657_a = _1656_t4;
    _1656_t11 = &_1656_t4;
    _1656_t12 = (function3) _1654_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _1656_t10 = _1656_t12(_1656_t11);
    $line_idx--;
    _1656_$retval = _1656_t10;
    return _1656_$retval;
}

struct struct2 _1652_add(void* _1652_$self_ptr, struct struct2 _1652_other){
    struct struct2 _1653_self;
    int64_t _1652_t2;
    int64_t _1652_t3;
    struct struct2 _1652_$retval;
    _1653_self = *(struct struct2*)_1652_$self_ptr;
    _1652_t2 = $add_int64_t(_1653_self._0, _1652_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _1652_t3 = $add_int64_t(_1653_self._1, _1652_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _1652_$retval = (struct struct2) {_1652_t2, _1652_t3};
    return _1652_$retval;
}

int64_t _1654_cab(void* _1654_$self_ptr){
    struct struct2 _1655_self;
    int64_t _1654_$retval;
    _1655_self = *(struct struct2*)_1654_$self_ptr;
    _1654_$retval = $add_int64_t(_1655_self._0, _1655_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _1654_$retval;
}


int main(void) {
  printf("%ld",_1656_main());
  return 0;
}
