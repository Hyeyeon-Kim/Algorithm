import sys, math
import re
from fractions import Fraction

def solution(new_id):
    new_id = new_id.lower()
    s = '~!@#$%^&*()=+[{]}:?,<>/'
    for i in s:
        new_id = new_id.replace(i,'')
    
    ids = new_id.split('.')
    nids = []
    for i in ids:
        if i != '':
            nids.append(i)
            
    new_id = '.'.join(nids)
    
    if new_id != '' and new_id[0] == '.':
        new_id = new_id[1:]

    if new_id != '' and new_id[len(new_id)-1] == '.':
        new_id = new_id[0:len(new_id)-2]
    
    if new_id == '':
        new_id = 'a'

    if len(new_id) >= 16:
        new_id = new_id[:15]
    
    if new_id != '' and new_id[len(new_id)-1] == '.':
        new_id = new_id[0:len(new_id)-1]
    
    while len(new_id) < 3:
        c = new_id[::-1]
        new_id += c[:1]
    
    return new_id