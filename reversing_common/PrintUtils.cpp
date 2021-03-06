#include "PrintUtils.h"

#include <type_traits>

void PrintUtils::printHexDigit(const uint8_t nibble, std::ostream& out) {
    const uint8_t nibble4Bit = nibble & 0x0Fu;

    if (nibble4Bit < 10) {
        out.put('0' + (char) nibble4Bit);
    } else {
        out.put('A' + (char)(nibble4Bit - 10));
    }
}

template <class T>
static void printHexInt(const T val, const bool bZeroPad, std::ostream& out) {
    // Add in the negative sign if required
    if constexpr (std::is_signed_v<T>) {
        if (val < 0) {
            out << '-';
        }
    }

    // Get the absolute value to print
    typedef std::make_unsigned_t<T> UnsignedT;
    UnsignedT valAbs;

    if constexpr (std::is_signed_v<T>) {
        if (val < 0) {
            if (val == std::numeric_limits<T>::min()) {
                // Have to special case the lowest possible number because this is not representible
                // as positive in twos complement format when using the same signed data type.
                // Doing this bit cast will do the trick for us:
                valAbs = (UnsignedT) val;
            } else {
                valAbs = (UnsignedT) -val;
            }
        } else {
            valAbs = (UnsignedT) val;
        }
    } else {
        valAbs = val;
    }

    // First chop off any leading '0' if not zero padding
    uint32_t curShift = sizeof(T) * 8;

    if (!bZeroPad) {
        while (curShift > 4) {
            const uint8_t nibble = (uint8_t)((valAbs >> (curShift - 4)) & 0x0Fu);

            if (nibble == 0) {
                curShift -= 4;
            } else {
                break;
            }
        }
    }

    // Print each nibble
    while (curShift > 0) {
        curShift -= 4;
        const uint8_t nibble = (uint8_t)((valAbs >> curShift) & 0x0Fu);
        PrintUtils::printHexDigit(nibble, out);
    }
}

void PrintUtils::printHexU8(const uint8_t val, const bool bZeroPad, std::ostream& out) {
    printHexInt(val, bZeroPad, out);
}

void PrintUtils::printHexI8(const int8_t val, const bool bZeroPad, std::ostream& out) {
    printHexInt(val, bZeroPad, out);
}

void PrintUtils::printHexU16(const uint16_t val, const bool bZeroPad, std::ostream& out) {
    printHexInt(val, bZeroPad, out);
}

void PrintUtils::printHexI16(const int16_t val, const bool bZeroPad, std::ostream& out) {
    printHexInt(val, bZeroPad, out);
}

void PrintUtils::printHexU32(const uint32_t val, const bool bZeroPad, std::ostream& out) {
    printHexInt(val, bZeroPad, out);
}

void PrintUtils::printHexI32(const int32_t val, const bool bZeroPad, std::ostream& out) {
    printHexInt(val, bZeroPad, out);
}

void PrintUtils::printBool(const bool bVal, std::ostream& out) {
    out << (bVal ? "true" : "false");   // N.B - parens are important for correct op order!
}

void PrintUtils::printEscapedChar(const char val, std::ostream& out) {
    const uint8_t valU8 = (uint8_t) val;

    if (valU8 >= 32 && valU8 <= 126) {
        if (val != '\\') {
            out.put(val);
        } else {
            out << "\\\\";
        }
    } else if (val == '\r') {
        out << "\\r";
    } else if (val == '\n') {
        out << "\\n";
    } else if (val == '\t') {
        out << "\\t";
    } else if (val == '\0') {
        out << "\\0";
    } else if (val == '\'') {
        out << "\\\'";
    } else if (val == '\"') {
        out << "\\\"";
    } else if (val == '\v') {
        out << "\\v";
    } else if (val == '\f') {
        out << "\\f";
    } else {
        out << "\\x";
        printHexU8(valU8, true, out);
    }
}
