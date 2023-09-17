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

/* Function definitions */
int64_t _2_main() {
    int64_t _3_x;
    int64_t* _3_y;
    int64_t _2_t9;
    uint8_t _2_t7;
    int64_t _2_$retval;
    int64_t _2_t2;
    _3_x = 3;
    _3_y = &_3_x;
    if (*_3_y != 5) {
        goto BB5;
    } else {
        goto BB11;
    }
BB5:
    _2_t2 = 33;
    goto BB8;
BB11:
    _2_t9 = *_3_y;
    _2_t7 = 4 > _2_t9;
    if (_2_t7) {
        goto BB12;
    } else {
        goto BB9;
    }
BB8:
    _2_$retval = _2_t2;
    return _2_$retval;
BB12:
    _2_t7 = _2_t9 >= 3.0e+00;
    if (_2_t7) {
        goto BB5;
    }
BB9:
    _2_t2 = 10;
    goto BB8;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
