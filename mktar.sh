#!/bin/bash

tar cv HorizonM.cia HorizonScreen/out HorizonScreen/*.dll HorizonScreen/HzScreen.bat README.md HorizonScreen/README.md HzLoad/HzLoad.cia HzLoad/HzLoad_HIMEM.cia HzLoad/README.md \
| lzma -zev >Hz.tar.lzma
