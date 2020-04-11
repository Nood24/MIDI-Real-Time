all:
	rm -f  OneManCeilidh
	rm -f -r CSVFiles
	cd ../midi_driver/driver && cp -r CSVFiles temp
	cd ../midi_driver/driver && mv temp ../../build_and_run/CSVFiles
	cd ../frontEnd && qmake
	cd ../frontEnd && make clean
	cd ../frontEnd && make
	cd ../frontEnd && cp OMC_FrontEnd OneManCeiidh
	cd ../frontEnd && mv OneManCeiidh ../build_and_run/OneManCeilidh
	cd ../frontEnd && make clean
