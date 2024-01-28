/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
struct vtable_impl {
    struct struct0(*add)(void*, struct struct0);
    int64_t(*cab)(void*);
};

/* Function forward definitions */
int64_t _1630_main(void);
struct struct0 _1626_add(void* _1626_$self_ptr, struct struct0 _1626_other);
int64_t _1628_cab(void* _1628_$self_ptr);

/* Trait vtable implementations */
struct vtable_impl _1624_$vtable = {
    .add = _1626_add,
    .cab = _1628_cab,
};


/* Function definitions */
int64_t _1630_main(void){
    int64_t _1630_t1;
    int64_t _1630_t2;
    struct struct0 _1631_a;
    struct struct0* _1630_t5;
    int64_t _1630_t7;
    int64_t _1630_t8;
    struct struct0 _1630_t6;
    struct struct0 _1630_t3;
    struct struct0* _1630_t11;
    int64_t _1630_t9;
    int64_t _1630_$retval;
    _1630_t1 = 100;
    _1630_t2 = 90;
    _1631_a = (struct struct0) {_1630_t1, _1630_t2};
    _1630_t5 = &_1631_a;
    _1630_t7 = 100;
    _1630_t8 = 9;
    _1630_t6 = (struct struct0) {_1630_t7, _1630_t8};
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _1630_t3 = _1624_$vtable.add(_1630_t5, _1630_t6);
    $line_idx--;
    _1631_a = _1630_t3;
    _1630_t11 = &_1630_t3;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _1630_t9 = _1624_$vtable.cab(_1630_t11);
    $line_idx--;
    _1630_$retval = _1630_t9;
    return _1630_$retval;
}

struct struct0 _1626_add(void* _1626_$self_ptr, struct struct0 _1626_other){
    struct struct0 _1627_self;
    int64_t _1626_t1;
    int64_t _1626_t2;
    struct struct0 _1626_$retval;
    _1627_self = *(struct struct0*)_1626_$self_ptr;
    _1626_t1 = $add_int64_t(_1627_self._0, _1626_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _1626_t2 = $add_int64_t(_1627_self._1, _1626_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _1626_$retval = (struct struct0) {_1626_t1, _1626_t2};
    return _1626_$retval;
}

int64_t _1628_cab(void* _1628_$self_ptr){
    struct struct0 _1629_self;
    int64_t _1628_$retval;
    _1629_self = *(struct struct0*)_1628_$self_ptr;
    _1628_$retval = $add_int64_t(_1629_self._0, _1629_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _1628_$retval;
}


int main(void) {
  printf("%ld",_1630_main());
  return 0;
}
