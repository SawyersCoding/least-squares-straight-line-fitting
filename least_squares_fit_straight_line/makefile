
OBJS = obj/leastsquaresstraightline.o obj/csvwriter.o

main: leastsquaresstraightline.o csvwriter.o
	g++ -g -o leastsquaresstraightline $(OBJS) main.cpp

csvwriter.o: leastsquaresstraightline.o
	g++ -c -o obj/csvwriter.o csvwriter.cpp

leastsquaresstraightline.o: obj
	g++ -c -lm -o obj/leastsquaresstraightline.o leastsquaresstraightline.cpp

obj:
	mkdir obj