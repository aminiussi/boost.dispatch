#!/bin/sh
set -e

# Get Boost 1.58
wget http://sourceforge.net/projects/boost/files/boost/1.58.0/boost_1_58_0.tar.bz2/download -O /tmp/boost.tar.bz2
tar jxf /tmp/boost.tar.bz2
mv boost_1_58_0/ $HOME/boost-trunk/
cd $HOME/boost-trunk && ./bootstrap.sh
