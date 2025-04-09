#!/bin/bash

zip -r Resource.zip Resources
./Dropbox-Uploader/dropbox_uploader.sh upload Resource.zip /Resource.zip

