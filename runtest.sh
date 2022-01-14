comp get_next_line.c test2.c -L libft/ -lft
for f in test_files/*.txt
do
./a.out $f
done
for f in test_files/*.txt
do
diff "$f" "${f}.test"
done
rm test_files/*.test