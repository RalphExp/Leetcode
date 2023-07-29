# Read from the file file.txt and print its transposed content to stdout.

# fetch the first line and see how many words in it,
# this is the column number when the file is transposed.
columns=$(cat file.txt | head -n 1 | wc -w)

# for every column
for i in $(seq 1 $columns)
do
    # use echo to translate a column to a row
    echo $(awk '{print $'$i'}' file.txt)

    # we can use xargs, too
    # e.g. awk '{print $'''$i'''}' file.txt | xargs

done
