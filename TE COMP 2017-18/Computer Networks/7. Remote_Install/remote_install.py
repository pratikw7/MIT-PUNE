#! /usr/bin/env python
import os

os.system('scp cmatrix_1.2a-5_amd64.deb ashwin@127.0.0.1:install.deb')
os.system('ssh -t ashwin@127.0.0.1 sudo dpkg -i install.deb')