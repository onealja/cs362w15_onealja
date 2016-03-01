CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

runAdventurer: adventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomcard:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

runRandomCard: randomcard
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomcard.out


playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

playdom2: dominion.o playdom2.c
	gcc -o playdom2 playdom2.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test1.c rngs.c -o unit_test1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test2.c rngs.c -o unit_test2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test3.c rngs.c -o unit_test3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test4.c rngs.c -o unit_test4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test1.c rngs.c -o card_test1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test2.c rngs.c -o card_test2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test3.c rngs.c -o card_test3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test4.c rngs.c -o card_test4 -lm -g


myTest:
	./unit_test1 &> unittestresult.out
	./unit_test2 >> unittestresult.out
	./unit_test3 >> unittestresult.out
	./unit_test4 >> unittestresult.out
	./card_test1 >> unittestresult.out
	./card_test2 >> unittestresult.out
	./card_test3 >> unittestresult.out
	./card_test4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

testDom:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testdominion.c rngs.c -o testdominion -lm -g
	
	./testdominion &> testdominion.out

testOtherDom:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testdominion.c rngs.c -o testdominion -lm -g
	./testdominion &> testotherdominion.out
	diff testdominion.out testotherdominion.out > diffout.txt



player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
