#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/cheetahcoin.png
ICON_DST=../../src/qt/res/icons/cheetahcoin.ico
convert ${ICON_SRC} -resize 16x16 cheetahcoin-16.png
convert ${ICON_SRC} -resize 32x32 cheetahcoin-32.png
convert ${ICON_SRC} -resize 48x48 cheetahcoin-48.png
convert cheetahcoin-16.png cheetahcoin-32.png cheetahcoin-48.png ${ICON_DST}

