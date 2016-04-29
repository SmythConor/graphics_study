. clean.sh
if [ -z $1 ]; then
	echo -e "Usage ./make.sh fileName"
	exit;
fi
gcc $1.c -o $1.o -lGL -lGLU -lglut -lm
