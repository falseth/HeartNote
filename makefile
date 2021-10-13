heart_note: Main.c Utils.c Utils.h
	gcc Main.c Utils.c -o HeartNote.exe

run:
	.\HeartNote.exe

clean:
	rm HeartNote.exe