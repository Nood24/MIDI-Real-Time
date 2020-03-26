all:
	rm -f  OneManCeilidh
	cd ../frontEnd && make clean
	cd ../frontEnd && qmake
	cd ../frontEnd && make
	cd ../frontEnd && cp OMC_FrontEnd OneManCeiidh
	cd ../frontEnd && mv OneManCeiidh ../buid_and_run/OneManCeilidh
