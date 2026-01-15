def f(typ):
    if typ == "code":
        return 0
    elif typ == "date":
        return 1
    elif typ == "maximum":
        return 2
    else:
        return 3


def solution(data, ext, val_ext, sort_by):
    
    code = f(ext)
    answer = [da for da in data if da[code] < val_ext]
    
    code = f(sort_by)
    return sorted(answer, key=lambda k: k[code])