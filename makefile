all: feigen

feigen: feigen.c
	g++ feigen.c -o feigen

clean:
	rm feigen output.txt

debug:
	g++ -g feigen.c -o feigen
