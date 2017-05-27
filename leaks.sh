PROCESSID=$(ps | grep "./fdf" | grep -v "grep" | sed 's/^[ ]*//g' | cut -d" " -f1)
leaks $PROCESSID
