cmake_minimum_required(VERSION 3.12)
project(op_bead C)

set(CMAKE_C_STANDARD 99)

add_executable(op_bead main.c create/create.c model/order.h create/create.h print/print.h print/print.c read/read.h read/read.c update/update.c update/update.h model/boolean.h file/file.h file/file.c select/select.c select/select.h delete/delete.c delete/delete.h filter/filter.c filter/filter.h)