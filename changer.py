import os
import sys
import argparse
import filecmp
parser=argparse.ArgumentParser()
parser.add_argument("--a",dest="f1")
parser.add_argument("--b",dest="f2")
parse=parser.parse_args()
A=parse.f1
B=parse.f2
f=filecmp.cmp(A,B)
if f:
    print("\033[1;32;40m Passed Bitch \n")
else:
    print("\033[1;31;40m Failed dumbarse nigga \n")




