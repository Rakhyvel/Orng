/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1624_main(void);

/* Function definitions */
int64_t _1624_main(void){
    int64_t _1625_x;
    int64_t* _1625_y;
    int64_t _1624_t3;
    uint8_t _1624_t5;
    int64_t _1624_t2;
    int64_t _1624_$retval;
    int64_t _1627_z;
    int64_t* _1624_t7;
    int64_t _1624_t10;
    int64_t _1624_t11;
    int64_t _1624_t13;
    int64_t _1624_t14;
    int64_t _1624_t17;
    _1625_x = 0;
    _1625_y = &_1625_x;
    _1624_t3 = 0;
    _1624_t5 = *_1625_y==_1624_t3;
    if (_1624_t5) {
        goto BB1936;
    } else {
        goto BB1940;
    }
BB1936:
    _1627_z = *_1625_y;
    _1624_t7 = &_1627_z;
    *_1624_t7 = $add_int64_t(_1627_z, _1627_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1627_z = $sub_int64_t(_1627_z, _1627_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1627_z = $mult_int64_t(_1627_z, _1627_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1624_t10 = 1;
    _1624_t11 = $add_int64_t(_1627_z, _1624_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1627_z = $div_int64_t(_1627_z, _1624_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1624_t13 = 1;
    _1624_t14 = $add_int64_t(_1627_z, _1624_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1627_z = $mod_int64_t(_1627_z, _1624_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1624_t17 = -1;
    _1627_z = $mult_int64_t(_1627_z, _1624_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1624_t2 = $mult_int64_t(_1627_z, _1624_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB1939;
BB1940:
    _1624_t2 = 1000;
    goto BB1939;
BB1939:
    _1624_$retval = _1624_t2;
    return _1624_$retval;
}

int main(void) {
  printf("%ld",_1624_main());
  return 0;
}
