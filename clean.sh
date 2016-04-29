TEST=*.o
if ls | grep $TEST; then
	rm $TEST
fi
