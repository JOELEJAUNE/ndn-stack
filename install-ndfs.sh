#!/bin/bash

    update='sudo apt-get update'
    install='sudo apt-get -y install'
    remove='sudo apt-get -y remove'
	
	#add repostories
	
	#sudo add-apt-repository ppa:boost-latest/ppa
	$update
	#Install dependencies
	
	$install python-software-properties
	$install build-essential libsqlite3-dev libcrypto++-dev libboost-all-dev
	$install git
	$install openmpi-bin openmpi-common openmpi-doc libopenmpi-dev
	
	
	
	$install python-dev python-pygraphviz python-kiwi
	$install python-pygoocanvas python-gnome2
	$install python-rsvg ipython
	
	#
	
	mkdir ndnSIM
	
	cd ndnSIM/
	git clone https://github.com/named-data-ndnSIM/ns-3-dev.git ns-3
	git clone https://github.com/named-data-ndnSIM/pybindgen.git pybindgen
	
	#install the correct version of ndnSim which works with NDNFS
	git clone -b 'ndnSIM-2.2' --recursive --single-branch --depth 1 https://github.com/named-data-ndnSIM/ndnSIM.git ns-3/src/ndnSIM 
	
	#clone NDNFS
	cd
	git clone https://github.com/charifmahmoudi/ndn-stack.git
	cd ndn-stack/
	cp bigdata/ndnSIM/ns-3/src/ndnSIM/apps/bigdata-* ../ndnSIM/ns-3/src/ndnSIM/apps/
	cp bigdata/ndnSIM/ns-3/scratch/data-scenario.cc ../ndnSIM/ns-3/scratch/
	cd ../ndnSIM/ns-3/
	./waf configure --enable-examples -d optimized 
	#--enable-mpi
	./waf
