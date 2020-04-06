#!/bin/bash

gcc -g3 -fsanitize=address -Wall -Werror -Wextra srcs/gnl_tester.c ../get_next_line.c ../get_next_line_utils.c -I ../ -D BUFFER_SIZE=3 && ./a.out