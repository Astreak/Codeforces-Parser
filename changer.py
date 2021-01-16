import os
import sys
import argparse
import filecmp
import subprocess
f=True
try:
    os.system('bash com.sh')
except:
    raise Exception('File compile Erro')
if 'Directory' in os.listdir():
    for i in os.listdir('Directory'):
        path=os.path.join('Directory',i)
        temp1=os.path.join(path,'input.in')

        subprocess.call(f"touch {os.path.join(path,'demo.in')}",shell=True)
        subprocess.call(f"bash exec.sh {os.path.join(path,'input.in')} {path}",shell=True)
        real=os.path.join(path,'output.in')
        out=os.path.join(path,'demo.in')
        if filecmp.cmp(real,out):
            print(f"\033[1;32;40m {i} Passed\n")
        else:
            print(f"\033[1;31;40m {i} Failed\n")
            f=False
else:
    print("\033[1;31;40m You have to run main first \n")
    sys.exit(1)

if f:
    print("\033[1;32;40m Passed All  Test Cases \n")
    subprocess.call('bash final.sh',shell=True)

else:
    print("\033[1;31;40m Wrong answer do not submit \n")





