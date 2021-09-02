#!/bin/bash

echo "Enter test name : "
read CONTAIN

if [ $CONTAIN == "vector" ]; then
clang++ -Wall -Wextra -Werror -stdlib=libstdc++ -pedantic-errors -g test_ft_containers/test_vector.cpp
./a.out > vector_result.txt
cat vector_result.txt
elif [ $CONTAIN == "map" ]; then
clang++ -Wall -Wextra -Werror -stdlib=libstdc++ -pedantic-errors -g test_ft_containers/test_map.cpp
./a.out > map_result.txt
cat map_result.txt
elif [ $CONTAIN == "stack" ]; then
clang++ -Wall -Wextra -Werror -stdlib=libstdc++ -pedantic-errors -g test_ft_containers/test_stack.cpp
./a.out > stack_result.txt
cat stack_result.txt
else
echo "Not good input"
fi

rm a.out
