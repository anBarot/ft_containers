#!/bin/bash

echo "Enter test name : "
read CONTAIN

if [ $CONTAIN == "main" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/project_main.cpp
./a.out 2 
elif [ $CONTAIN == "vector" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_vector.cpp
./a.out > vector_result.txt
cat vector_result.txt
elif [ $CONTAIN == "map" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_map.cpp
./a.out
cat map_result.txt
elif [ $CONTAIN == "map_2" ]; then
clang++ -Wall -Wextra -Werror -pedantic-errors -g test_ft_containers/test_bor/*.cpp
./a.out
cat map_result.txt
elif [ $CONTAIN == "stack" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_stack.cpp
./a.out > stack_result.txt
cat stack_result.txt
else
echo "Not good input"
fi

rm a.out
