all:
	(cd timerLib; make install)
	(cd project; make load)

clean:
	(cd timerLib; make clean)
	(cd project; make clean)
	rm -rf lib h *~ *#
