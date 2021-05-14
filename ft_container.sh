#!/bin/bash

read CONTAIN

if [ CONTAIN == "vector" ]; then
clang++ -Wall -Wextra -Werror -g test_ft_container/test_vector.cpp ../vector.hpp
# elif [ CONTAIN == "map" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_container/test_map.cpp ../map.hpp
# elif [ CONTAIN == "queue" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_container/test_queue.cpp ../queue.hpp
# elif [ CONTAIN == "list" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_container/test_list.cpp ../list.hpp
# elif [ CONTAIN == "stack" ]; then
# clang++ -Wall -Wextra -Werror -g test_ft_container/test_stack.cpp ../stack.hpp
fi