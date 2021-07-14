#!/bin/bash

echo "Enter test name : "
read CONTAIN

if [ $CONTAIN == "main" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/project_main.cpp map/*.hpp tools/*.hpp vector/*.hpp stack/*.hpp
./a.out > main_result.txt
cat main_result.txt
elif [ $CONTAIN == "vector" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_vector.cpp -I./vector
./a.out > vector_result.txt
cat vector_result.txt
# elif [ $CONTAIN == "map" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_containers/test_map.cpp ../map.hpp
elif [ $CONTAIN == "stack" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_stack.cpp -I.
./a.out > stack_result.txt
cat stack_result.txt
else
echo "Not good input"
fi

rm a.out