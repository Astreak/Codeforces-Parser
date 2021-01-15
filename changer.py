import os
import sys
import argparse
import filecmp
import subprocess
f=True
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
    print("\033[1;31;40m How are dumb you are arsehole run the main first bitch \n")
    sys.exit(1)

if f:
    print("\033[1;32;40m Passed All cases good job \n")
    subprocess.call('bash final.sh',shell=True)

else:
    print("\033[1;31;40m Check the code again bitch\n")





