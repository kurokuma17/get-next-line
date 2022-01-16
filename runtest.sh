#!/bin/bash
#sudo chown SlushGuest test_files/4-3-forbidden.txt
make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c -D BUFF_SIZE=1 #[modify buffsize if needed here]
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft 

echo ""
echo -e "\033[1;36mauthor file:\033[0m"
cat -e author
echo ""

echo -e "\033[1;36mNorm check:\033[0m"
norminette get_next_line.c
norminette get_next_line.h
echo ""

for f in test_files/*.txt
do
	./test_gnl $f
done

echo ""
echo -e "\033[1;36mBasic tests:\033[0m"
echo ""
for f in test_files/*.txt
do
	echo "diff $f  ${f}.test"
	diff -b "$f" "${f}.test" \
	&& echo -e "\033[1;32m\tOK\033[0m" || echo -e "\033[1;31m\tFAIL\033[0m"
	#diff -b <(sed -e '$a\' $f) <(sed -e '$a\' ${f}.test) \
done

echo ""
echo -e "\033[1;36mLeak check:\033[0m"
for f in test_files/*.txt
do
	leaks --atExit -- ./test_gnl $f | egrep 'leaked'
done

echo ""
echo -e "\033[0;35mBasic tests done\033[0m"
#rm test_files/*.test


echo ""
echo -e "\033[1;36mMultiple fds tests:\033[0m"
echo ""
clang -Wall -Wextra -Werror -I libft/includes -o main-multi-fds.o -c main-multi-fds.c
clang -o test_gnl_multi main-multi-fds.o get_next_line.o -I libft/includes -L libft/ -lft
tail -n +1 test_files/5-swcraw-iv.txt test_files/5-swcrawl-v.txt test_files/5-swcrawl-vi.txt
./test_gnl_multi test_files/5-swcraw-iv.txt test_files/5-swcrawl-v.txt test_files/5-swcrawl-vi.txt
echo -e "\033[0;35mMulti fds test done\033[0m"