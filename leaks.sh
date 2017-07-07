PROCESSID=$(ps | grep "./wolf3d" | grep -v "grep" | sed 's/^[ ]*//g' | cut -d" " -f1)
leaks $PROCESSID
