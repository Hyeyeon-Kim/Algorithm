def idx_x(n, w, h):
    if h % 2 == 1:
        return (w - (n % w)) - 1
    return n % w 

def solution(n, w, num):
    
    n_h = (n - 1) // w
    n_w = idx_x(n-1, w, n_h)
    num_h = (num - 1) // w
    num_w = idx_x(num-1, w, num_h)
    
    # print(n_h, num_h, n_w, num_w)
    if n_h % 2 == 1 and n_w <= num_w:
        return n_h - num_h + 1
    elif n_h % 2 == 0 and n_w >= num_w:
        return n_h - num_h + 1
    else:
        return n_h - num_h