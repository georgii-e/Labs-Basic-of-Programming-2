#pragma once
#include "tetr.h"
tetrahedron* gen_arr(int);
void remove(tetrahedron* p_arr);
void output(tetrahedron* p_arr, int length);
float max(tetrahedron* p_arr, int length, int* id); //пошук тетраедра с максимальним об'ємом

