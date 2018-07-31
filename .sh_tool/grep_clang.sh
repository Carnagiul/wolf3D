output=$(ps auxww | grep "clang" | grep -v grep | grep -v $0)
lines=`echo "$output" | wc -l`
while [ "$line" == "1" ]
do
output=$(ps auxww | grep "clang" | grep -v grep | grep -v $0)
lines=`echo "$output" | wc -l`
done
