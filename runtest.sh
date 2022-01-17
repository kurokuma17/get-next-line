#!/bin/bash
#sudo chown SlushGuest test_files/4-3-forbidden.txt
make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c #-D BUFF_SIZE=8 #[modify buffsize if needed here]
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft 

echo -e "\033[1;90m=================================\033[0m"
echo -e "\033[1;36mauthor file:\033[0m"
echo -e "\033[1;90m=================================\033[0m"
cat -e author
diff <(cat get_next_line.c | grep 'Created:' | cut -f 8 -d " ") <(cat author) \
&& echo -e "\033[1;32mOK\033[0m" || echo -e "\033[1;31mwrong login\033[0m"

echo -e "\033[1;36mNorm check:\033[0m"
echo -e "\033[1;90m=================================\033[0m"
norminette get_next_line.c get_next_line.h \
&& echo -e "Norm check: \033[1;32mOK\033[0m" || echo -e "Norm check: \033[1;31mFAIL\033[0m"

for f in test_files/*.txt
do
	./test_gnl $f > /dev/null
done
echo -e "\033[1;90m=================================\033[0m"
echo -e "\033[1;36mBasic tests:\033[0m"
echo -e "\033[1;90m=================================\033[0m"
for f in test_files/*.txt
do
	echo "Test: ${f#test_files/}" 
	#echo "Test: ${f%.txt}"
	diff -b "$f" "${f}.test" \
	&& echo -e "\033[1;32mOK\033[0m" || echo -e "\033[1;31mFAIL\033[0m"
	#diff -b <(sed -e '$a\' $f) <(sed -e '$a\' ${f}.test) \
done

echo -e "\033[1;90m=================================\033[0m"
echo -e "\033[1;36mLeak check:\033[0m"
echo -e "\033[1;90m=================================\033[0m"
for f in test_files/*.txt
do
	leaks --atExit -- ./test_gnl $f | egrep 'leaked'
done

echo -e "\033[0;35mBasic tests done\033[0m"
echo ""

echo -e "\033[1;90m=================================\033[0m"
echo -e "\033[1;36mMultiple fds tests:\033[0m"
echo -e "\033[1;90m=================================\033[0m"
clang -Wall -Wextra -Werror -I libft/includes -o main-multi-fds.o -c main-multi-fds.c
clang -o test_gnl_multi main-multi-fds.o get_next_line.o -I libft/includes -L libft/ -lft
head -n 5 test_files/5*.txt
./test_gnl_multi test_files/5*.txt
echo -e "\033[0;35mMulti fds test done\033[0m"
echo ""

echo -e "\033[1;90m=================================\033[0m"
echo -e "\033[1;36mSpeed test:\033[0m"
echo -e "\033[1;90m=================================\033[0m"
time ./test_gnl test_files/the-king-james-bible.txt
time ./test_gnl test_files/4.longstr.txt

echo ""
echo -e "\033[0;35mAll test done\033[0m"
echo ""

###cleanup###
make -C libft/ fclean
rm *.o
rm test_files/*.test 
rm test_gnl*
