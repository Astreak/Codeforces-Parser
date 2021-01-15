from flask import *
from flask_restful import *
import os
import sys
import argparse
from bs4 import BeautifulSoup as bs
import requests
import re

os.system('clear')
class CfParser(object):
    def __init__(self,url):
        self.url=url
        self.data=''
        self.proburl='https://www.codeforces.com/contest/'
    def get(self):
        self.L=self.url.split('/')
        self.contest_no=self.L[-1];
        self.proburl=os.path.join(self.proburl,self.contest_no)
        self.proburl=os.path.join(self.proburl,"problem")

        #print(self.contest_no)
        #print(self.L)
    def passprob(self,passer='A'):
        self.proburl=os.path.join(self.proburl,passer)
        print(self.proburl)
        
        self.data=requests.get(self.proburl)
        soup=bs(self.data.content,'html.parser')
        temp=soup.find("div",class_="ttypography")
        F=temp.find("div",class_="problem-statement")
        TESTS=F.find("div",class_="sample-tests")
        yolk=F.find("div",class_="sample-test")
        ok=0
        kk=0
        try:
            os.mkdir('Directory')
        except:
            pass
        for i in yolk:
            #print(i.get("class"))
    
            if i.get('class')[0]=='input':
                try:
                    os.mkdir(f"Directory/Testcase{ok}")
                except:
                    pass
                temp=i.pre.get_text()
                os.system(f"touch Directory/Testcase{ok}/input.in")
                os.system(f"touch Directory/Testcase{ok}/output.in")
                with open(f"Directory/Testcase{ok}/input.in","w") as inp:
                    temp=re.sub(r"^\s+", "", temp)
                    inp.write(temp)
                    
            else:
                temp=i.pre.get_text()
                with open(f"Directory/Testcase{ok}/output.in","w") as h:
                    temp=re.sub(r"^\s+", "", temp)
                    h.write(temp)
                    ok+=1










if __name__=="__main__":
    parser=argparse.ArgumentParser()
    parser.add_argument("-a",dest='prob')
    parser.add_argument('-u',dest='url')
    parse=parser.parse_args()
    cf=CfParser(parse.url)
    cf.get()
    cf.passprob(parse.prob)

    
    

