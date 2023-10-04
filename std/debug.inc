// debug utilities made use by the Orng compiler when in debug mode
// © 2023 Joseph Shimel. All rights reserved.

#include <stdnoreturn.h>

static const char* $lines[1024];
static uint16_t $line_idx = 0;

_Noreturn inline static void $panic(const char *restrict msg) {
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

inline static void $tag_check(const uint64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}

inline static int8_t $negate_int8_t(const int8_t x, const char *restrict line) {
    if (x == INT8_MIN) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int16_t $negate_int16_t(const int16_t x, const char *restrict line) {
    if (x == INT16_MIN) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int32_t $negate_int32_t(const int32_t x, const char *restrict line) {
    if (x == INT32_MIN) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int64_t $negate_int64_t(const int64_t x, const char *restrict line) {
    if (x == INT64_MIN) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int8_t $add_int8_t(const int8_t lhs, const int8_t rhs, const char *restrict line) {
    if (((rhs > 0) && (lhs > (INT8_MAX - rhs))) ||
        ((rhs < 0) && (lhs < (INT8_MIN - rhs)))) {
        $lines[$line_idx++] = line;
        $panic("addition overflow");
    }
    return lhs + rhs;
}

inline static int16_t $add_int16_t(const int16_t lhs, const int16_t rhs, const char *restrict line) {
    if (((rhs > 0) && (lhs > (INT16_MAX - rhs))) ||
        ((rhs < 0) && (lhs < (INT16_MIN - rhs)))) {
        $lines[$line_idx++] = line;
        $panic("addition overflow");
    }
    return lhs + rhs;
}

inline static int32_t $add_int32_t(const int32_t lhs, const int32_t rhs, const char *restrict line) {
    if (((rhs > 0) && (lhs > (INT32_MAX - rhs))) ||
        ((rhs < 0) && (lhs < (INT32_MIN - rhs)))) {
        $lines[$line_idx++] = line;
        $panic("addition overflow");
    }
    return lhs + rhs;
}

inline static int64_t $add_int64_t(const int64_t lhs, const int64_t rhs, const char *restrict line) {
    if (((rhs > 0) && (lhs > (INT64_MAX - rhs))) ||
        ((rhs < 0) && (lhs < (INT64_MIN - rhs)))) {
        $lines[$line_idx++] = line;
        $panic("addition overflow");
    }
    return lhs + rhs;
}

inline static int8_t $sub_int8_t(const int8_t lhs, const int8_t rhs, const char *restrict line) {
    if ((rhs > 0 && lhs < INT8_MIN + rhs) ||
        (rhs < 0 && lhs > INT8_MAX + rhs)) {
        $lines[$line_idx++] = line;
        $panic("subtraction overflow");
    }
    return lhs - rhs;
}

inline static int16_t $sub_int16_t(const int16_t lhs, const int16_t rhs, const char *restrict line) {
    if ((rhs > 0 && lhs < INT16_MIN + rhs) ||
        (rhs < 0 && lhs > INT16_MAX + rhs)) {
        $lines[$line_idx++] = line;
        $panic("subtraction overflow");
    }
    return lhs - rhs;
}

inline static int32_t $sub_int32_t(const int32_t lhs, const int32_t rhs, const char *restrict line) {
    if ((rhs > 0 && lhs < INT32_MIN + rhs) ||
        (rhs < 0 && lhs > INT32_MAX + rhs)) {
        $lines[$line_idx++] = line;
        $panic("subtraction overflow");
    }
    return lhs - rhs;
}

inline static int64_t $sub_int64_t(const int64_t lhs, const int64_t rhs, const char *restrict line) {
    if ((rhs > 0 && lhs < INT64_MIN + rhs) ||
        (rhs < 0 && lhs > INT64_MAX + rhs)) {
        $lines[$line_idx++] = line;
        $panic("subtraction overflow");
    }
    return lhs - rhs;
}

inline static int8_t $mult_int8_t(const int8_t lhs, const int8_t rhs, const char *restrict line) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    } else if ((lhs > 0 && ((rhs > 0 && lhs > INT8_MAX / rhs) || (rhs < 0 && rhs < INT8_MIN / lhs))) || 
        (lhs < 0 && ((rhs > 0 && lhs < INT8_MIN / rhs) || (rhs < 0 && rhs < INT8_MAX / lhs)))) {
        $lines[$line_idx++] = line;
        $panic("multiplication overflow");
    }

    return lhs * rhs;
}

inline static int16_t $mult_int16_t(const int16_t lhs, const int16_t rhs, const char *restrict line) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    } else if ((lhs > 0 && ((rhs > 0 && lhs > INT16_MAX / rhs) || (rhs < 0 && rhs < INT16_MIN / lhs))) || 
        (lhs < 0 && ((rhs > 0 && lhs < INT16_MIN / rhs) || (rhs < 0 && rhs < INT16_MAX / lhs)))) {
        $lines[$line_idx++] = line;
        $panic("multiplication overflow");
    }

    return lhs * rhs;
}

inline static int32_t $mult_int32_t(const int32_t lhs, const int32_t rhs, const char *restrict line) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    } else if ((lhs > 0 && ((rhs > 0 && lhs > INT32_MAX / rhs) || (rhs < 0 && rhs < INT32_MIN / lhs))) || 
        (lhs < 0 && ((rhs > 0 && lhs < INT32_MIN / rhs) || (rhs < 0 && rhs < INT32_MAX / lhs)))) {
        $lines[$line_idx++] = line;
        $panic("multiplication overflow");
    }

    return lhs * rhs;
}

inline static int64_t $mult_int64_t(const int64_t lhs, const int64_t rhs, const char *restrict line) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    } else if ((lhs > 0 && ((rhs > 0 && lhs > INT64_MAX / rhs) || (rhs < 0 && rhs < INT64_MIN / lhs))) || 
        (lhs < 0 && ((rhs > 0 && lhs < INT64_MIN / rhs) || (rhs < 0 && rhs < INT64_MAX / lhs)))) {
        $lines[$line_idx++] = line;
        $panic("multiplication overflow");
    }

    return lhs * rhs;
}

inline static int8_t $div_int8_t(const int8_t lhs, const int8_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT8_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs / rhs;
}

inline static int16_t $div_int16_t(const int16_t lhs, const int16_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT16_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs / rhs;
}

inline static int32_t $div_int32_t(const int32_t lhs, const int32_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT32_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs / rhs;
}

inline static int64_t $div_int64_t(const int64_t lhs, const int64_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT64_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs / rhs;
}

inline static int8_t $mod_int8_t(const int8_t lhs, const int8_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT8_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs % rhs;
}

inline static int16_t $mod_int16_t(const int16_t lhs, const int16_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT16_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs % rhs;
}

inline static int32_t $mod_int32_t(const int32_t lhs, const int32_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT32_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs % rhs;
}

inline static int64_t $mod_int64_t(const int64_t lhs, const int64_t rhs, const char *restrict line) {
    if (rhs == 0 || (lhs == INT64_MIN && rhs == -1)) {
        $lines[$line_idx++] = line;
        $panic("division overflow");
    }

    return lhs % rhs;
}