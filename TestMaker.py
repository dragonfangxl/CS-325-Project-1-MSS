#!/usr/bin/python
import random as rand
import sys
import getopt
import os

def main(argv):
    file = open(str(sys.argv[2]), 'w')
    for i in range (10):
        for j in range (int(sys.argv[1])):
            file.write(str(rand.randint(-99, 99)))
            if (j+1 != int(sys.argv[1])):
                file.write(" ")
        if (i+1 != 10):
            file.write("\n")
    file.close()
if __name__ == "__main__":
    main(sys.argv[1:])