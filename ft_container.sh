#!/bin/bash

echo "Enter test name : "
read CONTAIN

if [ $CONTAIN == "vector" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_vector.cpp -I.
./a.out > vector_result.txt
cat vector_result.txt
# elif [ $CONTAIN == "map" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_containers/test_map.cpp ../map.hpp
# elif [ $CONTAIN == "queue" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_containers/test_queue.cpp ../queue.hpp
# elif [ $CONTAIN == "list" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_containers/test_list.cpp ../list.hpp
# elif [ $CONTAIN == "stack" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_containers/test_stack.cpp ../stack.hpp
else
echo "Not good input"
fi

rm a.out