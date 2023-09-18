/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Function forward definitions */
int64_t _2_main();
uint8_t _7_f(int64_t _7_x);

/* Function definitions */
int64_t _2_main() {
    uint8_t _2_t1;
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _2_t1 = _7_f(4);
    $line_idx--;
    if (_2_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _2_t0 = 186;
    goto BB4;
BB5:
    _2_t0 = 4;
BB4:
    _2_$retval = _2_t0;
    return _2_$retval;
}

uint8_t _7_f(int64_t _7_x) {
    uint8_t _7_t4;
    uint8_t _7_$retval;
    uint8_t _7_t0;
    if (_7_x == _7_x) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _7_t4 = _7_x == _7_x;
    if (_7_t4) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _7_t0 = 0;
    goto BB7;
BB4:
    _7_t4 = 1;
    goto BB5;
BB8:
    _7_t4 = 0;
    goto BB5;
BB7:
    _7_$retval = _7_t0;
    return _7_$retval;
BB5:
    _7_t0 = _7_t4;
    goto BB7;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
