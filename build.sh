#!/bin/bash

# clone qmk, copy folders, compile .uf2

capa_qmk="./qmk/capa"
qmk_folder="./qmk_firmware"

echo "Looking for QMK..."

qmk_which=`which qmk`

if [ $? != 0 ]
then
	echo "QMK is not installed or could not be found. Please make sure you installed the QMK CLI. If you're unsure, look at https://docs.qmk.fm/#/newbs_getting_started"
	exit 1
else
	echo "Found QMK at ${qmk_which}!"
fi

if [ -d $qmk_folder ]
then
	echo "QMK Folder exists, skipping clone... (run rm -rf ${qmk_folder} to remove)"
else
	echo "Cloning QMK here..."

	qmk clone

	if [ $? != 0 ]
	then
		echo "An error occured while cloning QMK. Please check for errors in the logs above ^^^^^"
	fi
fi

echo "Copying ${capa_qmk} to ${qmk_folder}/keyboards/..."

cp -r $capa_qmk/ $qmk_folder/keyboards/

echo "Entering QMK folder..."

cd $qmk_folder

echo "Compiling firmware for ${qmk_folder}/keyboards/capa..."

qmk compile -kb capa -km default

if [ $? != 0  ]
then
	echo "An error occured while compiling QMK. Please check for errors in the logs above ^^^^^"
else
	echo "QMK Compiled successfully! Listing .uf2 files..."
	firmwares=`ls | grep .uf2`
	ls | grep .uf2
	echo "One of these files should be the capa firmware!"
	cp $firmwares ../
fi
