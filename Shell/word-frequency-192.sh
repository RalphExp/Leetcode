# Read from the file words.txt and output the word frequency list to stdout.
declare -A hash

while read line
do
    for word in $line; do
        hash[$word]=$((hash[$word]+1))
    done
done < words.txt

for key in ${!hash[*]}; do
    echo $key ${hash[$key]}
done | sort -n -r -k2
