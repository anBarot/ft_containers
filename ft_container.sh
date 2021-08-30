#!/bin/bash

echo "Enter test name : "
read CONTAIN

if [ $CONTAIN == "vector" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_vector.cpp
./a.out > vector_result.txt
cat vector_result.txt
elif [ $CONTAIN == "map" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_map.cpp
./a.out > map_result.txt
cat map_result.txt
elif [ $CONTAIN == "stack" ]; then
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/test_stack.cpp
./a.out > stack_result.txt
cat stack_result.txt
elif [ $CONTAIN == "speed_map" ]; then
sed -e '/test_vector_speed();/s/^/\/\//g' test_ft_containers/test_speed_std.cpp > test_ft_containers/tmp.cpp
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/tmp.cpp
echo -ne "test std :\n" > speed_result.txt
time ./a.out >> speed_result.txt
sed -e '/test_vector_speed();/s/^/\/\//g' test_ft_containers/test_speed_ft.cpp > test_ft_containers/tmp.cpp
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/tmp.cpp
echo -ne "test ft :\n" >> speed_result.txt
time ./a.out >> speed_result.txt
rm test_ft_containers/tmp.cpp
elif [ $CONTAIN == "speed_vector" ]; then
sed -e '/test_map_speed();/s/^/\/\//g' test_ft_containers/test_speed_std.cpp > test_ft_containers/tmp.cpp
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/tmp.cpp
echo -ne "test std :\n" > speed_result.txt
time ./a.out >> speed_result.txt
sed -e '/test_map_speed();/s/^/\/\//g' test_ft_containers/test_speed_ft.cpp > test_ft_containers/tmp.cpp
clang++ -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g test_ft_containers/tmp.cpp
echo -ne "test ft :\n" >> speed_result.txt
time ./a.out >> speed_result.txt
rm test_ft_containers/tmp.cpp
else
echo "Not good input"
fi

rm a.out
