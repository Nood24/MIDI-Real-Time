all:
	rm -f  OneManCeilidh
	rm -f -r CSVFiles
	cd ../midi_driver/driver && cp -r CSVFiles temp
	cd ../midi_driver/driver && mv temp ../../buid_and_run/CSVFiles
	cd ../frontEnd && make clean
	cd ../frontEnd && qmake
	cd ../frontEnd && make
	cd ../frontEnd && cp OMC_FrontEnd OneManCeiidh
	cd ../frontEnd && mv OneManCeiidh ../buid_and_run/OneManCeilidh
	cd ../frontEnd && make clean
