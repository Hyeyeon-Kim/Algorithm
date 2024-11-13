def check(u):
    stack = []
    
    for c in u:
        if c == '(':
            stack.append(c)    
        else :
            if stack == []:
                return False
            stack.pop()
    
    if stack != []:
        return False
    else:
        return True

def makeRight(p):
    if not p:
        return ""

    left = right = 0
    for i in range(len(p)):
        if p[i] == '(':
            left+=1
        else:
            right+=1
        
        if left == right:
            u = p[:i+1]
            v = p[i+1:]
            
            if (check(u)):
                return u + makeRight(v)
            else:
                new_str = '(' + makeRight(v) + ')'
                u = ''.join(')' if c == '(' else '(' for c in u[1:-1])
                return new_str + u


def solution(p):
    if check(p):
        return p
    return makeRight(p)