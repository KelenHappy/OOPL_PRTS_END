#!/bin/bash

./Dropbox-Uploader/dropbox_uploader.sh download /Resource.zip ../Resource.zip
cd ..
unzip Resource.zip
rm Resource.zip
