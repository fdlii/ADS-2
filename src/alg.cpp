// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) return 1;
    uint16_t num = 1;
    double res = value;
    if (n > 0) {
        while (num != n) {
            res *= value;
            num++;
        }
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint16_t num = 1;
    uint64_t res = 1;
    if (n == 0) return 1;
    if (n > 0) {
        while (num != n) {
            num += 1;
            res *= num;
        }
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double res = 1;
    if (count == 0) return 0;
    uint16_t i = 1;
    while (count != i) {
        res += calcItem(x, i);
        i++;
    }
    res += calcItem(x, i);
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0;
    if (count == 0) return 0;
    uint16_t i = 1;
    while (count != i) {
        res = res + calcItem(x, 2 * i - 1) * pown(-1, i - 1);
        i++;
    }
    res = res + calcItem(x, 2 * i - 1) * pown(-1, i - 1);
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 0;
    if (count == 0) return 0;
    if (count == 1) return x;
    uint16_t i = 1;
    while (count != i) {
        res = res + calcItem(x, 2 * i - 2) * pown(-1, i - 1);
        i++;
    }
    res = res + calcItem(x, 2 * i - 2) * pown(-1, i - 1);
    return res;
}
