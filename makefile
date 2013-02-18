all: feigen

feigen: f.c
	g++ f.c -o feigen

clean:
	rm feigen output.txt

debug:
	g++ -g f.c -o feigen
